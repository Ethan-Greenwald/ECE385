/************************************************************************
Avalon-MM Interface VGA Text mode display

Register Map:
0x000-0x0257 : VRAM, 80x30 (2400 byte, 600 word) raster order (first column then row)
0x258        : control register

VRAM Format:
X->
[ 31  30-24][ 23  22-16][ 15  14-8 ][ 7    6-0 ]
[IV3][CODE3][IV2][CODE2][IV1][CODE1][IV0][CODE0]

IVn = Draw inverse glyph
CODEn = Glyph code from IBM codepage 437

Control Register Format:
[[31-25][24-21][20-17][16-13][ 12-9][ 8-5 ][ 4-1 ][   0    ] 
[[RSVD ][FGD_R][FGD_G][FGD_B][BKG_R][BKG_G][BKG_B][RESERVED]

VSYNC signal = bit which flips on every Vsync (time for new frame), used to synchronize software
BKG_R/G/B = Background color, flipped with foreground when IVn bit is set
FGD_R/G/B = Foreground color, flipped with background when Inv bit is set

************************************************************************/
`define NUM_REGS 601 //80*30 characters / 4 characters per register
`define CTRL_REG 600 //index of control register

module vga_text_avl_interface (
	// Avalon Clock Input, note this clock is also used for VGA, so this must be 50Mhz
	// We can put a clock divider here in the future to make this IP more generalizable
	input logic CLK,
	
	// Avalon Reset Input
	input logic RESET,
	
	// Avalon-MM Slave Signals
	input  logic AVL_READ,					// Avalon-MM Read
	input  logic AVL_WRITE,					// Avalon-MM Write
	input  logic AVL_CS,					// Avalon-MM Chip Select
	input  logic [3:0] AVL_BYTE_EN,			// Avalon-MM Byte Enable
	input  logic [9:0] AVL_ADDR,			// Avalon-MM Address
	input  logic [31:0] AVL_WRITEDATA,		// Avalon-MM Write Data
	output logic [31:0] AVL_READDATA,		// Avalon-MM Read Data
	
	// Exported Conduit (mapped to VGA port - make sure you export in Platform Designer)
	output logic [3:0]  red, green, blue,	// VGA color channels (mapped to output pins in top-level)
	output logic hs, vs						// VGA HS/VS
);

//logic [31:0] LOCAL_REG       [`NUM_REGS]; // Registers
//put other local variables here
//port A is for AVL bus; port B is for local VGA read
logic [9:0] VGA_ADDR;
logic [31:0] VGA_WRITEDATA, VGA_READDATA;
logic VGA_READ, VGA_WRITE;
logic [31:0] rgb;
ram vram(.address_a(AVL_ADDR), .address_b(VGA_ADDR), .byteena_a(AVL_BYTE_EN), .clock(CLK), .data_a(AVL_WRITEDATA), .data_b(VGA_WRITEDATA), 
			.rden_a(AVL_READ), .rden_b(VGA_READ), .wren_a(AVL_WRITE), .wren_b(VGA_WRITE), .q_a(AVL_READDATA), .q_b(VGA_READDATA));
shadow ctrl_reg(.CLK, .write_flag(AVL_WRITE), .address(AVL_ADDR), .data(AVL_WRITEDATA), .rgb);

//Declare submodules..e.g. VGA controller, ROMS, etc
logic pixel_clk, blank, sync;
logic [9:0] DrawX, DrawY;
vga_controller da_vga_controller( .Clk(CLK), .Reset(RESET), .hs(hs), .vs(vs), .pixel_clk(pixel_clk), .blank(blank), .sync(sync), .DrawX(DrawX), .DrawY(DrawY));

logic [10:0] FONT_ADDR;
logic [7:0] FONT_DATA;
logic value;
font_rom da_font_rom( .addr(FONT_ADDR), .data(FONT_DATA));

//########## Handled by VRAM module #################
//// Read and write from AVL interface to register block, note that READ waitstate = 1, so this should be in always_ff
//always_ff @(posedge CLK) begin
//	
//end


//handle drawing (may either be combinational or sequential - or both).
logic [2:0] CharX;
logic [3:0] CharY;
logic [6:0] GridX;
logic [4:0] GridY;
logic [6:0] character;
logic invert;

assign CharX = DrawX[2:0];
assign CharY = DrawY[3:0];	//get specific pixel within glyph

assign GridX = DrawX >> 3;
assign GridY = DrawY >> 4;	//corresponds to location in character 80x30 grid
assign VGA_ADDR = (GridY * 8'h14) + GridX/4;

always_comb begin
	//extract invert flag and character keycode from read word (VGA_READDATA)
	unique case (GridX % 4)
		'h0: 	begin invert = VGA_READDATA[7];
				character = VGA_READDATA[6:0];
				end
				
		'h1: 	begin invert = VGA_READDATA[15];
				character = VGA_READDATA[14:8];
				end
				
		'h2: 	begin invert = VGA_READDATA[23];
				character = VGA_READDATA[22:16];
				end
				
		'h3: 	begin invert = VGA_READDATA[31];
				character = VGA_READDATA[30:24];
				end
	endcase
end

always_ff @(posedge CLK)
begin
	FONT_ADDR <= (character << 4) + CharY;
	value <= FONT_DATA[~CharX]^invert;
	
	unique case(value)
	//Background
	'h0: begin red <=  rgb[12:9];
		  green <= rgb[8:5];
		  blue <= rgb[4:1];
		  end
		  
	//Foreground
   'h1: begin red <= rgb[24:21];
		  green <= rgb[20:17];
		  blue <= rgb[16:13];
		  end
	endcase
end

assign VGA_WRITE = 0;
assign VGA_READ = 1;

//use GridX and GridY to get current character at our location from VRAM
//then, use character to index font_rom along with CharX and CharY to get specific pixel value
//use control register color + invertion bit to determine color to draw
//set RGB value and done!

endmodule

module shadow(input logic CLK,
				  input logic write_flag,
				  input logic [9:0] address,
				  input logic [31:0] data,
				  output logic [31:0] rgb);
				  
				  always_ff @(posedge CLK)
				  begin
					if(write_flag && address == 10'h258)
						rgb <= data; 
					end
endmodule
						
					
	
module datapath( 	input logic  LD_MAR, LD_MDR, LD_IR, LD_BEN, LD_CC, LD_REG, LD_PC, LD_LED,
						input logic  GatePC, GateMDR, GateALU, GateMARMUX,
						input logic  SR2MUX, ADDR1MUX,
						input logic  MIO_EN, DRMUX, SR1MUX,
						input logic  [1:0] PCMUX, ADDR2MUX, ALUK,
						input logic  [15:0] MDR_In,
						input logic  Clk, Reset,
						output logic BEN,
						output logic [15:0] MAR, MDR, IR
);

	logic [15:0] PC_in, PC_out, MDR_in, ALU_out, MARMUX_out;
	logic [15:0] bus;
	logic [15:0] SR1_out, SR2_out;
	logic [2:0] SR1, SR2, DR;
	
	// Logic for assigning bus output based on Gate inputs (simulate Tristate Buffers)
	logic [3:0] bus_gate;
	assign bus_gate = {GatePC, GateMDR, GateALU, GateMARMUX};
	always_comb begin
		case(bus_gate)
			4'b1000: bus = PC_out;
			4'b0100: bus = MDR;
			4'b0010: bus = ALU_out;
			4'b0001: bus = MARMUX_out;
			default: bus = 16'hXXXX;
		endcase
	end
	////////////////
	
	
	// Initialize PC, IR, MAR, MDR registers
	reg16 PC_reg( .Clk, .Reset, .Load(LD_PC), .D(PC_in), .Data_out(PC_out));
	reg16 IR_reg(.Clk, .Reset, .Load(LD_IR), .D(bus), .Data_out(IR));
	reg16 MAR_reg(.Clk, .Reset, .Load(LD_MAR), .D(bus), .Data_out(MAR));
	reg16 MDR_reg( .Clk, .Reset, .Load(LD_MDR), .D(MDR_in), .Data_out(MDR));
	////////////////
	
	// MDR Loading logic
	always_comb begin
		if(MIO_EN)
			MDR_in = MDR_In;
		else
			MDR_in = bus;
	end
	////////////////
	
	// PC logic
	always_comb begin
		case(PCMUX)
			2'b00: PC_in = PC_out + 1'b1;
			2'b01: PC_in = bus;
			2'b10:  PC_in = MARMUX_out;
			default: PC_in = PC_out;
		endcase
	end
	////////////////
	
	
	//Register file logic
	register_file registerfile(.D(bus), .*);
	
	always_comb begin
		if(!DRMUX)
			DR = IR[11:9];
		else
			DR = 3'b111;
	end
	
	//SR1 MUX Logic
	always_comb begin
		if(!SR1MUX)
			SR1 = IR[8:6];
		else
			SR1 = IR[11:9];
	end
	
	assign SR2 = IR[2:0];
	////////////////
	
	//MARMUX logic
	logic [15:0] ADDR1_out, ADDR2_out;
	always_comb begin
		ADDR1_out = 16'bX;
		ADDR2_out = 16'bX;
		
		case(ADDR1MUX)
			1'b0:		ADDR1_out = PC_out;
			1'b1:		ADDR1_out = SR1_out;
		endcase
		
		case(ADDR2MUX)
			2'b00: 	ADDR2_out = 16'b0;
			2'b01:	ADDR2_out = {{10{IR[5]}}, IR[5:0]};
			2'b10:	ADDR2_out = {{7{IR[8]}}, IR[8:0]};
			2'b11:	ADDR2_out = {{5{IR[10]}}, IR[10:0]};
		endcase
		
		MARMUX_out = ADDR1_out + ADDR2_out;
	end
	////////////////
	
	//ALU Logic
	logic [15:0] B; 
	always_comb begin
		B = 16'bX;
		case(SR2MUX)
			1'b0: B = SR2_out;
			1'b1: B = {{11{IR[4]}}, IR[4:0]};
		endcase
		
		ALU_out = 16'bX;
		case(ALUK)
			2'b00: ALU_out = B + SR1_out;
			2'b01: ALU_out = B & SR1_out;
			2'b10: ALU_out = ~SR1_out;
			2'b11: ALU_out = SR1_out;
		endcase
	end
	
	////////////////
	
	//BEN and NZP logic
	logic N, Z, P;
	always_ff @(posedge Clk) begin
		if(LD_CC) begin
			N <= bus[15];
			Z <= (bus == 16'b0);
			P <= ~bus[15] & ~(bus == 16'b0);
		end
		
		if(LD_BEN)
			BEN <= IR[11] & N | IR[10] & Z | IR[9] & P;
			
	end
	
	////////////////
	
	
endmodule


module reg16 (		input  logic Load,
						input  logic [15:0]  D,
						input logic Clk, Reset,
						output logic [15:0]  Data_out);
	
	always_ff @(posedge Clk) begin
		if (Reset)
			Data_out <= 16'h0000;
		else if(Load)
			Data_out <= D;
		else
			Data_out <= Data_out;
	end

endmodule

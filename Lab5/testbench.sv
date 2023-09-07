module testbench();

timeunit 10ns;	// Half clock cycle at 50 MHz
			// This is the amount of time represented by #1 
timeprecision 1ns;

// These signals are internal because the processor will be 
// instantiated as a submodule in testbench.

logic [9:0] SW; 
logic	Clk, Run, Continue;
logic [9:0] LED;
logic [6:0] HEX0, HEX1, HEX2, HEX3;
logic [15:0] PC, hex_data;

assign PC = test.slc.d0.PC_out;
assign hex_data = test.slc.memory_subsystem.hex_data;
//assign R0 = test.slc.d0.registerfile.registers[3'b000];
//assign R1 = test.slc.d0.registerfile.registers[3'b001];
//assign R2 = test.slc.d0.registerfile.registers[3'b010];
//assign R3 = test.slc.d0.registerfile.registers[3'b011];
//assign MAR = test.slc.MAR;
//assign MDR = test.slc.MDR;
//assign IR = test.slc.IR;


slc3_testtop test(.*);
// Toggle the clock
// #1 means wait for a delay of 1 timeunit
always begin : CLOCK_GENERATION
#1 Clk = ~Clk;
end

initial begin: CLOCK_INITIALIZATION
    Clk = 0;
end 

initial begin: TEST_VECTORS
Run = 1;						//buttons are active low (normally 1)
Continue = 1;
SW = 10'h05A;

#2 Run = 0;				//pressing reset button (active low) to get into initial state
	Continue=0;
	
#4 Run = 1;
	Continue=1;
	
#6 Run=0;
#7 Run=1;
			
#50 SW = 10'h02;	//sort
#52 Continue = 0;
#54 Continue = 1;

#1500 SW = 10'h03;	//display


#10000 Continue = 0;	//display first value
#10020 Continue = 1;

#10100 Continue = 0;
#10120 Continue = 1;

#10200 Continue = 0;
#10220 Continue = 1;

#10300 Continue = 0;
#10320 Continue = 1;

#10400 Continue = 0;
#10420 Continue = 1;

#10500 Continue = 0;
#10520 Continue = 1;

#10600 Continue = 0;
#10620 Continue = 1;

#10700 Continue = 0;
#10720 Continue = 1;

#13000 $stop;
end

endmodule
module testbench_simple();

timeunit 10ns;	// Half clock cycle at 50 MHz
			// This is the amount of time represented by #1 
timeprecision 1ns;

// These signals are internal because the processor will be 
// instantiated as a submodule in testbench.
logic Clk, Run, Reset, X;
logic [7:0] SW, A, B, answer;
logic [6:0] AHexU, AHexL, BHexU, BHexL;
integer ErrorCnt = 0;


Multiplier processor0(.*);	

typedef enum logic [5:0] {HOLD, ADD0, ADD1, ADD2, ADD3, ADD4, ADD5, ADD6, SUB, SH0, SH1, SH2, SH3, SH4, SH5, SH6, SH7, RESET, BEGIN, WAIT} States;
States state, next;

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
Reset = 1;
SW = 'h00;

#2 Reset = 0;				//pressing reset button (active low) to get into initial state
#4 Reset = 1;

#6 SW = 'hFE;			 	//set switches to first operand

#8 Reset = 0;				
#10 Reset = 1;

#12 SW = 'hFE;				//set switches to second operand

#14 Run = 0;				//pressing run button (active low) to start operation
#16 Run = 1;

#30 $stop;

end

always_comb begin
	state = States'(processor0.control_unit.curr_state);
	next = States'(processor0.control_unit.next_state);
	A = processor0.A_val;
	B = processor0.B_val;
	X = processor0.X;
end

endmodule

module Multiplier( input Clk, Reset, Run,
						 input [7:0] SW,
						 output [6:0]	AHexU, AHexL, BHexU, BHexL
						);
						
logic Clr_A, Ld_B, Shift, Add, Sub, X, X_val, A_shift_out;							
logic [7:0] A_val, B_val, A_in;
logic Reset_sync, Run_sync;

always_ff @(posedge Clk) begin
	if(Clr_A)
		X <= 0;
	else if(Add | Sub)
		X <= X_val;
	else
		X <= X;
	
end

Register regA(.Clk(Clk), .Reset(Clr_A), 	.Shift_In(X), 				.Load(Add | Sub), .Shift_En(Shift), .D(A_in), .Shift_Out(A_shift_out), 	.Data_Out(A_val));
Register regB(.Clk(Clk), 						.Shift_In(A_shift_out), .Load(Ld_B), 		.Shift_En(Shift), .D(SW), 										.Data_Out(B_val));


Adder adder(.A({A_val[7],A_val}), .B({SW[7],SW}), .Cin(Sub), .S({X_val,A_in}));

Control control_unit(.Clk(Clk), .Run(Run_sync), .Reset(Reset_sync), .M(B_val[0]), .M_next(B_val[1]), .Clr_A(Clr_A), .Ld_B(Ld_B), .Shift(Shift), .Add(Add), .Sub(Sub));

//add hex driver
HexDriver AUpper(.In0(A_val[7:4]), .Out0(AHexU));
HexDriver ALower(.In0(A_val[3:0]), .Out0(AHexL));
HexDriver BUpper(.In0(B_val[7:4]), .Out0(BHexU));
HexDriver BLower(.In0(B_val[3:0]), .Out0(BHexL));

sync button_sync[1:0] (Clk, {~Reset, ~Run}, {Reset_sync, Run_sync});

endmodule

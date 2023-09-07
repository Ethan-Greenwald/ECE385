module select_adder (
	input  logic [15:0] A, B,
	input  logic        cin,
	output logic [15:0] S,
	output logic        cout
);

    /* TODO
     *
     * Insert code here to implement a CSA adder.
     * Your code should be completly combinational (don't use always_ff or always_latch).
     * Feel free to create sub-modules or other files. */
	  logic c0, c1, c2;
	  ripple_adder_4 adder0(.A(A[3:0]), .B(B[3:0]), .cin, .S(S[3:0]), .cout(c0));
	  
	  CSA_module mod1(.A(A[7:4]), .B(B[7:4]), .cin(c0), .S(S[7:4]), .cout(c1));
	  
	  CSA_module mod2(.A(A[11:8]), .B(B[11:8]), .cin(c1), .S(S[11:8]), .cout(c2));
	  
	  CSA_module mod3(.A(A[15:12]), .B(B[15:12]), .cin(c2), .S(S[15:12]), .cout);

endmodule

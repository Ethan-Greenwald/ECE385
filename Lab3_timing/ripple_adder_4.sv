module ripple_adder_4
(
	input  logic [3:0] A, B,
	input  logic        cin,
	output logic [3:0] S,
	output logic        cout
);

    /* TODO
     *
     * Insert code here to implement a ripple adder.
     * Your code should be completly combinational (don't use always_ff or always_latch).
     * Feel free to create sub-modules or other files. */
	  wire w0, w1, w2;
	  full_adder add0( .A(A[0]), .B(B[0]), .Cin(cin), .S(S[0]), .Cout(w0));
	  full_adder add1( .A(A[1]), .B(B[1]), .Cin(w0), .S(S[1]), .Cout(w1));
	  full_adder add2( .A(A[2]), .B(B[2]), .Cin(w1), .S(S[2]), .Cout(w2));
	  full_adder add3( .A(A[3]), .B(B[3]), .Cin(w2), .S(S[3]), .Cout(cout));

     
endmodule


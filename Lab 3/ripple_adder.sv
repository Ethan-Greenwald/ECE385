module ripple_adder
(
	input  logic [15:0] A, B,
	input  logic        cin,
	output logic [15:0] S,
	output logic        cout
);

    /* TODO
     *
     * Insert code here to implement a ripple adder.
     * Your code should be completly combinational (don't use always_ff or always_latch).
     * Feel free to create sub-modules or other files. */
	  wire w0, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14;
	  full_adder add0( .A(A[0]), .B(B[0]), .Cin(cin), .S(S[0]), .Cout(w0));
	  full_adder add1( .A(A[1]), .B(B[1]), .Cin(w0), .S(S[1]), .Cout(w1));
	  full_adder add2( .A(A[2]), .B(B[2]), .Cin(w1), .S(S[2]), .Cout(w2));
	  full_adder add3( .A(A[3]), .B(B[3]), .Cin(w2), .S(S[3]), .Cout(w3));
	  full_adder add4( .A(A[4]), .B(B[4]), .Cin(w3), .S(S[4]), .Cout(w4));
	  full_adder add5( .A(A[5]), .B(B[5]), .Cin(w4), .S(S[5]), .Cout(w5));
	  full_adder add6( .A(A[6]), .B(B[6]), .Cin(w5), .S(S[6]), .Cout(w6));
	  full_adder add7( .A(A[7]), .B(B[7]), .Cin(w6), .S(S[7]), .Cout(w7));
	  full_adder add8( .A(A[8]), .B(B[8]), .Cin(w7), .S(S[8]), .Cout(w8));
	  full_adder add9( .A(A[9]), .B(B[9]), .Cin(w8), .S(S[9]), .Cout(w9));
	  full_adder add10( .A(A[10]), .B(B[10]), .Cin(w9), .S(S[10]), .Cout(w10));
	  full_adder add11( .A(A[11]), .B(B[11]), .Cin(w10), .S(S[11]), .Cout(w11));
	  full_adder add12( .A(A[12]), .B(B[12]), .Cin(w11), .S(S[12]), .Cout(w12));
	  full_adder add13( .A(A[13]), .B(B[13]), .Cin(w12), .S(S[13]), .Cout(w13));
	  full_adder add14( .A(A[14]), .B(B[14]), .Cin(w13), .S(S[14]), .Cout(w14));
	  full_adder add15( .A(A[15]), .B(B[15]), .Cin(w14), .S(S[15]), .Cout(cout));

     
endmodule


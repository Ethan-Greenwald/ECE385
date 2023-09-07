module full_adder(input logic A, B, Cin, output logic S, Cout);

	always_comb begin
		S = A ^ B ^ Cin;
		Cout = (A & B) | (B & Cin) | (A & Cin);
	end
	
endmodule

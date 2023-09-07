module cla4(input logic Cin,
				input logic [3:0] A,B,
				output logic P,G,
				output logic [3:0] S);
			
		logic c1, c2, c3;
		logic [3:0] P_array;
		logic [3:0] G_array;
		
		full_adder add0 (.A(A[0]), .B(B[0]), .Cin(Cin), .S(S[0]));
		full_adder add1 (.A(A[1]), .B(B[1]), .Cin(c1),  .S(S[1]));
		full_adder add2 (.A(A[2]), .B(B[2]), .Cin(c2),  .S(S[2]));
		full_adder add3 (.A(A[3]), .B(B[3]), .Cin(c3),  .S(S[3]));
		
		always_comb begin
			P_array = A ^ B;
			G_array = A & B;
			
			c1 = Cin & P_array[0] | G_array[0];
			c2 = Cin & P_array[0] & P_array[1] | G_array[0] & P_array[1] | G_array[1];
			c3 = Cin & P_array[0] & P_array[1] & P_array[2] | G_array[0] & P_array[1] & P_array[2] | G_array[1] & P_array[2] | G_array[2];
			
			P = P_array[0] & P_array[1] & P_array[2] & P_array[3];
			G = G_array[3] | G_array[2] & P_array[3] | G_array[1] & P_array[3] & P_array[2] | G_array[0] & P_array[3] & P_array[2] & P_array[1];
		end
		
endmodule

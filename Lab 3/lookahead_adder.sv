module lookahead_adder(input [15:0] A, B,
					 input cin,
					 output cout, 
					 output [15:0] S);
					 
			logic C4, C8, C12;
			logic P0, P4, P8, P12;
			logic G0, G4, G8, G12;
			
			cla4 CLA_addr1(.Cin(cin), .A(A[3:0]),   .B(B[3:0]),   .S(S[3:0]),   .P(P0),  .G(G0));
			cla4 CLA_addr2(.Cin(C4),  .A(A[7:4]),   .B(B[7:4]),   .S(S[7:4]),   .P(P4),  .G(G4));
			cla4 CLA_addr3(.Cin(C8),  .A(A[11:8]),  .B(B[11:8]),  .S(S[11:8]),  .P(P8),  .G(G8));
			cla4 CLA_addr4(.Cin(C12), .A(A[15:12]), .B(B[15:12]), .S(S[15:12]), .P(P12), .G(G12));
			
			always_comb begin
				C4 = G0 | cin & P0;
				C8 = G4 | G0 & P4 | cin & P0 & P4;
				C12 = G8 | G4 & P8 | G0 & P8 & P4 | cin & P0 & P4 & P8;
				cout = G12 | G8 & P12 | G4 & P8 & P12 | G0 & P4 & P8 & P12 | cin & P0 & P4 & P8 & P12;
			end
endmodule

			
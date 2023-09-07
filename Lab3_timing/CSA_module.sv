module CSA_module(input logic [3:0] A, B, 
						input logic cin, 
						output logic [3:0] S, 
						output logic cout);


	  logic [3:0] out0, out1;
	  logic c0, c1;
	  
	  ripple_adder_4 adder0(.A, .B, .cin(1'b0), .S(out0), .cout(c0));
	  ripple_adder_4 adder1(.A, .B, .cin(1'b1), .S(out1), .cout(c1));
	  
	  always_comb begin
		  if(cin == 0)
				 S = out0;
		  else
				 S = out1;
	  end
	  
	  assign cout = c0 | (c1 & cin);
	  
endmodule

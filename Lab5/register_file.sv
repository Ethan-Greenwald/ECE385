module register_file( input logic Clk,
							 input logic [15:0] D,
							 input logic [2:0] DR, SR1, SR2,
							 input logic LD_REG, 
							 output logic [15:0] SR1_out, SR2_out
);
							
	logic [15:0] registers [8];
	always_ff @(posedge Clk) begin
		if(LD_REG)
			registers[DR] = D;
	end
	
	always_comb begin
		SR1_out = registers[SR1];
		SR2_out = registers[SR2];
	end
	
endmodule

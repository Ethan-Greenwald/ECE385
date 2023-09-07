transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -sv -work work +incdir+D:/ECE\ 385/Lab\ 3 {D:/ECE 385/Lab 3/cla4.sv}
vlog -sv -work work +incdir+D:/ECE\ 385/Lab\ 3 {D:/ECE 385/Lab 3/reg_17.sv}
vlog -sv -work work +incdir+D:/ECE\ 385/Lab\ 3 {D:/ECE 385/Lab 3/mux2_1_17.sv}
vlog -sv -work work +incdir+D:/ECE\ 385/Lab\ 3 {D:/ECE 385/Lab 3/lookahead_adder.sv}
vlog -sv -work work +incdir+D:/ECE\ 385/Lab\ 3 {D:/ECE 385/Lab 3/HexDriver.sv}
vlog -sv -work work +incdir+D:/ECE\ 385/Lab\ 3 {D:/ECE 385/Lab 3/control.sv}
vlog -sv -work work +incdir+D:/ECE\ 385/Lab\ 3 {D:/ECE 385/Lab 3/full_adder.sv}
vlog -sv -work work +incdir+D:/ECE\ 385/Lab\ 3 {D:/ECE 385/Lab 3/adder_toplevel.sv}


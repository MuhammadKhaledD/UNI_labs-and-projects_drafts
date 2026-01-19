vsim -gui work.alu -gn=8
add wave -position insertpoint  \
sim:/alu/A \
sim:/alu/B \
sim:/alu/S \
sim:/alu/Cin \
sim:/alu/F \
sim:/alu/Cout
force -freeze sim:/alu/A 00001111 0
force -freeze sim:/alu/Cin 0 0
force -freeze sim:/alu/S 0000 0
run
force -freeze sim:/alu/B 00000001 0
force -freeze sim:/alu/S 0001 0
run
force -freeze sim:/alu/A 11111111 0
run
force -freeze sim:/alu/S 0010 0
run
force -freeze sim:/alu/S 0011 0
run
force -freeze sim:/alu/Cin 1 0
force -freeze sim:/alu/S 0000 0
force -freeze sim:/alu/A 00001110 0
run
force -freeze sim:/alu/S 0001 0
force -freeze sim:/alu/A 11111111 0
run
force -freeze sim:/alu/S 0010 0
force -freeze sim:/alu/A 00001111 0
run
force -freeze sim:/alu/S 0011 0
force -freeze sim:/alu/A 11110000 0
run
force -freeze sim:/alu/A 11110101 0
force -freeze sim:/alu/B 10101010 0
force -freeze sim:/alu/Cin 0 0
force -freeze sim:/alu/S 0100 0
run
force -freeze sim:/alu/S 0101 0
run
force -freeze sim:/alu/S 0110 0
run
force -freeze sim:/alu/S 0111 0
run
force -freeze sim:/alu/S 1000 0
run
force -freeze sim:/alu/S 1001 0
run
force -freeze sim:/alu/S 1010 0
run
force -freeze sim:/alu/Cin 1 0
run
force -freeze sim:/alu/Cin 0 0
force -freeze sim:/alu/S 1011 0
run
force -freeze sim:/alu/S 1100 0
run
force -freeze sim:/alu/S 1101 0
run
force -freeze sim:/alu/S 1110 0
run
force -freeze sim:/alu/Cin 1 0
run
force -freeze sim:/alu/Cin 0 0
force -freeze sim:/alu/S 1111 0
run
force -freeze sim:/alu/A 01111010 0
force -freeze sim:/alu/S 1001 0
run
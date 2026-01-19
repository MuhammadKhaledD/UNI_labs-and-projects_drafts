vcom RegFileMemArray.vhd

vsim work.RegFileMemArray

add wave -position insertpoint  \
sim:/RegFileMemArray/clk \
sim:/RegFileMemArray/rst \
sim:/RegFileMemArray/we \
sim:/RegFileMemArray/WAddress \
sim:/RegFileMemArray/RAddress1 \
sim:/RegFileMemArray/RAddress2 \
sim:/RegFileMemArray/writePort \
sim:/RegFileMemArray/readPort1 \
sim:/RegFileMemArray/readPort2

force clk 0 0, 1 10ns -repeat 20ns
force rst 1
force we 0
force RAddress1 000
force RAddress2 000
force WAddress 000
force writePort 00000000

run 20ns
force rst 0

force we 1
force WAddress 000
force writePort 11111111
run 20ns

force WAddress 001
force writePort 00010001
run 20ns

force WAddress 111
force writePort 10010000
run 20ns

force WAddress 011
force writePort 00001000
run 20ns

force RAddress1 001
force RAddress2 111
force WAddress 100
force writePort 00000011
run 20ns

force we 0
force RAddress1 010
force RAddress2 011
run 20ns

force RAddress1 100
force RAddress2 101
run 20ns

force we 1
force WAddress 000
force writePort 00000001
force RAddress1 110
force RAddress2 000
run 20ns

force we 0
run 20ns

wave zoom full

CC = gcc-10

funcNames = Log Log2 Log10 Exp Exp10 Exp2 Sinh Cosh
funcPiNames = Cospi Sinpi

obj = $(patsubst %, %, $(funcNames)) $(patsubst %, %, $(funcPiNames))

all: $(obj)

%: %.c
	$(CC) -frounding-math -fsignaling-nans -O3 -std=c11 -I../../../helper/ -I../../../include/  $^ ../../../lib/float34ROMathLib.a -lmpfr -lgmp -lm -o $@

clean:
	rm -rf $(obj) *.dSYM

CC = gcc-10

funcNames = Log Log2 Log10 Exp Exp2 Exp10 Sinh Cosh Cospi Sinpi

src = $(patsubst %, %.c, $(funcNames))
obj = $(patsubst %, %, $(funcNames))

all: $(obj)

%: %.c
	$(CC) -I../../include -frounding-math -fsignaling-nans -O3 -std=c11 $^ ../../lib/float34ROMathLib.a -lm -o $@

clean:
	rm -rf $(obj) *.dSYM

CC = gcc-10

funcNames = Log Log2 Log10 Exp Sinh Cosh Sinpi Cospi

src = $(patsubst %, %.c, $(funcNames))
obj = $(patsubst %, %, $(funcNames))

all: $(obj)

%: %.c
	$(CC) -static -frounding-math -fsignaling-nans -O3 -std=c11 -I../../../helper/ -I../../../include/ -I../../../external/include/crlibm/ $^ ../../../external/lib/libcrlibm.a ../../../lib/float34ROMathLib.a -o $@

clean:
	rm -rf $(obj) *.dSYM

CC = $(ICCPATH)/compiler/latest/linux/bin/intel64/icc

funcNames = Log Log2 Log10 Exp Exp10 Exp2 Sinh Cosh Sinpi Cospi

src = $(patsubst %, %.c, $(funcNames))
obj = $(patsubst %, %, $(funcNames))

all: $(obj)

%: %.c
	$(CC) -O3 -static -std=c11 -fp-model strict -no-ftz -I../../../include $^ ../../../lib/float34ROMathLib.a $(ICCPATH)/compiler/latest/linux/compiler/lib/intel64/libimf.a -no-ftz -o $@

clean:
	rm -rf $(obj) *.dSYM

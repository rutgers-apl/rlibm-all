CC = $(ICCPATH)/compiler/latest/linux/bin/intel64/icc

funcNames = Log Log2 Log10 Exp Exp2 Exp10 Sinh Cosh Cospi Sinpi

src = $(patsubst %, %.c, $(funcNames))
obj = $(patsubst %, %, $(funcNames))

all: $(obj)

%: %.c
	$(CC) -O3 -std=c11 -no-ftz -fp-model strict $^ -no-ftz -o $@

clean:
	rm -rf $(obj) *.dSYM

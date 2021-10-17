CC = gcc-10

funcNames = Log2Small

obj = $(patsubst %, %, $(funcNames)) $(patsubst %, %, $(funcPiNames))

all: $(obj)

%: %.c
	$(CC) -O3 -std=c11 -I../../helper/ -I../include/  $^ ../lib/small34ROMathLib.a -lm -o $@

clean:
	rm -rf $(obj) *.dSYM

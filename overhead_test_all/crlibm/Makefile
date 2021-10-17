CC = gcc-10

funcNames = Log Log2 Log10 Exp Cosh Sinh Cospi Sinpi

src = $(patsubst %, %.c, $(funcNames))
obj = $(patsubst %, %, $(funcNames))

all: $(obj)

%: %.c
	$(CC) -frounding-math -fsignaling-nans -O3 -std=c11 -I../../external/include/crlibm/ $^ ../../external/lib/libcrlibm.a -o $@

clean:
	rm -rf $(obj) *.dSYM

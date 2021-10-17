CC = gcc

funcNames = Log2Small

src = $(patsubst %, %.c, $(funcNames))
obj = $(patsubst %, %, $(funcNames))

all: $(obj)

%: %.c
	$(CC) -static -I../../include -I../../helper/IntervalGen -frounding-math -fsignaling-nans -O3 -std=c11 $^ -lm -lmpfr -lgmp -o $@

clean:
	rm -rf $(obj) *.dSYM

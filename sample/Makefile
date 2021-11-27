CC = gcc-10

funcNames = sample

src = $(patsubst %, %.c, $(funcNames))
obj = $(patsubst %, %, $(funcNames))

all: $(obj)

%: %.c
	$(CC) -I../include -std=c11 $^ ../lib/float34ROMathLib.a -lm -o $@

clean:
	rm -rf $(obj) *.dSYM

CC = gcc

small34ROFNames = log2small

small34ROSrcDir = source
small34ROObjDir = obj
libDir = lib

small34ROSrc = $(patsubst %, $(small34ROSrcDir)/%.c, $(small34ROFNames))
small34ROObj = $(patsubst %, $(small34ROObjDir)/%.o, $(small34ROFNames))

all: $(libDir)/small34ROMathLib.a

$(small34ROObjDir)/%.o: $(small34ROSrcDir)/%.c
	@mkdir -p $(small34ROObjDir)
	$(CC) -std=c11 -O3 -c $^ -Iinclude/ -o $@

$(libDir)/small34ROMathLib.a: $(small34ROObj)
	@mkdir -p $(libDir)
	ar rc $@ $^

small34ROmlib: $(libDir)/small34ROMathLib.a

clean:
	rm -rf obj lib *.dSYM

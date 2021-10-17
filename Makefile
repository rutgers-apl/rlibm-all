CC = gcc

floatFNames = log log2 log10 exp exp2 exp10 sinh cosh sinpi cospi log2_8 log10_8 
float34ROFNames = log log2 log10 exp exp10 exp2 sinh cosh sinpi cospi

floatSrcDir = source/float
floatObjDir = obj/float
float34ROSrcDir = source/float34RO
float34ROObjDir = obj/float34RO
libDir = lib

floatSrc = $(patsubst %, $(floatSrcDir)/%.c, $(floatFNames))
floatObj = $(patsubst %, $(floatObjDir)/%.o, $(floatFNames))
float34ROSrc = $(patsubst %, $(float34ROSrcDir)/%.c, $(float34ROFNames))
float34ROObj = $(patsubst %, $(float34ROObjDir)/%.o, $(float34ROFNames))

all: $(libDir)/floatMathLib.a $(libDir)/float34ROMathLib.a

$(floatObjDir)/%.o: $(floatSrcDir)/%.c
	@mkdir -p $(floatObjDir)
	$(CC) -std=c11 -O3 -c $^ -Iinclude/ -o $@

$(libDir)/floatMathLib.a: $(floatObj)
	@mkdir -p $(libDir)
	ar rc $@ $^

$(float34ROObjDir)/%.o: $(float34ROSrcDir)/%.c
	@mkdir -p $(float34ROObjDir)
	$(CC) -std=c11 -O3 -c $^ -Iinclude/ -o $@

$(libDir)/float34ROMathLib.a: $(float34ROObj)
	@mkdir -p $(libDir)
	ar rc $@ $^

floatmlib: $(libDir)/floatMathLib.a
float34ROmlib: $(libDir)/float34ROMathLib.a

clean:
	rm -rf obj lib *.dSYM

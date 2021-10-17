objects = Log2Small


CC=g++

INCLUDES= -I$(SOPLEXPATH)/src
CPP_FLAGS= -O2 -w -fvisibility=hidden -fvisibility-inlines-hidden --std=c++17 -I../../helper/
LD_FLAGS= $(SOPLEXPATH)/build/lib/libsoplex.a -lmpfr -lgmp  -lz -lm

all: $(objects)

%.o: %.cpp
	$(CC) $(CPP_FLAGS) -c $< -o $@ $(INCLUDES)

$(objects): %: ../../helper/PolyGenSampling/PolyGenSampling.o %.o 
	$(CC) $^ $(LD_FLAGS) -o $@

clean:
	rm -rf *.o ../../helper/PolyGenSampling/*.o $(objects) *~ *.dSYM dump.lp

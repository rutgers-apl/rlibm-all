#!/bin/bash
cd rlibm_Ofa
make -s clean
make -s
cd ../glibc_double
make -s clean
make -s
cd ../intel_double
make -s clean
make -s
cd ../crlibm
make -s clean
make -s
cd ../rlibm32
make -s clean
make -s
cd ..

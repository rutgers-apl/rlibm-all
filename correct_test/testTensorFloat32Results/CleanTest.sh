#!/bin/bash
cd rlibm_Ofa
make -s clean
cd ../glibc_double
make -s clean
cd ../intel_double
make -s clean
cd ../crlibm
make -s clean
cd ../rlibm32
make -s clean
cd ..

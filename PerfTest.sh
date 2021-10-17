#!/bin/bash
echo -e "\033[1mEstimated time: 15 minutes \033[0m"
echo -e "\033[1mRunning Performance Test Suite \033[0m"
cd overhead_test/glibc_rlibm_generic
make -s clean
make -s
./runAll.sh
make -s clean
cd ../glibc_double
make -s clean
make -s
./runAll.sh
make -s clean
cd ../glibc_float
make -s clean
make -s
./runAll.sh
make -s clean
cd ../crlibm
make -s clean
make -s
./runAll.sh
make -s clean
cd ../glibc_rlibm32
make -s clean
make -s
./runAll.sh
make -s clean
cd ../intel_rlibm_generic
make -s clean
make -s
./runAll.sh
make -s clean
cd ../intel_double
make -s clean
make -s
./runAll.sh
make -s clean
cd ../intel_float
make -s clean
make -s
./runAll.sh
make -s clean
cd ../..

echo -e "\033[1mGenerating Graph Files \033[0m"
python3 SpeedupOverCrlibm.py
python3 SpeedupOverGlibc.py
python3 SpeedupOverIntel.py
python3 SpeedupOverRlibm32.py

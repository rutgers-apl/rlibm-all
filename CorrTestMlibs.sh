#!/bin/bash

echo -e "\033[1mBuilding Test Suite for Float Result \033[0m"
cd correct_test/testFloatResults
./BuildTest.sh

echo -e "\033[1mFloat Result Correctness Test \033[0m"
./RunTest.sh
./CleanTest.sh

echo -e "\033[1mBuilding Test Suite for Tensorfloat32 Result \033[0m"
cd ../testTensorFloat32Results
./BuildTest.sh

echo -e "\033[1mTensorfloat32 Result Correctness Test \033[0m"
./RunTest.sh
./CleanTest.sh

#!/bin/bash

echo -e "\033[1mBuilding Test Suite for Float Result \033[0m"
cd correct_test_all/testFloatResults
./BuildTest.sh

echo -e "\033[1mFloat Result Correctness Test \033[0m"
./RunTest.sh
./CleanTest.sh

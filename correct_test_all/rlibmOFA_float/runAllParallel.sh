#!/bin/bash

parallelism=10

while getopts j: flag
do
    case "${flag}" in
        j) parArg=${OPTARG};;
    esac
done

if [ "$parArg" -eq "$parArg" ] 2>/dev/null
then
   parallelism=$parArg
fi

mkdir -p Result
mkdir -p Result/allrep

echo -e "Building correctness testing harness"
cd allrep
make -s clean
make -s
cd ..

#2. Run function generation program in parallel
echo -e "\033[1m* Checking Correctness of OurLibm. This will take a long time\033[0m"
echo -e "\033[1m* Especially EXP10 will take roughly 48 hours\033[0m"
echo -e "\033[1m* When each function is completely tested, it will print the result\033[0m"
echo -e "\033[1m* In the mean time, you can check the progress in Result/allrep/<function name>.txt\033[0m"
echo -e "\033[1m\tRunning testing script in parallel\033[0m"
echo -e "\033[1m\tParallelism: $parallelism jobs\033[0m"
echo -e "\033[1m\tEstimated time: > 24 hours \033[0m"
cat ParallelCommand.txt | parallel -j $parallelism

cd allrep
make -s clean
cd ..

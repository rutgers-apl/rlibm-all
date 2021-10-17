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

echo -e "\033[1m* Checking Correctness of several libraries.\033[0m"
echo -e "\033[1m* When each function is completely tested, it will print the result\033[0m"
echo -e "\033[1m\tRunning testing script in parallel\033[0m"
echo -e "\033[1m\tParallelism: $parallelism jobs\033[0m"
echo -e "\033[1m\tEstimated time: 2 hours \033[0m"
echo -e ""
echo    "| function |    Using OurLibm    |    glibc dbl libm   |   Intel dbl libm    |    Using Crlibm     |    Using Rlibm32    |"
echo    "--------------------------------------------------------------------------------------------------------------------------"
echo    "|          | rne rnn rnp rnz rna | rne rnn rnp rnz rna | rne rnn rnp rnz rna | rne rnn rnp rnz rna | rne rnn rnp rnz rna |"
cat ParallelCommand.txt | parallel -j $parallelism

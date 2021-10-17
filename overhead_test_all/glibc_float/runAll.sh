#!/bin/bash
echo -e "--- FLOAT WITH GLIBC FLOAT ---"

echo -e "Log"
taskset -c 0 ./Log

echo -e "Log2"
taskset -c 0 ./Log2

echo -e "Log10"
taskset -c 0 ./Log10

echo -e "Exp"
taskset -c 0 ./Exp

echo -e "Exp2"
taskset -c 0 ./Exp2

echo -e "Exp10"
taskset -c 0 ./Exp10

echo -e "Sinh"
taskset -c 0 ./Sinh

echo -e "Cosh"
taskset -c 0 ./Cosh

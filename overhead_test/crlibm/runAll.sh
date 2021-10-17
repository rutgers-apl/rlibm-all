#!/bin/bash
echo -e "--- FLOAT WITH CRLIBM DOUBLE ---"

echo -e "Log"
taskset -c 0 ./Log

echo -e "Log2"
taskset -c 0 ./Log2

echo -e "Log10"
taskset -c 0 ./Log10

echo -e "Exp"
taskset -c 0 ./Exp

echo -e "Sinh"
taskset -c 0 ./Sinh

echo -e "Cosh"
taskset -c 0 ./Cosh

echo -e "Sinpi"
taskset -c 0 ./Sinpi

echo -e "Cospi"
taskset -c 0 ./Cospi

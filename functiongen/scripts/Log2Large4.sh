#!/bin/bash

mkdir -p log2Result

time ../Log2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog2IntervalData log2Result/log2_12.log log2Result/log2_12.h 12
time ../Log2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog2IntervalData log2Result/log2_8.log log2Result/log2_8.h 8
time ../Log2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog2IntervalData log2Result/log2_4.log log2Result/log2_4.h 4
time ../Log2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog2IntervalData log2Result/log2_0.log log2Result/log2_0.h 0

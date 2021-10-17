#!/bin/bash

mkdir -p log10Result

time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_0.log log10Result/log10_0.h 0
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_4.log log10Result/log10_4.h 4
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_8.log log10Result/log10_8.h 8
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_12.log log10Result/log10_12.h 12

#!/bin/bash

mkdir -p log10Result

time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_1.log log10Result/log10_1.h 1
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_5.log log10Result/log10_5.h 5
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_9.log log10Result/log10_9.h 9
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_13.log log10Result/log10_13.h 13

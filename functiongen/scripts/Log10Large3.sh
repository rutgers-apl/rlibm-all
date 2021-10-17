#!/bin/bash

mkdir -p log10Result

time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_2.log log10Result/log10_2.h 2
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_6.log log10Result/log10_6.h 6
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_10.log log10Result/log10_10.h 10
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_14.log log10Result/log10_14.h 14

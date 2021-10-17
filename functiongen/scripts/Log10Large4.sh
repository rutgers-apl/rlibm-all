#!/bin/bash

mkdir -p log10Result

time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_3.log log10Result/log10_3.h 3
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_7.log log10Result/log10_7.h 7
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_11.log log10Result/log10_11.h 11
time ../Log10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLog10IntervalData log10Result/log10_15.log log10Result/log10_15.h 15

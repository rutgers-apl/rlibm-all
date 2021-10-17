#!/bin/bash

mkdir -p exp10Result

time ../Exp10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp10IntervalData exp10Result/exp10_7.log exp10Result/exp10_7.h 7
time ../Exp10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp10IntervalData exp10Result/exp10_11.log exp10Result/exp10_11.h 11
time ../Exp10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp10IntervalData exp10Result/exp10_15.log exp10Result/exp10_15.h 15

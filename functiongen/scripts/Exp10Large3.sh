#!/bin/bash

mkdir -p exp10Result

time ../Exp10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp10IntervalData exp10Result/exp10_6.log exp10Result/exp10_6.h 6
time ../Exp10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp10IntervalData exp10Result/exp10_10.log exp10Result/exp10_10.h 10
time ../Exp10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp10IntervalData exp10Result/exp10_14.log exp10Result/exp10_14.h 14

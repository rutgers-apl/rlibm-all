#!/bin/bash

mkdir -p exp10Result

time ../Exp10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp10IntervalData exp10Result/exp10_8.log exp10Result/exp10_8.h 8
time ../Exp10Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp10IntervalData exp10Result/exp10_12.log exp10Result/exp10_12.h 12

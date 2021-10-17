#!/bin/bash

mkdir -p exp2Result

time ../Exp2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp2IntervalData exp2Result/exp2_4.log exp2Result/exp2_4.h 4
time ../Exp2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp2IntervalData exp2Result/exp2_8.log exp2Result/exp2_8.h 8
time ../Exp2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp2IntervalData exp2Result/exp2_12.log exp2Result/exp2_12.h 12

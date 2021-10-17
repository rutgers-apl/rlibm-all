#!/bin/bash

mkdir -p exp2Result

time ../Exp2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp2IntervalData exp2Result/exp2_6.log exp2Result/exp2_6.h 6
time ../Exp2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp2IntervalData exp2Result/exp2_10.log exp2Result/exp2_10.h 10
time ../Exp2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp2IntervalData exp2Result/exp2_14.log exp2Result/exp2_14.h 14

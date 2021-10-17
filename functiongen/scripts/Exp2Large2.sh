#!/bin/bash

mkdir -p exp2Result

time ../Exp2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp2IntervalData exp2Result/exp2_5.log exp2Result/exp2_5.h 5
time ../Exp2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp2IntervalData exp2Result/exp2_9.log exp2Result/exp2_9.h 9
time ../Exp2Large /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExp2IntervalData exp2Result/exp2_13.log exp2Result/exp2_13.h 13

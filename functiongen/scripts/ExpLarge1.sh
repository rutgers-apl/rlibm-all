#!/bin/bash

mkdir -p expResult

time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_0.log expResult/exp_0.h 0
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_4.log expResult/exp_4.h 4
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_8.log expResult/exp_8.h 8
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_12.log expResult/exp_12.h 12

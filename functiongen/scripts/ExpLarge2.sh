#!/bin/bash

mkdir -p expResult

time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_1.log expResult/exp_1.h 1
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_5.log expResult/exp_5.h 5
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_9.log expResult/exp_9.h 9
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_13.log expResult/exp_13.h 13

#!/bin/bash

mkdir -p expResult

time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_2.log expResult/exp_2.h 2
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_6.log expResult/exp_6.h 6
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_10.log expResult/exp_10.h 10
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_14.log expResult/exp_14.h 14

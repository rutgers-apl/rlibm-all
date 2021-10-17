#!/bin/bash

mkdir -p expResult

time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_3.log expResult/exp_3.h 3
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_7.log expResult/exp_7.h 7
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_11.log expResult/exp_11.h 11
time ../ExpLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROExpIntervalData expResult/exp_15.log expResult/exp_15.h 15

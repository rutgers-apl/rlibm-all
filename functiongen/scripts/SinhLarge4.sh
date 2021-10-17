#!/bin/bash

mkdir -p sinhResults

time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_3.log sinhResults/sinh_3.h 3
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_7.log sinhResults/sinh_7.h 7
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_11.log sinhResults/sinh_11.h 11
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_15.log sinhResults/sinh_15.h 15

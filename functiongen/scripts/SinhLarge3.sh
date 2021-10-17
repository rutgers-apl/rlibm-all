#!/bin/bash

mkdir -p sinhResults

time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_2.log sinhResults/sinh_2.h 2
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_6.log sinhResults/sinh_6.h 6
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_10.log sinhResults/sinh_10.h 10
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_14.log sinhResults/sinh_14.h 14

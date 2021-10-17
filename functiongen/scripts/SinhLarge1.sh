#!/bin/bash

mkdir -p sinhResults

time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_0.log sinhResults/sinh_0.h 0
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_4.log sinhResults/sinh_4.h 4
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_8.log sinhResults/sinh_8.h 8
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_12.log sinhResults/sinh_12.h 12

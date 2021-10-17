#!/bin/bash

mkdir -p sinhResults

time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_1.log sinhResults/sinh_1.h 1
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_5.log sinhResults/sinh_5.h 5
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_9.log sinhResults/sinh_9.h 9
time ../SinhLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROSinhIntervalData sinhResults/sinh_13.log sinhResults/sinh_13.h 13

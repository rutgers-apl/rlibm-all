#!/bin/bash

mkdir -p coshResults

time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh0.log coshResults/cosh0.h 0
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh4.log coshResults/cosh4.h 4
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh8.log coshResults/cosh8.h 8
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh12.log coshResults/cosh12.h 12

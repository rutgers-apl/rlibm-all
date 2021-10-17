#!/bin/bash

mkdir -p coshResults

time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh2.log coshResults/cosh2.h 2
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh6.log coshResults/cosh6.h 6
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh10.log coshResults/cosh10.h 10
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh14.log coshResults/cosh14.h 14

#!/bin/bash

mkdir -p coshResults

time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh1.log coshResults/cosh1.h 1
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh5.log coshResults/cosh5.h 5
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh9.log coshResults/cosh9.h 9
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh13.log coshResults/cosh13.h 13

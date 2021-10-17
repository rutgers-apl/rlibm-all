#!/bin/bash

mkdir -p coshResults

time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh3.log coshResults/cosh3.h 3
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh7.log coshResults/cosh7.h 7
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh11.log coshResults/cosh11.h 11
time ../CoshLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34ROCoshIntervalData coshResults/cosh15.log coshResults/cosh15.h 15

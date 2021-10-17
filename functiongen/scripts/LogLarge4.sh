#!/bin/bash

mkdir -p logResult

time ../LogLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLogIntervalData logResult/log_12.log logResult/log_12.h 12
time ../LogLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLogIntervalData logResult/log_8.log logResult/log_8.h 8
time ../LogLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLogIntervalData logResult/log_4.log logResult/log_4.h 4
time ../LogLarge /filer/tmp1/jpl169/NewMathLibrary/intervals/Float34RoLogIntervalData logResult/log_0.log logResult/log_0.h 0

#pragma once

#ifndef FLOATXUNION
#define FLOATXUNION

typedef union {
    double d;
    unsigned long x;
} doubleX;

typedef union {
    float f;
    unsigned x;
} floatX;
#endif

double rlibm34_log(float);
double rlibm34_log2(float);
double rlibm34_log10(float);
double rlibm34_exp(float);
double rlibm34_exp2(float);
double rlibm34_exp10(float);
double rlibm34_sinh(float);
double rlibm34_cosh(float);
double rlibm34_sinpi(float);
double rlibm34_cospi(float);

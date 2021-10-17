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

double rlibm34_log2_small(float);

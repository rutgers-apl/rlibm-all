#include <stdint.h>
#include "bfloat16.h"

typedef union {
    double d;
    unsigned long x;
} dx;

typedef union {
    float f;
    unsigned int x;
} fx;

bfloat16_t rlibm_exp(bfloat16_t);
bfloat16_t rlibm_exp2(bfloat16_t);
bfloat16_t rlibm_exp10(bfloat16_t);
bfloat16_t rlibm_log(bfloat16_t);
bfloat16_t rlibm_log2(bfloat16_t);
bfloat16_t rlibm_log10(bfloat16_t);
bfloat16_t rlibm_sinpi(bfloat16_t);
bfloat16_t rlibm_cospi(bfloat16_t);
bfloat16_t rlibm_sqrt(bfloat16_t);
bfloat16_t rlibm_cbrt(bfloat16_t);
bfloat16_t rlibm_sinh(bfloat16_t);
bfloat16_t rlibm_cosh(bfloat16_t);

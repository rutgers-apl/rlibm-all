#include "RoundToOddPosit34.h"

int main() {
    mpfr_t mval;
    mpfr_init2(mval, 200);
    
    mpfr_set_d(mval, 1.5, MPFR_RNDN);
    mpfr_exp(mval, mval, MPFR_RNDZ);
    double res = FromMPFRToPosit34RO(mval);
    
    printf("mval= %.100e\n", mpfr_get_d(mval, MPFR_RNDN));
    printf("res = %.100e\n", res);
    printf("res = %lx\n", *(unsigned long*)&res);
    
    mpfr_clear(mval);
    return 0;
}

// 3a29400000000000
// 001110100010

#include "float34RO_math.h"
#include "float34RO_headers/Exp10.h"
#include "float34RO_headers/constants.h"
#include "math.h"

#define MAXVAL 3.40282361850336062550457001444955389952e+38
#define MAXm1VAL 3.40282356779733661637539395458142568448e+38

double rlibm34_exp10(float x) {
    floatX fx;
    fx.f = x;
    
    // Take care of special cases                                                                    
    if ((fx.x & 0x7FFFFFFF) == 0) return 1.0;

    if (fx.x <= 861821911) {
      if (fx.x <= 853433304) return 1.0000000298023223876953125;
      return 1.0000000894069671630859375;
    }

    if (1109008539 <= fx.x && fx.x <= 3000916953) {
      if (fx.x < 0x80000000) {
        if (fx.x < 0x7F800000) return 3.40282361850336062550457001444955389952e+38;
        if (fx.x == 0x7F800000) return 1.0 / 0.0;
        return 0.0/0.0;
      }

      // negative counterpart                                                                        
      if (fx.x <= 2992528344) return 0.99999998509883880615234375;

      return 0.99999995529651641845703125;
    }

    if (fx.x >= 3258228278) {
      if (fx.x == 0xFF800000) return 0.0;
      if (fx.x < 0xFF800000) return ldexp(1.0, -151);
      return 0.0/0.0;
    }

    // If x == 0.0, 1.0, 2.0, ..., 10.0, then it's also special case                                 
    switch(fx.x) {
    case 0x00000000:
    case 0x80000000: return 1.0;
    case 0x3f800000: return 10.0;
    case 0x40000000: return 100.0;
    case 0x40400000: return 1000.0;
    case 0x40800000: return 10000.0;
    case 0x40a00000: return 100000.0;
    case 0x40c00000: return 1000000.0;
    case 0x40e00000: return 10000000.0;
    case 0x41000000: return 100000000.0;
    case 0x41100000: return 1000000000.0;
    case 0x41200000: return 10000000000.0;
    }
    
    // Perform range reduction
    double xp = x * 2.12603398072791179629348334856331348419189453125e+02;
    int N = (int)xp;
    int N2 = N % 64;
    if (N2 < 0) N2 += 64;
    int N1 = N - N2;
    
    int M = N1 / 64;
    int J = N2;
    double R = x - N *
    4.703593682249706219022922226713490090332925319671630859375e-03;
    
    doubleX dX;
    dX.d = R;
    
    // Find the polynomial coefficients to use.
    double y;
    if (dX.x > 0x8000000000000000) {
        unsigned index = (dX.x & 0x03FFFFFFFFFFFFFF) >> 50lu;
        const double* coeff = __exp10NegCoeffs[index];
        
        y = coeff[3];
        y *= R;
        y += coeff[2];
        y *= R;
        y += coeff[1];
        y *= R;
        y += coeff[0];
    }
    else {
        unsigned index = (dX.x & 0x03FFFFFFFFFFFFFF) >> 50lu;
        const double* coeff = __exp10PosCoeffs[index];
        y = coeff[3];
        y *= R;
        y += coeff[2];
        y *= R;
        y += coeff[1];
        y *= R;
        y += coeff[0];
    }
    
    // Perform output compensation
    y *= ldexp(__exp2JBy64[J], M);
    return y;
}

#include "float34RO_math.h"
#include "float34RO_headers/Exp.h"
#include "float34RO_headers/constants.h"
#include "math.h"

double rlibm34_exp(float x) {
    floatX fx;
    fx.f = x;
    
    // Take care of special cases
    if ((fx.x & 0x7FFFFFFF) == 0) return 1.0;

    if (fx.x <= 872415231) {
      if (fx.x <= 864026623) return 1.0000000298023223876953125;
      return 1.0000000894069671630859375;
    }

    if (1118925336 <= fx.x && fx.x <= 3011510272) {
      if (fx.x < 0x80000000) {
        if (fx.x < 0x7F800000) return 3.40282361850336062550457001444955389952e+38;
        if (fx.x == 0x7F800000) return 1.0 / 0.0;
	return 0.0/0.0;
      }
      
      // negative counterpart
      if (fx.x <= 3003121664) return 0.99999998509883880615234375;
      
      return 0.99999995529651641845703125;
    }

    if (fx.x >= 3268407733) {
      if (fx.x == 0xFF800000) return 0.0;
      if (fx.x < 0xFF800000) return ldexp(1.0, -151);
      return 0.0/0.0;
    }
    
    // Perform range reduction
    double xp = x * 92.332482616893656768297660164535045623779296875;
    int N = (int)xp;
    int N2 = N % 64;
    if (N2 < 0) N2 += 64;
    int N1 = N - N2;
    
    int M = N1 / 64;
    int J = N2;
    double R = x - N *
    0.01083042469624914509729318723429969395510852336883544921875;
    
    doubleX dX;
    dX.d = R;
    
    // Find the polynomial coefficients to use.
    const double* coeff;
    unsigned index = (dX.x & 0x03FFFFFFFFFFFFFF) >> 51;
    if (dX.x > 0x8000000000000000) coeff = __expNegCoeffs[index];
    else coeff = __expPosCoeffs[index];
    
    // Compute polynomial
    double y = coeff[4];
    y *= R;
    y += coeff[3];
    y *= R;
    y += coeff[2];
    y *= R;
    y += coeff[1];
    y *= R;
    y += coeff[0];
    
    // Perform output compensation
    y *= ldexp(__exp2JBy64[J], M);
    return y;
}

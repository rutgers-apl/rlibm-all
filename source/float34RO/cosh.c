#include "float34RO_math.h"
#include "float34RO_headers/Sinh.h"
#include "float34RO_headers/Cosh.h"
#include "float34RO_headers/constants.h"

#define CONST64BYLN2 92.332482616893656768297660164535045623779296875
#define LN2BY64 0.01083042469624914509729318723429969395510852336883544921875

double rlibm34_cosh(float x) {
    floatX fx;
    fx.f = x;
    fx.x &= 0x7FFFFFFF;
    
    // Take care of special cases
    if (fx.x <= 973078527) {
      if (fx.x == 0) return 1.0;
      if (fx.x <= 968164595) return 1.0000000298023223876953125;
      return 1.0000000894069671630859375;
    }
    
    if (fx.x >= 1119016189) {
        if (fx.x > 0x7F800000) return 0.0/0.0;
	if (fx.x == 0x7F800000) return 1.0 / 0.0;
        return 3.40282361850336062550457001444955389952e+38;
    }
    
    // Perform range reduction
    double xp = fx.f * CONST64BYLN2;
    int N = (int)xp;
    int N2 = N % 64;
    if (N2 < 0) N2 += 64;
    int N1 = N - N2;
    int I = N1 / 64;
    double R = fx.f - N * LN2BY64;
    double R2 = R * R;
    
    double sinhHigh = __sinhKLn2[I];
    double coshHigh = __coshKLn2[I];
    double sinhMid = __sinhKLn2By64[N2];
    double coshMid = __coshKLn2By64[N2];
    
    double sinhHM = sinhHigh * coshMid + coshHigh * sinhMid;
    double coshHM = sinhHigh * sinhMid + coshHigh * coshMid;
    
    doubleX dX;
    dX.d = R;
    
    // Find the polynomial coefficients to use.
    unsigned long coshIndex = (dX.x & 0x03FFFFFFFFFFFFFFlu) >> 53lu;
    unsigned long sinhIndex = (dX.x & 0x03FFFFFFFFFFFFFFlu) >> 52lu;
    
    const double* sinhCoeff = __sinhCoeffs[sinhIndex];
    const double* coshCoeff = __coshCoeffs[coshIndex];
    
    // Compute sinh component
    double sinhL = sinhCoeff[2];
    sinhL *= R2;
    sinhL += sinhCoeff[1];
    sinhL *= R2;
    sinhL += sinhCoeff[0];
    sinhL *= R;
    
    // Compute cosh component
    double coshL = coshCoeff[2];
    coshL *= R2;
    coshL += coshCoeff[1];
    coshL *= R2;
    coshL += coshCoeff[0];
    
    // Perform output compensation
    return sinhHM * sinhL + coshHM * coshL;
}

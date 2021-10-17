#include "float34RO_math.h"
#include "float34RO_headers/Sinpi.h"
#include "float34RO_headers/Cospi.h"
#include "float34RO_headers/constants.h"

double rlibm34_cospi(float x) {
  floatX fX;
  fX.f = x;
  fX.x &= 0x7FFFFFFF;

  if (fX.x <= 950204803) {
    if (fX.x == 0) return 1.0;
    return 0.99999998509883880615234375;
  }
  
  if (fX.x >= 0x4b000000) {
    if (fX.x >= 0x7F800000) return 0.0 / 0.0;
    if (fX.x >= 0x4b800000) return 1.0;
    
    // If x >= 2^23, then if x is even, then 1.0f
    if ((fX.x & 0x1) == 0) return 1.0;
    
    // Otherwise, then -1.0f
    return -1.0;
  }
    
  // Range Reduction
  double xp = fX.f * 512.0;
  unsigned N = (unsigned)xp;
  unsigned N2 = N & 0xFF;
  unsigned I = (N >> 8) + 1;
  double R, cospiM, sinpiM;
  unsigned long s = (I & 0x2) ? 0x8000000000000000 : 0;
  R = fX.f - N * 0.001953125;
  
  if (R == 0 && N2 == 0) {
    if (I & 1l) {
      doubleX resx;
      resx.d = 1.0;
      resx.x |= s;
      return resx.d;
    } else {
      return 0.0;
    }
  }
    
  if (I & 1) {
    if (N2 == 0) {
      cospiM = 1.0;
      sinpiM = 0.0;
    }
    else {
      N2++;
      R = 0.001953125 - R;
      cospiM = __sinpiMBy512[256 - N2];
      sinpiM = __cospiMBy512[256 - N2];
    }
  } else {
    cospiM = __sinpiMBy512[N2];
    sinpiM = __cospiMBy512[N2];
  }

    doubleX dX;
    dX.d = R;

    // Find the polynomial coefficients to use.
    unsigned long index = (dX.x & 0x03FFFFFFFFFFFFFFlu) >> 56lu;

    const double* sinpiCoeff = __sinpiCoeffs[index];
    const double* cospiCoeff = __cospiCoeffs[index];
    
    double R2 = R * R;
    double cospiR, sinpiR;
        
    sinpiR = sinpiCoeff[2];
    sinpiR *= R2;
    sinpiR += sinpiCoeff[1];
    sinpiR *= R2;
    sinpiR += sinpiCoeff[0];
    sinpiR *= R;
    
    cospiR = cospiCoeff[2];
    cospiR *= R2;
    cospiR += cospiCoeff[1];
    cospiR *= R2;
    cospiR += cospiCoeff[0];

    dX.d = cospiM * cospiR + sinpiM * sinpiR;
    dX.x ^= s;
    
    return dX.d;
}

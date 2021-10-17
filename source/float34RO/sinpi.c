#include "float34RO_math.h"
#include "float34RO_headers/Sinpi.h"
#include "float34RO_headers/Cospi.h"
#include "float34RO_headers/constants.h"

#define PI 3.141592653589793115997963468544185161590576171875

double rlibm34_sinpi(float x) {
  floatX fX;
  fX.f = x;
  unsigned long s = (fX.x & 0x80000000) == 0 ? 0x0 : 0x8000000000000000;
  fX.x &= 0x7FFFFFFF;
  
  if (fX.x <= 872158519) {
    if (fX.x == 869073367) {
      if (s) return -2.9990871297513876925222575664520263671875e-07;
      return 2.9990871297513876925222575664520263671875e-07;
    }

    return (double)x * PI;
  }
  
  if (fX.x >= 0x4b000000) {
      if (fX.x >= 0x7F800000) {
          return 0.0/0.0;
      }
      return 0.0;
  }
  
  double xp = fX.f * 512;
  unsigned N = (unsigned)xp;
  unsigned N2 = N & 0xFF;
  unsigned I = N >> 8;
  double R = fX.f - N * 0.001953125;
  if (I & 0x2) s ^= 0x8000000000000000;
  
  doubleX dX;
    
  // More special cases when sinpi(x) is exactly representable
  if (R == 0 && N2 == 0) {
    if (I & 0x1) {
      dX.d = 1.0;
      dX.x |= s;
      return dX.d;
    } else {
      return 0.0;
    }
  }

  if (I & 0x1) {
      N2 = 255 - N2;
      R = 0.001953125 - R;
  }

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
      
  dX.d = __sinpiMBy512[N2] * cospiR + __cospiMBy512[N2] * sinpiR;
  dX.x ^= s;
  
  return dX.d;
}

#include "float34RO_math.h"
#include "float34RO_headers/constants.h"
#include "float34RO_headers/Log2.h"
#include "math.h"

double rlibm34_log2(float x) {
  floatX fix, fit, spec;
  fix.f = x;
  int m = 0;

  if (fix.x < 0x800000 || fix.x >= 0x7F800000) {
    if ((fix.x & 0x7FFFFFFF) == 0) { // log(+/-0) = -infty
      fix.x = 0xFF800000;
      return fix.f;
    }
    
    if (fix.x > 0x7FFFFFFF) { // Log(-val) = NaN
      return (x - x) / 0;
        
    }
    
    if (fix.x >= 0x7F800000) {
      return x + x;
    }

    // Special case when we have denormal input and exact result
    int exp;
    spec.f = frexpf(fix.f, &exp);
    if (spec.x == 0x3f000000) return (double)(exp - 1);

    fix.f *= 8.388608e+06;
    m -= 23;
  }
  
  m += fix.x >> 23;
  m -= 127;
  fix.x &= 0x007FFFFF;
  
  if (fix.x == 0) {
    return (double)m;
  }
  
  fix.x |= 0x3F800000;
  
  fit.x = fix.x & 0x007F0000;
  int FIndex = fit.x >> 16;
  fit.x |= 0x3F800000;
  
  double f = fix.f - fit.f;
  f *= __log_oneByF[FIndex];
  
  // Find the index of polynomial coefficients
  doubleX dX;
  dX.d = f;
  unsigned long index = (dX.x & 0x01FFFFFFFFFFFFFFlu) >> 49lu;
  const double* coeffs = __log2Coeffs[index];

  double y = coeffs[2];
  y *= f;
  y += coeffs[1];
  y *= f;
  y += coeffs[0];
  y *= f;
  
  y += __log2_lut[FIndex];
  y += m;
  
  return y;
}

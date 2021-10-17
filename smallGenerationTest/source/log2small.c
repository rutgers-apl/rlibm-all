#include "Log2Small_math.h"
#include "float34RO_headers/constants.h"
#include "float34RO_headers/log2Small.h"
#include "math.h"

double rlibm34_log2_small(float x) {
  floatX fix, fit, spec;
  fix.f = x;
  int m = 0;
  
  m += fix.x >> 23;
  m -= 127;
  fix.x &= 0x007FFFFF;
  
  if (fix.x == 0) return (double)m;
  
  fix.x |= 0x3F800000;
  fit.x = fix.x & 0x007F0000;
  int FIndex = fit.x >> 16;
  fit.x |= 0x3F800000;
  
  double f = fix.f - fit.f;
  f *= __log_oneByF_small[FIndex];
  
  const double* coeffs = __log2CoeffsSmall[0];

  double y = coeffs[4];
  y *= f;
  y += coeffs[3];
  y *= f;
  y += coeffs[2];
  y *= f;
  y += coeffs[1];
  y *= f;
  y += coeffs[0];
  y *= f;
  
  y += __log2_lut_small[FIndex];
  y += m;
  
  return y;
}

#include "float34RO_math.h"
#include "float34RO_headers/constants.h"
#include "float34RO_headers/Log.h"
#include "math.h"

#define LN2HIGH 0.69314718055994528622676398299518041312694549560546875

double rlibm34_log(float x) {
    floatX fix, fit;
    fix.f = x;
    int m = 0;

    // Special case for RO:
    if (x == 1.0) return 0.0;
    
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
        
        fix.f *= 8.388608e+06;
        m -= 23;
    }
    
    m += fix.x >> 23;
    m -= 127;
    fix.x &= 0x007FFFFF;
    fix.x |= 0x3F800000;
    
    fit.x = fix.x & 0x007F0000;
    int FIndex = fit.x >> 16;
    fit.x |= 0x3F800000;
    
    double f = fix.f - fit.f;
    f *= __log_oneByF[FIndex];
    
    // Find the index of polynomial coefficients
    doubleX dX;
    dX.d = f;
    unsigned long index = (dX.x & 0x01FFFFFFFFFFFFFFlu) >> 47lu;
    const double* coeffs = __logCoeffs[index];

    double y = coeffs[2];
    y *= f;
    y += coeffs[1];
    y *= f;
    y += coeffs[0];
    y *= f;
    
    y += __ln_lutHIGH[FIndex];
    y += m * LN2HIGH;
    
    return y;
}

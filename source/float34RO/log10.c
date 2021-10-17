#include "float34RO_math.h"
#include "float34RO_headers/constants.h"
#include "float34RO_headers/Log10.h"
#include "math.h"

#define LOG102HIGH 0.30102999566398114250631579125183634459972381591796875
#define LOG102LOW  5.27074231034726570126349709198449199648263806413338306011695522101945243775844573974609375e-17

double rlibm34_log10(float x) {
    floatX fix, fit;
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
        
        fix.f *= 8.388608e+06;
        m -= 23;
    }

    switch (fix.x) {
    case 0x3f800000 : return 0.0;
    case 0x41200000 : return 1.0;
    case 0x42c80000 : return 2.0;
    case 0x447a0000 : return 3.0;
    case 0x461c4000 : return 4.0;
    case 0x47c35000 : return 5.0;
    case 0x49742400 : return 6.0;
    case 0x4b189680 : return 7.0;
    case 0x4cbebc20 : return 8.0;
    case 0x4e6e6b28 : return 9.0;
    case 0x501502f9 : return 10.0;
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
    unsigned long index = (dX.x & 0x01FFFFFFFFFFFFFFlu) >> 49lu;
    const double* coeffs = __log10Coeffs[index];

    double y = coeffs[2];
    y *= f;
    y += coeffs[1];
    y *= f;
    y += coeffs[0];
    y *= f;
    
    y += m * LOG102LOW;
    y += __log10_lut[FIndex];
    y += m * LOG102HIGH;
    
    return y;
}

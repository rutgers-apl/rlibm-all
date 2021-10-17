#pragma once
#include "mpfr.h"

using namespace std;

mpfr_t mval;

template <class T>
class Elementary {
    public :
    
    static double RangePropagation(double, double);
    static double ReverseRangePropagation(double, double);
    static bool FlipLbAndUb(double);
        
    static T MpfrCalculateFunction(T);
    static double RangeReduction(T, double&);
    static bool ComputeSpecialCase(T, T&);
    static T FromMPFR(mpfr_t);
};

template <>
bfloat16 Elementary<bfloat16>::FromMPFR(mpfr_t _mval) {
        double retVal = mpfr_get_d(_mval, MPFR_RNDN);

        if (retVal == 0) return 0.0;
        if (retVal != retVal) {
            return retVal;
        }
        
        if (mpfr_cmp_d(_mval, pow(2, -134)) <= 0 &&
            mpfr_cmp_d(_mval, -pow(2, -134)) >= 0) {
            return 0.0;
        }

        long exp;
        double fr = mpfr_get_d_2exp(&exp, _mval, MPFR_RNDN);
        fr *= 2;
        exp--;
        
        if (mpfr_cmp_d(_mval, 0.0) > 0) {
            if (mpfr_cmp_d(_mval, 1.5 * pow(2, -133)) < 0) return pow(2, -133);
            if (mpfr_cmp_d(_mval, pow(2, -132)) < 0) return pow(2, -132);
        } else {
            if (mpfr_cmp_d(_mval, -1.5 * pow(2, -133)) > 0) return -pow(2, -133);
            if (mpfr_cmp_d(_mval, -pow(2, -132)) > 0) return -pow(2, -132);
        }
        
        if (exp >= -132 && exp <= -127) {
            int prec = 134 + exp;
            mpfr_t r;
            mpfr_init2(r, prec);
            mpfr_set(r, _mval, MPFR_RNDN);
            retVal = mpfr_get_d(r, MPFR_RNDN);
            mpfr_clear(r);
            return retVal;
        } else {
            mpfr_t r;
            mpfr_init2(r, 8);
            mpfr_set(r, _mval, MPFR_RNDN);
            retVal = mpfr_get_d(r, MPFR_RNDN);
            mpfr_clear(r);
            return retVal;
        }
    }

template <>
float Elementary<float>::FromMPFR(mpfr_t _mval) {
    double retVal = mpfr_get_d(_mval, MPFR_RNDN);

    if (retVal == 0) return 0.0;
    if (retVal != retVal) {
        return retVal;
    }
    
    if (mpfr_cmp_d(_mval, pow(2, -150)) <= 0 && mpfr_cmp_d(_mval, -pow(2, -150)) >= 0) {
        return 0;
    }

    long exp;
    double fr = mpfr_get_d_2exp(&exp, _mval, MPFR_RNDN);
    fr *= 2;
    exp--;
    
    if (mpfr_cmp_d(_mval, 0.0) > 0) {
        if (mpfr_cmp_d(_mval, 1.5 * pow(2, -149)) < 0) return pow(2, -149);
        if (mpfr_cmp_d(_mval, pow(2, -148)) < 0) return pow(2, -148);

    } else {
        if (mpfr_cmp_d(_mval, -1.5 * pow(2, -149)) > 0) return -pow(2, -149);
        if (mpfr_cmp_d(_mval, -pow(2, -148)) > 0) return -pow(2, -148);
    }
    
    if (exp >= -148 && exp <= -127) {
        int prec = 150 + exp;
        mpfr_t r;
        mpfr_init2(r, prec);
        mpfr_set(r, _mval, MPFR_RNDN);
        retVal = mpfr_get_d(r, MPFR_RNDN);
        mpfr_clear(r);
        return retVal;
    } else {
        mpfr_t r;
        mpfr_init2(r, 24);
        mpfr_set(r, _mval, MPFR_RNDN);
        retVal = mpfr_get_d(r, MPFR_RNDN);
        mpfr_clear(r);
        return retVal;
    }
}

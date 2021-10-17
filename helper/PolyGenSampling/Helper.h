#pragma once

union floatint{
  float f;
  unsigned int x;
};

union doubleint{
  double d;
  unsigned long long int x;
};

using namespace std;

template <class T>
class Helper {
    public :
    static inline double ConvertToDouble(T x);
    static inline uint32_t GetHexRep(T x);
    static inline void HexToValue(T& v, uint32_t h);
    static void CalculateInterval(T, double&, double&);
};

template <>
void Helper<float>::CalculateInterval(float x, double& lb, double& ub) {
    floatint xi;
    doubleint di;
    xi.f = x;
    double dx = x;
    // Take care of special cases:
    if (x == 0.0) {
        xi.x = 0x80000001;
        double lower = xi.f;
        lb = lower / 2;
        xi.x = 0x00000001;
        double upper = xi.f;
        ub = upper / 2;
        return;
    }
    
    if (x < 0.0) {
        if (xi.x == 0xFF7FFFFF) {
            double lower = -pow(2.0, 128.0);
            lb = (dx + lower) / 2;
        } else {
            xi.x++;
            double lower = xi.f;
            lb = (dx + lower) / 2;
            xi.x--;
        }
        
        xi.x--;
        double upper = xi.f;
        ub = (dx + upper) / 2;

        // Inclusive or exclusive?
        xi.f = x;
        if ((xi.x & 0x1) != 0) {
            di.d = lb;
            di.x--;
            lb = di.d;
            di.d = ub;
            di.x++;
            ub = di.d;
        }
        return;
    }
    
    // Otherwise x > 0.0
    xi.x--;
    double lower = xi.f;
    lb = (dx + lower) / 2;
    xi.x++;
    
    if (xi.x == 0x7F7FFFFF) {
        double upper = pow(2.0, 128.0);
        ub = (dx + upper) / 2;
    } else {
        xi.x++;
        double upper = xi.f;
        ub = (dx + upper) / 2;
    }
    
    // inclusive or exclusive?
    xi.f = x;
    if ((xi.x & 0x1) != 0) {
        di.d = lb;
        di.x++;
        lb = di.d;
        di.d = ub;
        di.x--;
        ub = di.d;
    }
}

template <>
inline double Helper<float>::ConvertToDouble(float x) {
    return x;
}

template <>
inline uint32_t Helper<float>::GetHexRep(float x) {
    return *((unsigned int *)&x);
}

template <>
inline void Helper<float>::HexToValue(float& v, uint32_t h) {
        floatint fi;
        fi.x = h;
        v = fi.f;
}

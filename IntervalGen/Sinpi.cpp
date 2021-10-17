#include "IntervalGen/IntGenForFloatROTwoApprox.h"
#include "luts.h"
#include "math.h"

bool IntervalGenerator2::ComputeSpecialCase(float x, double& res) {
    floatX fX;
    fX.f = x;
    unsigned long s = (fX.x & 0x80000000) ? 0x8000000000000000UL : 0x0UL;
    fX.x &= 0x7FFFFFFF;
    
    if (fX.x <= 872158519) {
      if (fX.x == 869073367) {
        res = 2.9990871297513876925222575664520263671875e-07;
        if (s) res = -res;
        return true;
      }
      
      res = (double)x * PI;
      return true;
    }
    
    if (fX.x >= 0x4b000000) {
        if (fX.x >= 0x7F800000) {
            res = 0.0/0.0;
            return true;
        }
        res = 0.0f;
        return true;
    }

    double xp = fX.f * 512;
    unsigned N = (unsigned)xp;
    unsigned N2 = N & 0xFF;
    unsigned I = N >> 8;
    double R;
    
    if (I & 0x1) {
      N2 = 255 - N2;
      R = (N + 1) * 0.001953125 - fX.f;
    } else R = fX.f - N * 0.001953125;
    
    if (I & 0x2) s ^= 0x8000000000000000;
    
    if ((double)I == fX.f * 2.0) {
      I &= 0x3;
      
      if (I == 0) {
        res = 0.0;
        return true;
      }
      
      if (I == 1) {
        res = s ? -1.0 : 1.0;
        return true;
      }
      
      if (I == 2) {
        res = 0.0;
        return true;
      }
      
      if (I == 3) {
        res = s ? -1.0 : 1.0;
        return true;
      }
    }
    
    return false;
}



double IntervalGenerator2::RangeReduction(float x) {
    floatX fX;
    fX.f = x;
    fX.x &= 0x7FFFFFFF;
    
    double xp = fX.f * 512;
    unsigned N = (unsigned)xp;
    unsigned N2 = N & 0xFF;
    unsigned I = N >> 8;
    double R;
    
    if (I & 0x1) {
        N2 = 255 - N2;
        R = (N + 1) * 0.001953125 - fX.f;
    } else R = fX.f - N * 0.001953125;
    
    return R;
}

double IntervalGenerator2::OutputCompensation(double x,
                                              double sinpip,
                                              double cospip) {
    floatX fX;
    fX.f = x;
    unsigned long s = (fX.x & 0x80000000) == 0 ? 0x0 : 0x8000000000000000;
    fX.x &= 0x7FFFFFFF;
    
    double xp = fX.f * 512;
    unsigned N = (unsigned)xp;
    unsigned N2 = N & 0xFF;
    unsigned I = N >> 8;
    double R;
    
    if (I & 0x1) {
        N2 = 255 - N2;
        R = (N + 1) * 0.001953125 - fX.f;
    } else R = fX.f - N * 0.001953125;
    
    if (I & 0x2) s ^= 0x8000000000000000;
    
    doubleX dx;
    
    dx.d = cospiMBy512[N2] * sinpip + sinpiMBy512[N2] * cospip;
    dx.x ^= s;
    
    return dx.d;
}

void IntervalGenerator2::
SpecCaseRedInt(float x,
               double sinhLbGuess, bool& sinhLbSpec, double& sinhLB,
               double sinhUbGuess, bool& sinhUbSpec, double& sinhUB,
               double coshLbGuess, bool& coshLbSpec, double& coshLB,
               double coshUbGuess, bool& coshUbSpec, double& coshUB) {
    return;
}

bool IntervalGenerator2::GuessInitialLbUb(float x,
                                          double totalLB, double totalUB,
                                          double R,
                                          double& sinpiLB, double& sinpiUB,
                                          double& cospiLB, double& cospiUB) {
    doubleX dx, dx1, dx2;
    floatX fX;
    fX.f = x;
    unsigned long s = (fX.x & 0x80000000) == 0 ? 0x0 : 0x8000000000000000;
    fX.x &= 0x7FFFFFFF;
    
    double xp = fX.f * 512;
    unsigned long N = (unsigned)xp;
    unsigned long N2 = N & 0xFF;
    unsigned long I = N >> 8;
    
    if (I & 0x1) {
        N2 = 255 - N2;
    }
    
    if (I & 0x2) s ^= 0x8000000000000000;
  
  // Take sign out of the equation.
  if (s) {
    double temp = totalLB;
    totalLB = -totalUB;
    totalUB = -temp;
  }

    double cospiM = cospiMBy512[N2];
    double sinpiM = sinpiMBy512[N2];
    double SINPIR = sin(R * PI);
    double COSPIR = cos(R * PI);
    
    double M1 = totalLB / (cospiM * SINPIR + sinpiM * COSPIR);
    double M2 = totalUB / (cospiM * SINPIR + sinpiM * COSPIR);

    if (cospiM == 0) {
        sinpiLB = -1.0e300;
        sinpiUB = 1.0e300;
    } else if (SINPIR == 0) {
        sinpiLB = 0;
        sinpiUB = 0;
    } else {
        sinpiLB = SINPIR * M1;
        sinpiUB = SINPIR * M2;
    }

    if (sinpiM == 0) {
        cospiLB = -1.0e300;
        cospiUB = 1.0e300;
    } else if (COSPIR == 0) {
        cospiLB = 0;
        cospiUB = 0;
    } else {
        cospiLB = COSPIR * M1;
        cospiUB = COSPIR * M2;
    }

    if (cospiM * SINPIR + sinpiM * COSPIR == 0) {
        return true;
    }
    
    // If the signs are the same, we have to restrict sinpiLB and cospiLB, then
    // sinpiUB and cospiUB
    
    // Make sure totalLB and totalUB is positive. If everything went well, it
    // should be the case that totalLB and totalUB are neither negative or zero
    if (totalLB <= 0 || totalUB <= 0 ) {
        printf("Uh oh. Something went wrong when computing reduced interval.");
        printf("totalLB or totalUB is <= 0. Should not happen\n");
        printf("x        = %.100e (%x)\n", x, *(unsigned *)&x);
        printf("R        = %.100e (%lx)\n", R, *(unsigned long*)&R);
        printf("s        = %lx\n", s);
        printf("totalLB  = %.100e\n", totalLB);
        printf("totalUB  = %.100e\n", totalUB);
        exit(0);
    }
    
    // Reconstruct sinpi(x) using sinpiHM * cospiLB + cospiHM * sinpiLB and make
    // sure that sinpiLB and cospiLB makes larger than totalLB.
    double recon = sinpiM * cospiLB + cospiM * sinpiLB;

  while (recon < totalLB) {
    if (sinpiM != 0 && cospiLB != 0) {
      dx.d = cospiLB;
      if (dx.d >= 0) dx.x += 1000000;
      else dx.x -= 1000000;
      cospiLB = dx.d;
    }
    if (cospiM != 0 && sinpiLB != 0) {
      dx.d = sinpiLB;
      if (dx.d >= 0) dx.x += 1000000;
      else dx.x -= 1000000;
      sinpiLB = dx.d;
    }
    recon = sinpiM * cospiLB + cospiM * sinpiLB;
  }
    
    // Reconstruct sinpi(x) using sinpiHM * cospiLB + cospiHM * sinpiLB and make
    // sure that we find the smallest sinpiLB and cospiLB boundary.
  unsigned long step = 0x100000000000;
  while (step > 0) {
    dx1.d = cospiLB;
    dx2.d = sinpiLB;
    
    if (sinpiM != 0 && cospiLB != 0) {
      if (dx1.d >= 0) dx1.x -= step;
      else dx1.x += step;
    }
    
    if (cospiM != 0 && sinpiLB != 0) {
      if (dx2.d >= 0) dx2.x -= step;
      else dx2.x += step;
    }
    
    double recon = sinpiM * dx1.d + cospiM * dx2.d;
    
    if (recon >= totalLB) {
      cospiLB = dx1.d;
      sinpiLB = dx2.d;
    } else if (step > 0) {
      step /= 2;
    }
  }
    
    // Reconstruct sinpi(x) using sinpiHM * cospiLB + cospiHM * sinpiLB and make
    // sure that sinpiLB and cospiLB makes smaller than totalUB.
    recon = sinpiM * cospiUB + cospiM * sinpiUB;

  while (recon > totalUB) {
    if (sinpiM != 0 && cospiUB != 0) {
      dx.d = cospiUB;
      if (dx.d >= 0) dx.x -= 1000000;
      else dx.x += 1000000;
      cospiUB = dx.d;
    }
    if (cospiM != 0 && sinpiUB != 0) {
      dx.d = sinpiUB;
      if (dx.d >= 0) dx.x -= 1000000;
      else dx.x += 1000000;
      sinpiUB = dx.d;
    }
    recon = sinpiM * cospiUB + cospiM * sinpiUB;
  }
    
    // Reconstruct sinpi(x) using sinpiHM * cospiUB + cospiHM * sinpiUB and make
    // sure that we find the largest sinpiUB and cospiUB boundary.
  step = 0x100000000000;
  while (step > 0) {
    dx1.d = cospiUB;
    dx2.d = sinpiUB;
    
    if (sinpiM != 0 && cospiUB != 0) {
      if (dx1.d >= 0) dx1.x += step;
      else dx1.x -= step;
    }
    
    if (cospiM != 0 && sinpiUB != 0) {
      if (dx2.d >= 0) dx2.x += step;
      else dx2.x -= step;
    }
    
    double recon = sinpiM * dx1.d + cospiM * dx2.d;
    
    if (recon <= totalUB) {
      cospiUB = dx1.d;
      sinpiUB = dx2.d;
    } else if (step > 0) {
      step /= 2;
    }
  }
    return true;
}

int main(int argc, char** argv) {
    
    if (argc != 4) {
        printf("Usage: %s <reduced sinpi file> <reduced cospi file> <oracle file>\n", argv[0]);
        exit(0);
    }
    
    IntervalGenerator2 SinpiIntGen;
    SinpiIntGen.CreateReducedIntervalFile(0x0, 0x40000001llu, argv[1], argv[2], argv[3]);
    
    return 0;
}

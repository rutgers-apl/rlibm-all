#include "IntervalGen/IntGenForFloatROTwoApprox.h"
#include "luts.h"
#include "math.h"

bool IntervalGenerator2::ComputeSpecialCase(float x, double& res) {
   floatX fX;
   fX.f = x;
   fX.x &= 0x7FFFFFFF;

   if (fX.x <= 950204803) {
     if (fX.x == 0) {
       res = 1.0;
       return true;
     }

     res = 0.99999998509883880615234375;
     return true;
   }
   
   if (fX.x >= 0x4b000000) {
     if (fX.x >= 0x7F800000) {
       res = 0.0 / 0.0;
       return true;
     }
     
     if (fX.x >= 0x4b800000) {
       res = 1.0;
       return true;
     }

     // If x >= 2^23, then if x is even, then 1.0f
     if ((fX.x & 0x1) == 0) {
       res = 1.0;
       return true;
     }
     
     // Otherwise, then -1.0f
     res = -1.0;
     return true;
   }

   double xp = fX.f * 512.0;
   
   unsigned N = (unsigned)xp;
   unsigned N2 = N & 0xFF;
   unsigned I = (N >> 8) + 1;
   unsigned I2 = (I - 1) & 0x3;
   double R;
   unsigned s = (I & 0x2) ? 0x80000000 : 0;
   
   if (I & 1) {
     if (N2 == 0) R = fX.f - N * 0.001953125;
     else R = (N + 1) * 0.001953125 - fX.f;
   } else {
     R = fX.f - N * 0.001953125;
   }

   if ((double)(I - 1) == fX.f * 2.0) {
     if (I2 == 0) {
       res = 1.0;
       return true;
     } else if (I2 == 1) {
       res = 0.0;
       return true;
     } else if (I2 == 2) {
       res = -1.0;
       return true;
     } else if (I2 == 3) {
       res = 0.0;
       return true;
     }
   }
     
   return false;
}

double IntervalGenerator2::RangeReduction(float x) {
    floatX fX;
    fX.f = x;
    fX.x &= 0x7FFFFFFF;
    
    // Range Reduction
    double xp = fX.f * 512.0;
    unsigned N = (unsigned)xp;
    unsigned N2 = N & 0xFF;
    unsigned I = (N >> 8) + 1;
    double R, cospiM, sinpiM;
    unsigned sign = (I & 0x2) ? 0x80000000 : 0;
    
    if (I & 1) {
      if (N2 == 0) {
          R = fX.f - N * 0.001953125;
      }
      else {
          N2++;
          R = (N + 1) * 0.001953125 - fX.f;
      }
    } else {
      R = fX.f - N * 0.001953125;
    }
    
    return R;
}

double IntervalGenerator2::OutputCompensation(double x,
                                              double sinpip,
                                              double cospip) {
    floatX fX;
    fX.f = x;
    fX.x &= 0x7FFFFFFF;
    
    // Range Reduction
    double xp = fX.f * 512.0;
    unsigned N = (unsigned)xp;
    unsigned N2 = N & 0xFF;
    unsigned I = (N >> 8) + 1;
    double R, cospiM, sinpiM;
    unsigned long sign = (I & 0x2) ? 0x8000000000000000 : 0x0;
    
    if (I & 1) {
      if (N2 == 0) {
        R = fX.f - N * 0.001953125;
        cospiM = 1.0;
        sinpiM = 0.0;
      }
      else {
        N2++;
        R = (N + 1) * 0.001953125 - fX.f;
        cospiM = sinpiMBy512[256 - N2];
        sinpiM = cospiMBy512[256 - N2];
      }
    } else {
      R = fX.f - N * 0.001953125;
      cospiM = sinpiMBy512[N2];
      sinpiM = cospiMBy512[N2];
    }
    
    doubleX dx;
    
    dx.d = cospiM * cospip + sinpiM * sinpip;
    dx.x ^= sign;
    return dx.d;
}

void IntervalGenerator2::
SpecCaseRedInt(float x,
               double sinpiLbGuess, bool& sinpiLbSpec, double& sinpiLbSpecVal,
               double sinpiUbGuess, bool& sinpiUbSpec, double& sinpiUbSpecVal,
               double cospiLbGuess, bool& cospiLbSpec, double& cospiLbSpecVal,
               double cospiUbGuess, bool& cospiUbSpec, double& cospiUbSpecVal) {
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
    fX.x &= 0x7FFFFFFF;
    
    // Range Reduction
    double xp = fX.f * 512.0;
    unsigned N = (unsigned)xp;
    unsigned N2 = N & 0xFF;
    unsigned I = (N >> 8) + 1;
    double cospiM, sinpiM;
    unsigned long sign = (I & 0x2) ? 0x8000000000000000 : 0;
  
  // Take sign out of the equation.
  if (sign) {
    double temp = totalLB;
    totalLB = -totalUB;
    totalUB = -temp;
  }
    
    if (I & 1) {
        if (N2 == 0) {
            cospiM = 1.0;
            sinpiM = 0.0;
        }
        else {
            N2++;
            cospiM = sinpiMBy512[256 - N2];
            sinpiM = cospiMBy512[256 - N2];
        }
    } else {
        cospiM = sinpiMBy512[N2];
        sinpiM = cospiMBy512[N2];
    }

    double cospiR = cos(R * PI);
    double sinpiR = sin(R * PI);
    double M1 = totalLB / (cospiM * cospiR + sinpiM * sinpiR);
    double M2 = totalUB / (cospiM * cospiR + sinpiM * sinpiR);
    
    if (cospiM == 0) {
        cospiLB = -1.0e300;
        cospiUB = 1.0e300;
    } else if (cospiR == 0) {
        cospiLB = 0.0;
        cospiUB = 0.0;
    } else {
        cospiLB = cospiR * M1;
        cospiUB = cospiR * M2;
    }
    
    if (sinpiM == 0) {
        sinpiLB = -1.0e300;
        sinpiUB = 1.0e300;
    } else if (sinpiR == 0) {
        sinpiLB = 0.0;
        sinpiUB = 0.0;
    } else {
        sinpiLB = sinpiR * M1;
        sinpiUB = sinpiR * M2;
    }

    if (cospiM * cospiR + sinpiM * sinpiR == 0) {
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
        printf("sign     = %lx\n", sign);
        printf("totalLB  = %.100e\n", totalLB);
        printf("totalUB  = %.100e\n", totalUB);
        exit(0);
    }
      
    // Reconstruct cospi(x) using sinpiHM * sinpiLB + cospiHM * cospiLB and make
    // sure that sinpiLB and cospiLB makes larger than totalLB.
    double recon = sinpiM * sinpiLB + cospiM * cospiLB;

  while (recon < totalLB) {
    //printf("hm1\n");
    if (cospiM != 0 && cospiLB != 0) {
      dx.d = cospiLB;
      if (dx.d >= 0) dx.x += 1000000;
      else dx.x -= 1000000;
      cospiLB = dx.d;
    }
    if (sinpiM != 0 && sinpiLB != 0) {
      dx.d = sinpiLB;
      if (dx.d >= 0) dx.x += 1000000;
      else dx.x -= 1000000;
      sinpiLB = dx.d;
    }
    recon = sinpiM * sinpiLB + cospiM * cospiLB;
  }
      
    // Reconstruct cospi(x) using sinpiHM * sinpiLB + cospiHM * cospiLB and make
    // sure that we find the smallest sinpiLB and cospiLB boundary.
  unsigned long step = 0x100000000000;
  while (step > 0) {
    //printf("hm2\n");
    dx1.d = cospiLB;
    dx2.d = sinpiLB;
    
    if (cospiM != 0 && cospiLB != 0) {
      if (dx1.d >= 0) dx1.x -= step;
      else dx1.x += step;
    }
    
    if (sinpiM != 0 && sinpiLB != 0) {
      if (dx2.d >= 0) dx2.x -= step;
      else dx2.x += step;
    }
    
    double recon = sinpiM * dx2.d + cospiM * dx1.d;
    
    if (recon >= totalLB) {
      cospiLB = dx1.d;
      sinpiLB = dx2.d;
    } else if (step > 0) {
      step /= 2;
    }
  }

    // Reconstruct cospi(x) using sinpiM * sinpiUB + cospiM * cospiUB and make
    // sure that sinpiLB and cospiLB makes smaller than totalUB.
    recon = sinpiM * sinpiUB + cospiM * cospiUB;

  while (recon > totalUB) {
    //printf("hm3\n");
    if (cospiM != 0 && cospiUB != 0) {
      dx.d = cospiUB;
      if (dx.d >= 0) dx.x -= 1000000;
      else dx.x += 1000000;
      cospiUB = dx.d;
    }
    if (sinpiM != 0 && sinpiUB != 0) {
      dx.d = sinpiUB;
      if (dx.d >= 0) dx.x -= 1000000;
      else dx.x += 1000000;
      sinpiUB = dx.d;
    }
    recon = sinpiM * sinpiUB + cospiM * cospiUB;
  }
      
    // Reconstruct sinpi(x) using sinpiHM * cospiUB + cospiHM * sinpiUB and make
    // sure that we find the largest sinpiUB and cospiUB boundary.
    step = 0x100000000000;
  while (step > 0) {
    dx1.d = cospiUB;
    dx2.d = sinpiUB;
    
    if (cospiM != 0 && cospiUB != 0) {
      if (dx1.d >= 0) dx1.x += step;
      else dx1.x -= step;
    }
    
    if (sinpiM != 0 && sinpiUB != 0) {
      if (dx2.d >= 0) dx2.x += step;
      else dx2.x -= step;
    }
    
    double recon = sinpiM * dx2.d + cospiM * dx1.d;
    
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

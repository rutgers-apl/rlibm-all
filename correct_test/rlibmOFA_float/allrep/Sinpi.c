#define __MPFR_ELEM__ mpfr_sin
#define	__ELEM__ rlibm34_sinpi
#include "LibTestHelperPi.h"

int IsSpecialCase(float x, double* specCaseRes) {
  double reduced = fmod(x, 2.0);
  if (reduced == -0.5) {
    *specCaseRes = -1.0;
    return 1;
  }
  else if (reduced == -1.0) {
    *specCaseRes = 0.0;
    return 1;
  }
  else if (reduced == -1.5) {
    *specCaseRes = 1.0;
    return 1;
  }
  else if (reduced == 0.0) {
    *specCaseRes = 0.0;
    return 1;
  }
  else if (reduced == 0.5) {
    *specCaseRes = 1.0;
    return 1;
  }
  else if (reduced == 1.0) {
    *specCaseRes = 0.0;
    return 1;
  }
  else if (reduced == 1.5) {
    *specCaseRes = -1.0;
    return 1;
  }
  
  return 0;
}

int main(int argc, char** argv) {
    RunTest(argv[1], "Sinpi");
    return 0;
}

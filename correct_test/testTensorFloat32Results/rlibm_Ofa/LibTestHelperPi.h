#define _GNU_SOURCE
#include <stdio.h>
#include "float34RO_math.h"
#include "rounding.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "math.h"
#include "mpfr.h"

mpfr_t mval;
int IsSpecialCase(float, double*);

mpfr_rnd_t rnd_modes[5] = {MPFR_RNDN, MPFR_RNDD, MPFR_RNDU, MPFR_RNDZ, MPFR_RNDNA};
char* rnd_modes_string[5] = {"RNE", "RNN", "RNP", "RNZ", "RNA"};
enum RoundMode my_rnd_modes[5] = {RNE, RNN, RNP, RNZ, RNA};

double MpfrResult(float x, int* sticky) {
  double specCaseRes;
  if (IsSpecialCase(x, &specCaseRes)) {
    *sticky = 0;
    return specCaseRes;
  }
  
  double reduced = fmod(x, 2.0);
  mpfr_const_pi(mval, MPFR_RNDZ);
  mpfr_mul_d(mval, mval, reduced, MPFR_RNDZ);
  
  // Don't need to track exact, because it's guaranteed to be not exact as long
  // as the input is not a special case input.
  __MPFR_ELEM__(mval, mval, MPFR_RNDZ);
  *sticky = 1;
  return mpfr_get_d(mval, MPFR_RNDZ);
}

void RunTestForExponent() {
  unsigned long wrongCounts[5];
  for (int i = 0; i < 5; i++) wrongCounts[i] = 0;
  mpfr_init2(mval, 500);
  
  floatX fx;
    
  for (unsigned long count = 0x0; count < 0x80000; count++) {
    int sticky = 0;
    fx.x = (count << 13);
    double res = __ELEM__(fx.f);
    double orc = MpfrResult(fx.f, &sticky);
    
    for (int rnd_index = 0; rnd_index < 5; rnd_index++) {
      enum RoundMode rmode = my_rnd_modes[rnd_index];
      float oracleRes = RoundDoubleToF8NWithSticky(orc, 19, rmode, sticky);
      float roundedRes = RoundDoubleToF8N(res, 19, rmode);
      
      if (oracleRes != oracleRes && roundedRes != roundedRes) continue;
      if (oracleRes != roundedRes) {
        wrongCounts[rnd_index]++;
        
        if (wrongCounts[rnd_index] <= 5) {
          printf("count  = %lu\n", count);
          printf("rnd    = %s\n", rnd_modes_string[rnd_index]);
          printf("x      = %.50e\n", fx.f);
          printf("oracle = %.50e\n", oracleRes);
          printf("res    = %.100e\n", res);
          printf("res    = %lx\n", *(unsigned long*)&res);
          printf("test   = %.50e\n\n", roundedRes);
          printf("res    = %x\n", *(unsigned*)&roundedRes);
        }
      }
    }
  }
  
  for (int i = 0; i < 5; i++) {
    if (wrongCounts[i] == 0) printf("\033[0;32mo\033[0m");
    else printf("\033[0;31mx\033[0m");
    if (i < 4) printf("   ");
  }
  
  mpfr_clear(mval);
}

void RunTest(char* logFile) {
  RunTestForExponent();
}

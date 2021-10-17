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

mpfr_t mval, mval200;
int default_emin, default_emax;

mpfr_rnd_t rnd_modes[5] = {MPFR_RNDN, MPFR_RNDD, MPFR_RNDU, MPFR_RNDZ, MPFR_RNDNA};
char* rnd_modes_string[5] = {"RNE", "RNN", "RNP", "RNZ", "RNA"};
enum RoundMode my_rnd_modes[5] = {RNE, RNN, RNP, RNZ, RNA};

double MpfrResult(float x, mpfr_rnd_t rnd) {
  if (rnd == MPFR_RNDNA) {
    unsigned sticky = 0;
    mpfr_set_emin(default_emin);
    mpfr_set_emax(default_emax);
    int exact = mpfr_set_d(mval200, x, MPFR_RNDZ);
    exact = __MPFR_ELEM__(mval200, mval200, MPFR_RNDZ);
    if (exact != 0) sticky = 1;
    double result = mpfr_get_d(mval200, MPFR_RNDZ);
    if (mpfr_cmp_d(mval200, result) != 0) sticky = 1;
    return RoundDoubleToF8NWithSticky(result, 19, RNA, sticky);
  }
  
  mpfr_set_emin(-135);
  mpfr_set_emax(128);
  int exact = mpfr_set_d(mval, x, MPFR_RNDZ);
  exact = mpfr_subnormalize(mval, exact, MPFR_RNDZ);
  
  exact = __MPFR_ELEM__(mval, mval, rnd);
  exact = mpfr_subnormalize(mval, exact, rnd);
  double result = mpfr_get_d(mval, rnd);
  
  mpfr_set_emin(default_emin);
  mpfr_set_emax(default_emax);
  
  return result;
}

void RunTestForExponent() {
  unsigned long wrongCounts[5];
  for (int i = 0; i < 5; i++) wrongCounts[i] = 0;
  
  default_emin = mpfr_get_emin();
  default_emax = mpfr_get_emax();
      
  mpfr_init2(mval, 11);
  mpfr_init2(mval200, 12);
  
  floatX fx;
  
  for (unsigned long count = 0x0; count < 0x80000; count++) {
    fx.x = (count << 13);
    double res = __ELEM__(fx.f);
    
    for (int rnd_index = 0; rnd_index < 5; rnd_index++) {
      mpfr_rnd_t rnd = rnd_modes[rnd_index];
      double oracleResult = MpfrResult(fx.f, rnd);
      double roundedRes = RoundDoubleToF8N(res, 19, my_rnd_modes[rnd_index]);
      
      if (oracleResult != oracleResult && roundedRes != roundedRes) continue;
      if (oracleResult != roundedRes) {
        wrongCounts[rnd_index]++;
        
      }
    }
  }
  
  for (int i = 0; i < 5; i++) {
    if (wrongCounts[i] == 0) printf("\033[0;32mo\033[0m");
    else printf("\033[0;31mx\033[0m");
    if (i < 4) printf("   ");
  }
  
  mpfr_clear(mval);
  mpfr_clear(mval200);
}

void RunTest(char* logFile) {
  RunTestForExponent();
}

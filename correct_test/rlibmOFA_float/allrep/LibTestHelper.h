#define _GNU_SOURCE
#include <stdio.h>
#include "float34RO_math.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "math.h"
#include "mpfr.h"
#include "rounding.h"

#define MAX_STRIDE 19u

mpfr_t mval, mval200;
int default_emin, default_emax, new_emin, new_emax;

mpfr_rnd_t rnd_modes[5] = {MPFR_RNDN, MPFR_RNDD, MPFR_RNDU, MPFR_RNDZ, MPFR_RNDNA};
char* rnd_modes_string[5] = {"RNE", "RNN", "RNP", "RNZ", "RNA"};
enum RoundMode my_rnd_modes[5] = {RNE, RNN, RNP, RNZ, RNA};

float MpfrResult(float x, int numExpBit, unsigned bitlen, mpfr_rnd_t rnd) {
  if (rnd == MPFR_RNDNA) {
    unsigned sticky = 0;
    mpfr_set_emin(default_emin);
    mpfr_set_emax(default_emax);
    int exact = mpfr_set_d(mval200, x, MPFR_RNDZ);
    exact = __MPFR_ELEM__(mval200, mval200, MPFR_RNDZ);
    if (exact != 0) sticky = 1;
    double result = mpfr_get_d(mval200, MPFR_RNDZ);
    if (mpfr_cmp_d(mval200, result) != 0) sticky = 1;
    return RoundDoubleToFEN(result, numExpBit, bitlen, RNA, sticky);
  }
  
  mpfr_set_emin(new_emin);
  mpfr_set_emax(new_emax);
  int exact = mpfr_set_d(mval, x, MPFR_RNDZ);
  exact = mpfr_subnormalize(mval, exact, MPFR_RNDZ);

  exact = __MPFR_ELEM__(mval, mval, rnd);
  exact = mpfr_subnormalize(mval, exact, rnd);
  float result = mpfr_get_flt(mval, rnd);

  return result;
}

unsigned long RunTestForExponent(int numExpBit, FILE* f, char* FuncName) {
  unsigned long totalWrongResult = 0;

  for (unsigned bitlen = numExpBit + 2; bitlen <= numExpBit + 24; bitlen++) {
    unsigned long wrongResult = 0;
    int bias = (1 << (numExpBit - 1)) - 1;
    int emax = (1 << numExpBit) - 1 - bias;
    
    default_emin = mpfr_get_emin();
    default_emax = mpfr_get_emax();
    new_emin = 1 - bias - ((int)bitlen - 1 - numExpBit) + 1;
    new_emax = emax;
    
    mpfr_init2(mval, bitlen - numExpBit);
    mpfr_init2(mval200, bitlen - numExpBit + 1);
    
    // Run at most 64K at a time. That's still 5 * 22 * 7 * 64K = 50M tests
    unsigned long upperlimit = 1lu << (unsigned long)bitlen;
    unsigned long start = bitlen <= MAX_STRIDE ?
                          0 : 1lu << (bitlen - MAX_STRIDE) - 1;
    unsigned step = (bitlen > MAX_STRIDE) ? (1u << (bitlen - MAX_STRIDE)) : 1u;
    for (unsigned long count = start; count < upperlimit; count += step) {
      float x = ConvertBinToFP((unsigned)count, numExpBit, bitlen);
      double res = __ELEM__(x);
      
      for (int rnd_index = 0; rnd_index < 5; rnd_index++) {
        float oracleResult = MpfrResult(x, numExpBit, bitlen, rnd_modes[rnd_index]);
        float roundedRes = RoundDoubleToFEN(res, numExpBit, bitlen,
                                             my_rnd_modes[rnd_index], 0);
	
        if (oracleResult != oracleResult && roundedRes != roundedRes) continue;
        if (oracleResult != roundedRes && wrongResult < 10) wrongResult++;
      }
    }
    
    if (wrongResult == 0)
      fprintf(f, "Testing FP%u(%d exp bit): \033[0;32mcheck\033[0m    \r", bitlen, numExpBit);
    else
      fprintf(f, "Testing FP%u(%d exp bit): \033[0;31mincorrect\033[0m\r", bitlen, numExpBit);
    fflush(f);
    totalWrongResult += wrongResult;
    
    mpfr_clear(mval);
    mpfr_clear(mval200);
  }
  
  if (totalWrongResult == 0)
    fprintf(f, "FP reps with %d exp bits: \033[0;32mcheck\033[0m    \n", numExpBit);
  else
    fprintf(f, "FP reps with %d exp bits: incorrect\n", numExpBit);
  
  if (totalWrongResult == 0)
    printf("FP reps with %d exp bits: \033[0;32mcheck\033[0m    \n", numExpBit);
  else
    printf("FP reps with %d exp bits: incorrect\n", numExpBit);

  return totalWrongResult;
}

void RunTest(char* logFile, char* FuncName) {
  FILE* f = fopen(logFile, "w");
  fprintf(f, "Function: %s\n", FuncName);
  printf("Function: %s\n", FuncName);
  for (int i = 2; i <= 8; i++) {
    RunTestForExponent(i, f, FuncName);
  }
  fclose(f);
}

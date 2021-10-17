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

#define MAX_STRIDE 17u

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

unsigned long RunTestForExponent(int numExpBit, FILE* f, char* FuncName) {
  mpfr_init2(mval, 500);
  unsigned long totalWrongResult = 0;

  for (unsigned bitlen = numExpBit + 2; bitlen <= numExpBit + 24; bitlen++) {
    unsigned long wrongResult = 0;
    int bias = (1 << (numExpBit - 1)) - 1;
    int emax = (1 << numExpBit) - 1 - bias;
    
    // Run at most 64K at a time. That's still 5 * 22 * 7 * 64K = 50M tests
    unsigned long upperlimit = 1lu << (unsigned long)bitlen;
    unsigned long start = bitlen <= MAX_STRIDE ?
                          0 : 1lu << (bitlen - MAX_STRIDE - 1);
    unsigned step = (bitlen > MAX_STRIDE) ? (1u << (bitlen - MAX_STRIDE)) : 1u;
    for (unsigned long count = start; count < upperlimit; count += step) {
      float x = ConvertBinToFP((unsigned)count, numExpBit, bitlen);
      double res = __ELEM__(x);
      int sticky;
      double orc = MpfrResult(x, &sticky);
      
      for (int rnd_index = 0; rnd_index < 5; rnd_index++) {
        float oracleResult = RoundDoubleToFEN(orc, numExpBit, bitlen, my_rnd_modes[rnd_index], sticky);
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
  }
  
  if (totalWrongResult == 0)
    fprintf(f, "FP reps with %d exp bits: \033[0;32mcheck\033[0m    \n", numExpBit);
  else
    fprintf(f, "FP reps with %d exp bits: incorrect\n", numExpBit);
  
  if (totalWrongResult == 0)
    printf("FP reps with %d exp bits: \033[0;32mcheck\033[0m    \n", numExpBit);
  else
    printf("FP reps with %d exp bits: incorrect\n", numExpBit);
  
  mpfr_clear(mval);

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

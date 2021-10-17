#define _GNU_SOURCE
#include <stdio.h>
#include "crlibm.h"
#include "float34RO_math.h"
#include "rounding.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char* rnd_modes_string[5] = {"RNE", "RNN", "RNP", "RNZ", "RNA"};
enum RoundMode my_rnd_modes[5] = {RNE, RNN, RNP, RNZ, RNA};

void RunTestForExponent() {
  unsigned long wrongCounts[5];
  for (int i = 0; i < 5; i++) wrongCounts[i] = 0;
  
  floatX fx;
  
  for (unsigned long count = 0x0; count < 0x80000; count++) {
    fx.x = (count << 13);
    double orc = __GEN_ELEM__(fx.f);
    double res = __ELEM__(fx.f);
    
    for (int rnd_index = 0; rnd_index < 5; rnd_index++) {
      double oracleResult = RoundDoubleToF8N(orc, 19, my_rnd_modes[rnd_index]);
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
  
}

void RunTest(char* logFile) {
  RunTestForExponent();
}

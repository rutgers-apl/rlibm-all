#define DIVISOR_RATIO 1000
#define DIVISOR_MAX 10000

#include "PolyGenSampling/PolyGenFromFile.h"

int main(int argc, char** argv) {
    
    // We want 3 additional command line arguments:
    if (argc != 4 && argc != 5) {
        printf("Usage : %s <interval file> <log file> <header file>\n", argv[0]);
        printf("Input : <interval file> - file containing reduced constrains\n");
        printf("Output: <log file> - where we print some logging information\n");
        printf("Output: <header file> - the file containing coefficients\n");
    }

    FILE* f = fopen(argv[1], "r");
    FILE* log = fopen(argv[2], "w");
    FILE* header = fopen(argv[3], "w");
    
    int minN = -1;
    if (argc == 5) minN = atoi(argv[4]);
    
    std::vector<int> power({1, 3, 5, 7, 9, 11, 13, 15});
    GeneratePiecewiseFunction(f, log, header, power, minN);
    
    fclose(f);
    fclose(log);
    fclose(header);


    return 0;
}

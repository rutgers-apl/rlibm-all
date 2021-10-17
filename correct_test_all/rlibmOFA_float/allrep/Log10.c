#define __MPFR_ELEM__ mpfr_log10
#define	__ELEM__ rlibm34_log10
#include "LibTestHelper.h"

int main(int argc, char** argv) {

    RunTest(argv[1], "Log10");
    return 0;
}

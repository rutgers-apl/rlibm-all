#define __MPFR_ELEM__ mpfr_exp
#define	__ELEM__ rlibm34_exp
#include "LibTestHelper.h"

int main(int argc, char** argv) {
    RunTest(argv[1], "Exp");
    return 0;
}

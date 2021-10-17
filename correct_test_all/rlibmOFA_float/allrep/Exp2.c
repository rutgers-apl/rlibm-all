#define __MPFR_ELEM__ mpfr_exp2
#define	__ELEM__ rlibm34_exp2
#include "LibTestHelper.h"

int main(int argc, char** argv) {

    RunTest(argv[1], "Exp2");
    return 0;
}

#define __MPFR_ELEM__ mpfr_sinh
#define	__ELEM__ rlibm34_sinh
#include "LibTestHelper.h"

int main(int argc, char** argv) {
    RunTest(argv[1], "Sinh");
    return 0;
}

#define __MPFR_ELEM__ mpfr_log
#define	__ELEM__ rlibm34_log
#include "LibTestHelper.h"

int main(int argc, char** argv) {

    RunTest(argv[1], "Log");
    return 0;
}

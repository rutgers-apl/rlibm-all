#define __MPFR_ELEM__ mpfr_log2
#define	__ELEM__ rlibm34_log2
#include "LibTestHelper.h"

int main(int argc, char** argv) {

    RunTest(argv[1], "Log2");
    return 0;
}

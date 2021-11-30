# RLIBM-ALL

RLIBM-ALL is a math library generator and collection of correctly
rounded elementary functions. A single implementation for an
elementary function produces correctly rounded results for all inputs
with multiple representations and rounding modes.

If you are more interested in the technical details of RLIBM-ALL, the
following resources  will be helful.

1. [The POPL 2022 paper on RLIBM-ALL][https://people.cs.rutgers.edu/~sn349/papers/rlibmall-popl-2022.pdf]
2. [The extended Rutgers DCS Technical Report DCS-TR-757 on RLIBM-ALL][https://arxiv.org/pdf/2108.06756.pdf]
3. [The RLIBM project page][https://people.cs.rutgers.edu/~sn349/rlibm/]

Currently, RLIBM-ALL supports a number of elementary functions for the
floating point representation.

## List of floating point functions supported by RLIBM-ALL
1. log(x), log2(x), log10(x)
2. exp(x), exp2(x), exp10(x)
3. sinh(x), cosh(x)
4. sinpi(x), cospi(x)

### List of floating point representations supported by RLIBM-ALL
* All floating point representations of up to a total of 32-bits, up to 8-bits of exponent, and up to 23-bits of mantissa. This includes, but is not limited to,
* 32-bit float
* bfloat16
* tensorfloat32
* and much more

### List of floating point rounding modes supported by RLIBM-ALL
* Round-to-nearest-tie-goes-to-even
* Round-to-nearest-tie-goes-away
* Round-towards-zero
* Round-towards-positive-infinity
* Round-towards-negative-infinity



# Getting started with RLIBM-ALL:
There are various pre-requisites for using RLIBM-ALL math library, testing it, or generating polynomials.
We describe the pre-requisites in each section. Alternatively, we have set up a docker image that contains the pre requisites and environment variables set up already. 

### Using Docker Image
1. Install docker if not already installed by following the installation documentation in this link: https://docs.docker.com/install/

2. Download the docker image

```
docker pull jpl169/popl2022artifact
```
* The docker image is roughly ~6GB in size

3. Run the docker image
	
```
sudo docker run -it jpl169/popl2022artifact
```

### Manual Installation
In each section (using math library, testing, generating polynomial) we list the pre-requisites and how to set up.




# How to build and use RLIBM-ALL math library

### Setup

1. Create an environment variable SOFTPOSITPATH that points to the directory of SoftPosit:
```
export SOFTPOSITPATH=<path-to-softposit-directory>
```
  
2. Build the math library
  1. If you want to build all the math libraries, simply use make rule from the root directory
```
cd <path-to-rlibm-all>
make
```

  2. If you want to build math libraries for just the floating point representation, you can use this make rule
```
cd <path-to-rlibm-all>
make float34ROmlibm
```

### USAGE
The math library will be located in the `lib` directory.
  * float34ROMathLib.a : math library for the floating point representation

The header files for each library is located in the include directory:
  * `float34RO_math.h` : header for the floating point math library

You can use our library in the code similar to how standard math library is used, except our function names start with "rlibm34_":
```
test.cpp:
#include "float34RO_math.h"
int main() {
  float result = rlibm34_cospi(1.5f);
  return 0;
}
```

To build the program, include the math library in the compilation command:
```
g++ test.cpp -I<path-to-rlibm-all>/include/ <path-to-rlibm-all>/lib/float34ROMathLib.a -lm -o test
```

To see a sample program that uses OurLibm, please look into the `sample` directory. It is a simple program that computes `e^0.005 / sinpi(0.75)`. The makefile shows how to link the library and the dependency. Currently, RLIBM-ALL uses some functions from the default math library for range reduction (i.e., to decompose a floating point value into the integral part and fractional part) so make sure to include `-lm` flag.





# Testing Correctness of RLIBM-ALL

### Setup
  
1. Build the math library
```
cd <path-to-rlibm-all>
make
```

### Testing

1. To test the correctness of RLIBM-ALL's floating point functions for some randomly distributed inputs, use the following command, 
```
./CorrTestRLibmAll.sh
```

* This script will take roughly 15 minutes. This script tests whether ourLibm produces the correctly rounded results for uniformly sampled FP inputs with different amount of exponent bits (and mantissa bits), for all standard rounding modes. If the testing is successful, you should see "check" in green text, for each elementary function and for representations with different exponent bits. Otherwise, it will print "incorrect" in red text, which signifies that the test has failed.

2. We also set up a test script to run this test for ALL possible FP inputs. However, this will take > 48 hours, even when run in parallel...
```
./CorrTestRLibmAll_Full.sh
```

3. To test the correctness of mainstream math libraries, run the bash script,
```
./CorrTestMlibs.sh
```

* This script will take roughly 15 minutes. This script tests whether different math libraries produce correctly rounded results. We uniformly sample inputs out of 4 billion float inputs. 

4.  We also set up a test script to run this test for ALL possible float inputs. However, this will take roughly 6 hours to complete.
```
./CorrTestMlibs_Full.sh
```


# Testing Performance of Various Math Libraries

### Prerequisite
To run the testing script to check for performance, we recommend to also install Intel compiler (icc) via [this site ](https://software.intel.com/content/www/us/en/develop/tools/oneapi/hpc-toolkit/download.html).

1. Select the appropriate operating system
2. Select "Web & Local" distribution option
3. Select Online installer
4. On the right hand side (gray background) if you scroll down, it will show the steps to install. 
  * If your OS is Linux base, then you might use the command:
```
wget https://registrationcenter-download.intel.com/akdlm/irc_nas/18211/l_HPCKit_p_2021.4.0.3347.sh
sudo bash l_HPCKit_p_2021.4.0.3347.sh
```

5. Follow the instruction. The installer will guide you through installing intel compiler.
  a. Make sure to install "Intel® oneAPI DPC++/C++ Compiler & Intel® C++ Compiler Classic." You can choose to not install any other components
  b. Make sure to remember the Installation directory
  c. If it shows you any warning about requiring the "Base toolkit" you can choose to ignore it.
    * The installation will take roughly 5~10 minutes.

6. Once installation is complete, run script to set variables:
```
cd <path to intel oneAPI directory>
. setvars.sh
```

### Setup

1. Create an environment variable ICCPATH that points to the directory of intel/oneapi directory. If you did not change the installation path while installing Intel compiler, then the path to Intel oneAPI directory will most likely end with "intel/oneapi":
```
export ICCPATH=<path to Intel oneAPI directory>
```

2. Build the math library
```
cd <path-to-rlibm-32>
make
```

### Testing
* To test the performance of glibc, intel, CR-LIBM, and RLIBM-ALL for the floating point functions, use the pre-assembled testing script:
```
./PerfTest.sh
```

* This script will take roughly 15 minutes. This script uniformly samples some inputs to compare the performance. Once the script terminates, you will see the following files:

1. SpeedupOverGlibc.pdf - This file shows the speedup of RLIBM-ALL against glibc math library
2. SpeedupOverIntel.pdf - This file shows the speedup of RLIBM-ALL against intel math library
3. SpeedupOverCrlibm.pdf - This file shows the speedup of RLIBM-ALL against CRLIBM
4. SpeedupOverRlibm32.pdf - This file shows the speedup of RLIBM-ALL against RLIBM-32

* If you're using docker, you can copy the pdf's from the container to your host machine using the following commands:
```
exit
sudo docker container ls -a  (Find the correct container id)
sudo docker cp <container id>:/home/POPL2022Artifact/SpeedupOverGlibc.pdf .
sudo docker cp <container id>:/home/POPL2022Artifact/SpeedupOverIntel.pdf .
sudo docker cp <container id>:/home/POPL2022Artifact/SpeedupOverCrlibm.pdf .
sudo docker cp <container id>:/home/POPL2022Artifact/SpeedupOverRlibm32.pdf .
```

* To go back into docker container, use the following commands:
```
sudo docker start <container id>
sudo docker attach <container id>
```



# How to Generate Polynomials

* In general, generating a polynomial that produces the correctly rounded results for a given domain of inputs consists of three steps:
1. Computing the oracle result (34-bit floating point repesentation with the round-to-odd rounding mode)
2. Computing the odd intervals and the reduced intervals
3. Generating the polynomials based on the reduced intervals


* The directory `smallGenerationTest` shows how to execute each of the three steps using the artifact. The source code for each step is organized into separate directories:
1. GenerateOracleFiles : Compute rno result and store into oracle_file
2. IntervalGen : Compute reduced intervals using oracle_file and store into interval_file
3. functiongen : Use interval_files to generate polynomials and generate a table of coefficients

We now describe what must be provided to perform each of the steps using the files in the smallGenerationTest directory. More details can be found in the comments of each file preluded with "TODO"

### Step 1: GenerateOracleFiles/Log2Small.c
* The function `ComputeOracleResult` must provide a way to compute the correctly rounded rno result of f(x) given any input. Currently, this function produces correctly rounded rno results for `log2(x)`.
* In the `main` function, the RunTestHelper must be provided with the domain of inputs using the bit-patterns of the 32-bit float representation. For example, `[0x3f800000, 0x40000000)` is equivalent to an input domain of `[1.0, 2.0)`
* To generate the oracle file, use the following command:
```
./Log2Small <file to store rno results>
```

### Step 2: IntervalGen/Log2Small.cpp
There are several things that must be provided to generate correctly generate reduced intervals. These functions need to be customized for the specific f(x) function. If a component is incorrect, it is common to see an infinite loop.
* `ComputeSpecialCase` function : Given an input "x", determine whether f(x) is a special case value. Specifically, it is important to correctly determine whether f(x) is infinity, NaN, or the odd interval is a singleton interval. If it is, store the correct result in "res" and return true. Otherwise, return false.
* `RangeReduction` function : The implementation of the range reduction function. If not using range reduction strategy, simply return "x"
* `OutputCompensation` function: The implementation of the output compensation function. If not using range reduction strategy, simply return "yp"
* `GuessInitialLbUb` function: To accurately compute the reduced interval, we need an initial point in the reduced interval. This initial point, when used with the output compensation function, must result in a value within the rounding interval. The initial point can be computed using the function that the polynomial is approximation. In most cases, that would be f(x) itself, unless the range reduction strategy performs function transformation (i.e. the range reduction strategy we use for log2(x)). Provide the initial guess into the variable "double initialGuess." 
- Note : If the initialGuess misses the rounding interval by a few ulps, don't worry too much. The bulk of the code in `GuessInitialLbUb` tries to wiggle around initialGuess to find a point that will result in the rounding interval.
* `SpecCaseRedInt` function : This function is for very special case, where you need special computation to compute the reduced interval. In other words, you can use "SpecCaseRedInt" to implement your own algorithm to identify the reduced intervals. If you leave it as it is, the program will use a naive method to identify the reduced intervals, which is sufficient most of the time.
* `main` function : Make sure to provide the input domain. This must match exactly with the domain provided during Step 1.
* To generate the reduced intervals, use the following command:
```
./Log2Small <file to store interval information> <name of file containing rno results>
```

### Step 3: functiongen/Log2Small.cpp 
* The "power" vector describes the shape of the polynomial. For example, `{1, 2, 3, 4, ... 8}` indicates that we want to create a polynomial of the form c_1 x + c_2 x^2 + ... + c_8 x^8. Depending on the function you want to approximate, you may want to change the shape of the polynomial. For example,
  - e^x : `{0, 1, 2, 3, 4, ...}`
  - sin(x) : `{1, 3, 5, ...}`
  - Note : functiongen will automatically try to generate the lowest degree polynomial, even if you specify much more terms in the vector.

* To generate the polynomials based on the generated reduced intervals, use the following command:
```
./Log2Small <file with interval info.> <log file output> <header file output> <size of piecewise polynomial in logscale, i.e., N creates 2^N polynomials>
```

* If the header file has values in the array, it means the polynomial was successfully generated. If the array is empty, then the polynomial was unsuccessful. You can check the log file to see what's going on.

* If you use `GenerationTest.sh` to automate the process for you, the header file will be located in `smallGenerationTest/include/float34RO_headers`. 

### Generated coefficients 
* Once all three steps are done, the <header file output> should contain an 2-D array. 
* Each array represents a polynomial in the piecewise polynomial. Each value in the array represents the coefficients.
* The coefficients corresponds to each of the terms specified in the "power" vector.

### Creating implementation
* Using the generated polynomial, you can come the range reduction function, output compensation function, and the special case functions to implement f(x)!
* The implementation of log2(x) for our small sample is in smallGenerationTest/source/log2small.c
* Edit this file accordingly

### Testing 
* Make sure that you edit the testing script in `smallGenerationTest/correct_test` as well.
* The testing script is in `smallGenerationTest/correct_test`. The main file to change is LibTestHelper.h. This script uses the generated oracle file to compare against the implementation. Make sure that we are iterating through the correct input domain. Otherwise, we may see unexpected results. 


### How we generated the functions for RLIBM-ALL
* The root directory has `GenerateOracleFiles`, `IntervalGen`, and `functiongen` by itself. 
* You can find the exact configuration we used to generate the polynomials. 
* Be aware that using these code directly will take several hours to generate polynomials.

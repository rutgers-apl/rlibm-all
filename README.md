# RLIBM-ALL

RLibm-All is both a library that provides correctly orunded results for all inputs for multiple representations and rounding modes as well as a collection of tools used to generate the correct polynomials. See the technical report at https://arxiv.org/abs/2108.06756 for more detail. The paper describing the techniques used for RLIBM-ALL will appear in POPL 2022.

More details on the RLIBM project is available on the RLIBM project page at https://people.cs.rutgers.edu/~sn349/rlibm/.

Currently, RLIbM-ALL supports a number of elementary functions for the floating point representation.

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
Currently, RLIBM-ALL uses some functions from the default math library for range reduction (i.e., to decompose a floating point value into the integral part and fractional part) so make sure to include `-lm` flag.~




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
$ ./CorrTestRLibmAll.sh
```

* This script will take roughly 15 minutes. This script tests whether ourLibm produces the correctly rounded results for uniformly sampled FP inputs with different amount of exponent bits (and mantissa bits), for all standard rounding modes. If the testing is successful, you should see "check" in green text, for each elementary function and for representations with different exponent bits. Otherwise, it will print "incorrect" in red text, which signifies that the test has failed.

2. We also set up a test script to run this test for ALL possible FP inputs. However, this will take > 48 hours, even when run in parallel...
```
$ ./CorrTestRLibmAll_Full.sh
```

3. To test the correctness of mainstream math libraries, run the bash script,
```
$ ./CorrTestMlibs.sh
```

* This script will take roughly 15 minutes. This script tests whether different math libraries produce correctly rounded results. We uniformly sample inputs out of 4 billion float inputs. 

4.  We also set up a test script to run this test for ALL possible float inputs. However, this will take roughly 6 hours to complete.
```
$ ./CorrTestMlibs_Full.sh
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
$ ./PerfTest.sh
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
$ sudo docker start <container id>
$ sudo docker attach <container id>
```
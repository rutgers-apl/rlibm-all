# RLIBM-ALL POPL 2022 Artifact Information

_________________________________________________________________________________________________

* INSTALLATION GUIDE:

There are two methods to install the artifact: (1) Installing docker and downloading the docker image for the artifact or (2) Manual installation. We recommend to use the docker image provided to expedite the installation process.

** DOWNLOADING PREBUILT DOCKER IMAGE

    We have prebuilt a docker image and hosted it in the docker hub.

(1) Install docker if not already installed by following the installation documentation in this link: https://docs.docker.com/install/

    We recommend installing docker and evaluating our artifact on a machine with Ubuntu. Although docker can be used with Windows or MacOS, docker may run on top of a linux VM

(2) Download the prebuilt docker image by using the command:

    $ sudo docker pull jpl169/popl2022artifact

    The docker image is roughly 5.5GB

(3) Run the docker image:

    $ sudo docker run -it jpl169/popl2022artifact

(4) If running the docker image on macOS, increase docker's memory resource. You can increase memory resource by going to docker->preference->Resources. 12GB of memory usage should be more than enough.

(5) Installation is complete. Go to EVALUATION GUIDE section.


** MANUAL INSTALLATION
Note: We show the manual installation process on Ubuntu 20.04. We specifically chose Ubuntu 20.04, since gcc version 10 can be easily installed via "apt install." We use gcc version 10 to test the correctness and performance of glibc's libm. gcc version 10 is only used for testing purposes. To generate polynomials, any gcc version will suffice. However, for artifact evaluation, we highly suggest Ubuntu 20.04 if doing manual installation. If your machine does not have Ubuntu 20.04 installed, you can use docker with a base image of Ubuntu 20.04. In the case of using docker, make sure to omit the "sudo" command since you're automatically logged in as the root. Still, the best method for artifact evaluation is to use the docker image. Otherwise, gcc version 10 will have to be manually installed. We do not provide the steps to manually install gcc version 10.

(1) To install and evaluate the artifact manually, first install a list of prerequisites:

    $ sudo apt update
    $ sudo apt install -yq --no-install-recommends apt-utils
    $ sudo apt install -yq build-essential parallel cmake git libgmp3-dev libmpfr-dev zlib1g zlib1g-dev bc wget python3 python3-pip gcc-10 g++-10 ncurses-term
    $ sudo python3 -m pip install --upgrade pip
    $ sudo python3 -m pip install matplotlib

(2) Download and install soplex 4.0.1:
    
    Please download soplex-4.0.1 from https://soplex.zib.de/index.php#download.
    Note: Make sure the version you download is soplex-4.0.1.

    $ tar -xvf soplex-4.0.1.tgz
    $ cd soplex-4.0.1
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ cd ../..

    Now, set the environment variable:
    $ export SOPLEXPATH=<path to soplex folder>

(3) Install Intel OneApi (to get Intel classic compiler: icc)
    
    1. Go to the link: https://software.intel.com/content/www/us/en/develop/tools/oneapi/hpc-toolkit/download.html
    2. Select the appropriate operating system (Linux)
    3. Select "Web & Logal" distribution option
    4. Select Online installer
    5. On the right hand side (gray background) if you scroll down, it will show the steps to install. 
    On Linux base system, it will be:
    $ wget https://registrationcenter-download.intel.com/akdlm/irc_nas/18211/l_HPCKit_p_2021.4.0.3347.sh
    $ sudo bash l_HPCKit_p_2021.4.0.3347.sh

    6. Follow the instruction. The installer will guide you through installing intel compiler.
        a. Make sure to install "Intel® oneAPI DPC++/C++ Compiler & Intel® C++ Compiler Classic." You can choose to not install any other components
        b. Make sure to remember the Installation directory
        c. If it shows you any warning about requiring the "Base toolkit" you can choose to ignore it.
            * The installation will take roughly 5~10 minutes.
    7. Once installation is complete, run script to set variables:
    $ cd <path to intel oneAPI directory> (e.g., /opt/intel/oneapi)
    $ source setvars.sh

    8. Set the environment variable:
    $ export ICCPATH=<path to Intel oneAPI directory> (e.g., export ICCPATH=/opt/intel/oneapi/)
    

(4) Or, download POPL21 artifact from Zenodo and untar the file:
    - Zenodo page: https://doi.org/10.5281/zenodo.5550564
    $ tar -xvf POPL2022Artifact.tar
    $ cd POPL2022Artifact
    $ make

(7) Installation is complete. Go to EVALUATION GUIDE section.

_________________________________________________________________________________________________

* EVALUATION GUIDE FOR THE ARTIFACT

    If you have followed one of the two installation methods in the INSTALLATION GUIDE section, you should be in the POPL21-artifact directory. If you are evaluating the artifact using the provided docker image, you will automatically be placed into POPL21-artifact directory when you run the docker image.


(1) Generating the polynomials for ourLibm (Claim 1):

    To test our technique in generating the polynomials, run the bash script,

    $ ./GenerationTest.sh

    This script will take roughly 7 minutes. It gives an example of how to generate a polynomial that produces the correct results of log2(x) for all inputs in [1, 2), for several FP representations, for all standard FP rounding modes. Once the script is finished, it should say a message similar to "successfully created..." in green text. If it produces a message similar to "incorrect polynomial ..." in red text, then the test failed.

    * The necessary files to generate the polynomial is in the folder, "smallGenerationTest." You can modify the files in there to generate polynomials of other elementary functions.
    - The "smallGenerationTest/GenerateOracleFiles" directory contains source code to generate the RNO result correctly.
    - The "smallGenerationTest/IntervalGen" directory contains source code to compute the reduced interval based on the range reduction strategy chosen to use with the log2(x) function.
    - The "smallGenerationTest/functiongen" directory contains source code to generate a polynomial that satisfies the intervals produced in the previous step.
    - The "smallGenerationTest/source" directory contains the source code of the elementary function implementation.
    - The "smallGenerationTest/correct_test" contains the source code to test the correctness of the created implementation.

    * As you can see, the root directory of POPL2022Artifact also contains similar directories (i.e., GenerateOracleFiles, etc.) The files in these directories contain how to generate elementary functions that produces correct results for all inputs. However, running this will take at a minimum 3-4 hours, for each elementary function. Hence, for the purposes of artifact evaluation, we show how to create polynomials for small input domain. 
    
(2) Check the correctness of ourLibm and mainstream math libraries (Claim 2):
    
    * To test the correctness of ourLibm, run the bash script,

    $ ./CorrTestRLibmAll.sh

    This script will take roughly 15 minutes. This script tests whether ourLibm produces the correctly rounded results for uniformly sampled FP inputs with different amount of exponent bits (and mantissa bits), for all standard rounding modes. If the testing is successful, you should see "check" in green text, for each elementary function and for representations with different exponent bits. Otherwise, it will print "incorrect" in red text, which signifies that the test has failed.

    We also set up a test script to run this test for ALL possible FP inputs. However, we really don't recommend running this for artifact evaluation purposes, as this will take > 48 hours, even when run in parallel...
    $ ./CorrTestRLibmAll_Full.sh

    * To test the correctness of mainstream math libraries, run the bash script,

    $ ./CorrTestMlibs.sh

    This script will take roughly 15 minutes. This script tests whether different math libraries produce correctly rounded results. This test corresponds to Table 2 and Table 3. The output is written in terminal. Once the test is complete, you should see two tables, that resembles how Table2 and Table3 looks like in the submission pdf, respectively. 
    For the test corresponding table 2, we uniformly sample inputs out of 4 billion float inputs. Because we uniformly sample inputs, the result will look different from the pdf. However, it should always be the case that when the pdf reports "checkmark," then our test also reports "o." If the pdf shows "N/A", then our test will show blank spaces for them. If the pdf reports "x", then our test may report "o" or "x". Additionally, because the test is set up to run in parallel, the rows that show up in the result of our test may not be the same as the rows shown in the pdf. 
    For the test corresponding table 3, we test the correctness against all inputs (2^19 inputs). Hence, the result should be matched identically to table 3. If the pdf reports "checkmark" our test reports "o". If the pdf reports "N/A", then our test show blank spaces. If the pdf reports "x", then our test reports "x". Again, because the test is set up to run in parallel, the rows that show up in the result of our test may not be the same as the rows shown in the pdf.

    We also set up a test script to run this test for ALL possible float inputs. Although we do not recommend to run this script for artifact evaluation purposes (as it will take 3-4 hours to complete), it would be good to run it if there's enough time.

    $ ./CorrTestMlibs_Full.sh


(3) Checking the performance of ourLibm (Claim 3):

    - To test the speedup of ourLibm, run the bash script,
    
    $ ./PerfTest.sh

    This script will take roughly 15 minutes. This script uniformly samples some inputs to compare the performance. Once the script terminates, you will see the following files:

    (b) SpeedupOverGlibc.pdf - This file shows the graph presented in Figure 14 (a)
    (c) SpeedupOverIntel.pdf - This file shows the graph presented in Figure 14 (b)
    (a) SpeedupOverCrlibm.pdf - This file shows the graph presented in Figure 14 (c)
    (d) SpeedupOverRlibm32.pdf - This file shows the graph presented in Figure 14 (d)

    - If you're using docker to evaluate the artifact, you can copy the pdf's from the container to your host machine using the following commands:

    $ exit
    $ sudo docker container ls -a  (Find the correct container id)
    $ sudo docker cp <container id>:/home/POPL2022Artifact/SpeedupOverGlibc.pdf .
    $ sudo docker cp <container id>:/home/POPL2022Artifact/SpeedupOverIntel.pdf .
    $ sudo docker cp <container id>:/home/POPL2022Artifact/SpeedupOverCrlibm.pdf .
    $ sudo docker cp <container id>:/home/POPL2022Artifact/SpeedupOverRlibm32.pdf .

    - To go back into docker container, use the following commands:

    $ sudo docker start <container id>
    $ sudo docker attach <container id>

    To evaluate the result, compare the graphs from the pdf against Figure 14. The speedup may be differ greatly between hardware architecture and specific configurations. Additionally, since the inputs are uniformly sampled for the artifact evaluation, the speedup may be different from what is shown in  Figure 14. However, it should still be the case that on average, ourLibm has speedup (bars are higher than 1.0) over glibc's libm, Intel's libm, and CR-LIBM, while slowdown (bars are less than 1.0) over RLibm-32.

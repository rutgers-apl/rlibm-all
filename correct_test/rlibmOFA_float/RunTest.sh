#!/bin/bash
bold=$(tput bold)
normal=$(tput sgr0)

echo -e "${bold}Testing correctness of Log(x) for various FP representations${normal}"
./allrep/Log
echo -e "${bold}Testing correctness of Log2(x) for various FP representations${normal}"
./allrep/Log2
echo -e "${bold}Testing correctness of Log10(x) for various FP representations${normal}"
./allrep/Log10
echo -e "${bold}Testing correctness of Exp(x) for various FP representations${normal}"
./allrep/Exp
echo -e "${bold}Testing correctness of Exp2(x) for various FP representations${normal}"
./allrep/Exp2
echo -e "${bold}Testing correctness of Exp10(x) for various FP representations${normal}"
./allrep/Exp10
echo -e "${bold}Testing correctness of Sinh(x) for various FP representations${normal}"
./allrep/Sinh
echo -e "${bold}Testing correctness of Cosh(x) for various FP representations${normal}"
./allrep/Cosh
echo -e "${bold}Testing correctness of Sinpi(x) for various FP representations${normal}"
./allrep/Sinpi
echo -e "${bold}Testing correctness of Cospi(x) for various FP representations${normal}"
./allrep/Cospi

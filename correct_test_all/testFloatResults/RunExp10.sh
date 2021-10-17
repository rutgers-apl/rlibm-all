#!/bin/bash

echo -n "| exp10(x) |  "
echo -ne "\033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m"
echo -n "  |  "
./glibc_double/Exp10
echo -n "  |  "
./intel_double/Exp10
echo -n "  |  "
echo -n "                 "
echo -n "  |  "
./rlibm32/Exp10
echo    "  |"

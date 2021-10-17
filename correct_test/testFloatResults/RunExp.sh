#!/bin/bash

echo -n "| exp(x)   |  "
echo -ne "\033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m"
echo -n "  |  "
./glibc_double/Exp
echo -n "  |  "
./intel_double/Exp
echo -n "  |  "
./crlibm/Exp
echo -n "  |  "
./rlibm32/Exp
echo    "  |"

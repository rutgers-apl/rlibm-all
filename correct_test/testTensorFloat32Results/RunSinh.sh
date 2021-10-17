#!/bin/bash

echo -n "| sinh(x)  |  "
echo -ne "\033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m"
echo -n "  |  "
./glibc_double/Sinh
echo -n "  |  "
./intel_double/Sinh
echo -n "  |  "
./crlibm/Sinh
echo -n "  |  "
./rlibm32/Sinh
echo    "  |"

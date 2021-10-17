#!/bin/bash

echo -n "| log10(x) |  "
echo -ne "\033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m"
echo -n "  |  "
./glibc_double/Log10
echo -n "  |  "
./intel_double/Log10
echo -n "  |  "
./crlibm/Log10
echo -n "  |  "
./rlibm32/Log10
echo    "  |"

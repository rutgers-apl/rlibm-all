#!/bin/bash

echo -n "| log2(x)  |  "
echo -ne "\033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m"
echo -n "  |  "
./glibc_double/Log2
echo -n "  |  "
./intel_double/Log2
echo -n "  |  "
./crlibm/Log2
echo -n "  |  "
./rlibm32/Log2
echo    "  |"

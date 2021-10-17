#!/bin/bash

echo -n "| cospi(x) |  "
echo -ne "\033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m"
echo -n "  |  "
echo -n "                 "
echo -n "  |  "
./intel_double/Cospi
echo -n "  |  "
./crlibm/Cospi
echo -n "  |  "
./rlibm32/Cospi
echo    "  |"

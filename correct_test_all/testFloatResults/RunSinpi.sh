#!/bin/bash

echo -n "| sinpi(x) |  "
echo -ne "\033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m   \033[0;32mo\033[0m"
echo -n "  |  "
echo -n "                 "
echo -n "  |  "
./intel_double/Sinpi
echo -n "  |  "
./crlibm/Sinpi
echo -n "  |  "
./rlibm32/Sinpi
echo    "  |"

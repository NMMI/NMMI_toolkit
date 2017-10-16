#!/bin/bash
echo -e "\e[1m[\e[32mcompiling all examples...\e[39m]\e[21m"

echo -e "\e[1m[\e[33m - example\e[39m]\e[21m"
cd ../example/qbdevice_handler
mkdir build
cd build
cmake ..
make
cd ../../../scripts
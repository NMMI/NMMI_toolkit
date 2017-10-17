#!/bin/bash
echo -e "\e[1m[\e[32mcompiling all examples...\e[39m]\e[21m"

echo -e "\e[1m[\e[33m - qbdevice_handler\e[39m]\e[21m"
cd ../example/qbdevice_handler
mkdir build
g++ -std=c++11 qbdevice_handler.cpp ../../qbAPI/src/qbmove_communications.cpp -o build/qbdevice_handler
cd ../../scripts

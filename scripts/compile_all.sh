#!/bin/bash
echo -e "\e[1m[\e[33m - qbAPI\e[39m]\e[21m"
cd qbAPI/src
make
cd ../..
echo -e "\e[1m[\e[33m - qbadmin\e[39m]\e[21m"
cd qbadmin/src
make
cd ../..

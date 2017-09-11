#!/bin/bash
chmod 777 scripts/*
echo -e "\e[1m[\e[32mupdating all submodules...\e[39m]\e[21m"
. scripts/update_all.sh
echo -e "\e[1m[\e[32mcompiling all submodules...\e[39m]\e[21m"
. scripts/compile_all.sh
echo -e "\e[1m[\e[32mSetup Completed!\e[39m]\e[21m"

#!/bin/bash
chmod 777 *
echo -e "\e[1m[\e[32mupdating all submodules...\e[39m]\e[21m"
. update_all.sh
echo -e "\e[1m[\e[32mcompiling all submodules...\e[39m]\e[21m"
. compile_submodules.sh
echo -e "\e[1m[\e[32mSetup Completed!\e[39m]\e[21m"

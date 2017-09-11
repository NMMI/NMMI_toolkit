# NMMI_toolkit
In this repository we collect the basic libraries of the NMMI.

Installation
===

UBUNTU
---

Open a terminal and clone the repository, if you associated an SSH key to github type:
```
git clone --recursive git@github.com:NMMI/NMMI_toolkit.git
```
otherwise:
```
git clone --recursive https://github.com/NMMI/NMMI_toolkit.git
```

Setup the toolkit
```
cd NMMI_toolkit
chmod 777 setup.sh
. setup.sh
```

This script update all the submodules to the latest version running the script *update_all.sh* and compile everything using the script *compile_all.sh* from the scripts folder.

For assistance contact: **ale.settimi[at]gmail.com**

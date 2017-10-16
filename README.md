# NMMI_toolkit
In this repository we collect the basic libraries of the NMMI.

Requirements
===
- g++
- make
- git
- bash

Installation
===

Ubuntu / MAC
---
Open a terminal and clone the repository typing:
```
git clone --recursive https://github.com/NMMI/NMMI_toolkit.git
```

Setup the toolkit
```
cd NMMI_toolkit/scripts
chmod 777 setup.sh
. setup.sh
```


Windows
---
Open a command prompt and clone the repository typing:
```
git clone --recursive https://github.com/NMMI/NMMI_toolkit.git
```

Setup the toolkit
```
cd NMMI_toolkit/scripts
setup.sh
```

This script update all the submodules to the latest version running the script *update_all.sh* and compile everything using the script *compile_all.sh* from the scripts folder.

Running Demos
===

Ubuntu / MAC
---
Open a terminal and compile the given examples:
```
cd NMMI_toolkit/scripts
. compile_example.sh
```

To run the *qbdevice_handler* example that shows how to control a chain made of qbmove and qbhand type:
```
cd example/qbdevice_handler/build/
./qbdevice_handler
```

For assistance contact: **ale.settimi[at]gmail.com**

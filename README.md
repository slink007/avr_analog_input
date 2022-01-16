avr_analog_input
=================

### Overview
More of a learning experience than a useful program, this is a chance for me to try out several things at once.  This project will involve getting a PIC/AVR Atmega32 to read an analog voltage and provide a suitable output on a LCD.  It will also be my first attempt at using git submodules.


### Getting Started
It's assumed that you're running some form of Linux on your computer.  I'm using Arch/Manjaro, but other versions should work as well.  Debian and/or Ubuntu name some of their programs differently than what I have below so users of those systems will need to alter the CMakefiles.txt file.

You need to have a few programs installed and in your PATH before you can build this code.
- avr-gcc
- avr-libc
- avr-binutils
- CMake


### Cloning and Compiling
```sh
git clone https://github.com/slink007/avr_analog_input.git --recursive
cd avr_analog_input
mkdir build
cd build
cmake ..
make
```

### It won't build, and code seems to be missing
This is most likely because you skipped the README, went straight to the green Code button, used the URL that it gave you to clone the repository.  That's OK, these things happen.

To fix this, go into the avr\_analog\_input directory, and do the following.
```sh
git submodule init
git submodule update
```


### Simulation
If you want to experiment with this code, and you don't happen to have an Atmega32 or a LCD, you can try using simulation.
[SimulIDE](https://www.simulide.com/p/home.html) is a basic circuit simulator program.  It includes some microcontrollers in its libraries, and the Atmega32 is one of the ones it supports.  You can create a circuit and then load the .hex file (found in the build folder).

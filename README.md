# Interplanetary Travel Calculator

> Updated: 11/30/2023

## About

This program is used to approximate the travel time to a planet from earth, as well as the individual's weight on said planet via interaction through the command line. This project was created mainly as an exercise of the following C++ programming concepts:

- Global constants declaration using the preprocessor
- Classes and object construction
- Switch statements
- Looping until input become valid
- "Memory-wise" variables using the "stdint" library
- Delaying execution using the "thread" and "chrono" library
- Adaptive semi-graphical output using the .resize() method
- Basic arithmetic operations

## Implementation

This program is written in the C++ programming language and has been tested to work with the GCC compiler on a Linux operating system. It is split into a header file (planet.h), an implementation file (planet.cpp), and a main file (main.cpp).

## Dependencies

The program relies on no other dependencies other than the libraries imported at the top of the main.cpp file.

## Running the program

To run the program on Linux, type the following commands:

```bash
cd /dir/of/project
make
./main
```

To remove compiled binaries use the following command:

```bash
make clean
```

## Disclaimer

This project is only for educational purposes. Any calculations made are not to be considered accurate as they do not take into account the changes in distance due to the orbit of planets, changes in the speed of the spacecraft, and other variables that may sway the results.

## License

This project is licensed under the GNU General Public License v3.0. See the LICENSE file for more info.

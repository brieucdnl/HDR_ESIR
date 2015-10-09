# HDR_ESIR

Oceane LASSERRE
Brieuc DANIEL

Ecole Superieure d'Ingenieurs de Rennes - SFX class - Teacher: Remi Cozot


### Install requirements

A few external libraries must be installed in order to run that project:

1. LibRaw (v >= 0.17)

Available at http://www.libraw.org

This library allows our code to use proprietary format such as .NEF (Nikon), .CR2 (Canon).
It's distributed under three different licences, we let you find more about this at http://www.libraw.org/docs

2. OpenCV (v >= 2.4.8)

Available at http://opencv.org

This library is the core of our application, we use its data-structures, functions, etc.
You may find OpenCV licence at http://opencv.org/about.html

### Compiling and Execution

If the different libraries are correctly installed, you just have to generate the compiling files. In this purpose, you need to set your path to HDR_ESIR/build and execute:
`cmake ../`
This step completed, you may compile the files executing:
`make`
Then you have to execute the project like this:
`./HDR`

ENJOY !

# MakerWear
MakerWear is a tangible and modular, wearable construction kit for young children that contains two parts: (1) a set of single-function, plug-and-play modules that could be combined to create complex interactive behaviors; (2) magnetic socket meshes that are pre-sewn into clothing that provides an easy method to attach and detach modules to clothes.

This repository contains all of the source files that are required to build or modify MakerWear modules in addition to the socket mesh.

# Repository Organization
For example, take the MultiColor Light as an example. Similar to almost all other modules, the MultiColor Light is a 1x3 module which means that it has one input and three outputs and requires two PCBs to build. The bottom PCB is found here: https://github.com/MakerWear/MakerWear/tree/master/Common/BasePCBs/1x3/Bottom and the Top PCB (along with the rest of the source files that are specifically designed for this module) is found here: https://github.com/MakerWear/MakerWear/tree/master/Modules/Action/MultiColorLight

The ComponentList.xlsx contains all of the components and links to the vendors from which you can buy them. the .brd file (board layout) should always be next the the .sch file (board schematics).

Each module has a microcontroller which could be programmed using an Arduino. the arduino source file is inside the https://github.com/MakerWear/MakerWear/tree/master/Modules/Action/MultiColorLight/ArduinoCodes folder. and finally, there is an illustrator file which is used to cut/etch a piece of colored cardboard (e.g. white, red, black, blue for action, power, sensor and modifier) using a laser cutter.

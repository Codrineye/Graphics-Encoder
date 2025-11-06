# Graphics Encoder

A graphical tool that lets you **draw a user interface** and **encode it into a file**.<br>
You can then use the same tool to **decode** that file into C++ code, allowing you to hard-code the UI directly into a program.

## Current Limitations
- Encoding and decoding are not yet implemented.
- Data is stored only as points.
- Only line drawing is supported.
- Only the color white is available.

## Dependencies
This project is built using **MSVC’s `cl.exe`** (x86 architecture).<br>
It uses **FreeGLUT** as the graphical interface.<br>
Exact version in use: [FreeGLUT 3.0.0 MSVC Package](https://www.transmissionzero.co.uk/software/freeglut-devel/) from Transmission Zero.

## Versioning
This project serves as a personal learning experiment and may not be of general use to others.

### Prototype Phase
The “Prototype” status applies until encoding, decoding, and additional tools are implemented.

#### V1.0.0.2
Third push.<br>
Reverted module Data to using Node linked list instead of vector to have more control over the data storage.<br>
Push to not lose progress.

#### V1.0.0.1
Second push.<br>
- Changed repository visibility from private to public.  
- Added namespace `GE` to remove uncontrolled global variables.

#### V1.0.0.0
First push.<br>
- Implemented modules [Data](./Data/Data.hpp) and [Frontend](./Frontend/Frontend.hpp).  
- No namespace present in this version.

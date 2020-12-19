# mine-plow
The goal of project is to improve my PE file analyzing skills.

## Usage
### Version Compatibility
* Windows XP Minesweeper

### Features
* Modifying the time counting
* Look up landmines coordinates

## Build Instruction
### Prerequisites
* CMake 3.12+
* Linux - minGW 
* Windows - Visual Studio(MSVC)

#### Windows based
```bash
$ git clone https://github.com/andrewbae/gambian-pouched-rat.git
$ cd gambian-pouched-rat && mkdir build 
$ cmake . -D CMAKE_CXX_COMPILER="MSVC" -Bbuild
$ cmake --build build/
```
#### Linux based
```bash
$ git clone https://github.com/andrewbae/gambian-pouched-rat.git
$ cd gambian-pouched-rat && mkdir build 
$ cmake . -D CMAKE_CXX_COMPILER="x86_64-w64-mingw32-g++" -Bbuild
$ cmake --build build/
```


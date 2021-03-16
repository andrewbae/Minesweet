# mine-plow
[![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fandrewbae%2Fmine-plow&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23FFFFFF&title=hits&edge_flat=false)](https://hits.seeyoufarm.com)  
A simple Windows minesweeper trainer.  
Unfortunately, mine-plow does support XP version only yet.  
[@andrewbae](github.com/andrewbae) 

## Usage
### Version Compatibility
* Windows XP Minesweeper

### Features
* Modifying the time counting
* Look up landmines coordinates

### Technical details
0x0f: Unknown box
0x10: Start and end lines of board
0x40: Blank box
0x41~0x48: Numeric box
0x8f: mine

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


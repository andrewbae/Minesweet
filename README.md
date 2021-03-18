# mine-plow
[![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fandrewbae%2Fmine-plow&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23FFFFFF&title=hits&edge_flat=false)](https://hits.seeyoufarm.com)  

<img src="https://user-images.githubusercontent.com/40394063/111699953-1e439580-887c-11eb-98c1-5b03a59f044e.png" width=300px>

A simple Windows minesweeper trainer.  
Unfortunately, mine-plow does support XP version only yet.  
[@andrewbae](github.com/andrewbae) 


## Version Compatibility
* Windows XP Minesweeper

## Features
### Disable the entire mines
  ![ezgif com-gif-maker](https://user-images.githubusercontent.com/40394063/111704023-dcb5e900-8881-11eb-93d6-153535d4c67c.gif)  
### Reset the timer
 ![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/40394063/111704518-9d3bcc80-8882-11eb-9bec-25ed9a6a110f.gif)

## Technical details
```cpp
#define GAME_TIMER_ADDRESS (0x0100579C)
#define GAME_BOARD_ADDRESS (0x01005360)
#define GAME_BOARD_SIZE (832)
#define GAME_BOARD_WALL (0x10)

#define GAME_BOX_UNKNOWN (0x0f)
#define GAME_BOX_BLANK (0x40)
#define GAME_BOX_1 (0x41)
#define GAME_BOX_2 (0x42)
#define GAME_BOX_3 (0x43)
#define GAME_BOX_4 (0x44)
#define GAME_BOX_5 (0x45)
#define GAME_BOX_6 (0x46)
#define GAME_BOX_7 (0x47)
#define GAME_BOX_8 (0x48)
#define GAME_BOX_MINE_HIDDEN (0x8f)
#define GAME_BOX_MINE_SHOWN (0x8a)
```

## Build Instruction
### Prerequisites
* CMake 3.12+
* Linux - minGW 
* Windows - Visual Studio(MSVC)

#### Windows based

```bash
$ git clone https://github.com/andrewbae/mine-plow.git
$ cd mine-plow && mkdir build 
$ cmake . -D CMAKE_CXX_COMPILER="MSVC" -Bbuild
$ cmake --build build/
```
#### Linux based
```bash
$ git clone https://github.com/andrewbae/mine-plow.git
$ cd mine-plow && mkdir build 
$ cmake . -D CMAKE_CXX_COMPILER="x86_64-w64-mingw32-g++" -Bbuild
$ cmake --build build/
```

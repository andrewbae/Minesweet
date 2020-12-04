#ifndef _MAIN_H
#define _MAIN_H

#define TIMER_ADDRESS (0x0100579C)

#define MAP_START_ADDRESS (0x01005361)
#define MAP_END_ADDRESS (MAP_START_ADDRESS | 0x0000011E)
#define MAP_WIDTH (30)
#define MAP_HEIGHT (16)
#define MAP (MAP_WIDTH * MAP_HEIGHT)

#define ID_NEWLINE (0x10)
#define ID_MINE (0x8F)
#define ID_MINE_FLAG (0x8E)
#define ID_UNKNOWN (0x0F)
#define ID_UNKNOWN_FLAG (0x0E)
#define ID_BACKGROUND (0x40)

PROCESSENTRY32 fnSearchMinesweeperProcess();
int fnScreenBanner();
int fnMineLocationRadar(HANDLE hProcess);

#endif

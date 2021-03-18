#ifndef _APP_H
#define _APP_H

#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif


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

#include <windows.h>
#include <tlhelp32.h>
#include "proc.h"

namespace Ui { class Application {}; };

class Application {
private:
    WNDCLASSA windowClass;
    RECT rect;
public:
    const LPCSTR classNameMain = "MINE_PLOW";
    const LPCSTR classNameBackgroundWhite = "BACKGROUND_WHITE";

    UCHAR gameBoard[GAME_BOARD_SIZE] = { 0x00 };
    HWND windowHandle;
    
    HINSTANCE instanceHandle;
    HWND __stdcall AppInitialize(
        _In_ HINSTANCE imageBaseAddress,
        _In_ LPCSTR applicationTitle,
        _In_ RECT rect,
        _In_ int cmdShow
    );
    void __stdcall SetWindowPositionToCenter(void);
    PROCESSENTRY32 __stdcall SearchMinesweeperProcess(void);
    void __stdcall DisableEntireMines(
        _In_ DWORD pid
    );
    void __stdcall ResetTimer(
        _In_ DWORD pid
    );
    void __stdcall Copyright(void);
};

#endif

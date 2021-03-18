#include "main.h"

INT __stdcall WinMain(
    _In_ HINSTANCE imageBaseAddress,
    _In_opt_ HINSTANCE prevImageBaseAddress,
    _In_ LPSTR cmdLine,
    _In_ INT cmdShow
) {
    Application* app = new Application;
    if (!app->SearchMinesweeperProcess().dwSize) {
        MessageBoxA(nullptr, "Please run minesweeper first", "Cannot found minesweeper", MB_OK | MB_ICONSTOP);
        return EXIT_FAILURE;
    }
    app->instanceHandle = imageBaseAddress;
    
    RECT rect;
    SetRect(&rect, 40, 115, 285, 185);
    app->windowHandle = app->AppInitialize(app->instanceHandle, "Mine plow", rect, cmdShow);
    if (!(app->windowHandle)) {
        MessageBoxA(nullptr, "Cannot create the window", "Unexpected error!", MB_OK | MB_ICONSTOP);
        return EXIT_FAILURE; 
    }

    app->SetWindowPositionToCenter();

    while (GetMessage(&message, 0, 0, 0) > 0) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return 0;
}

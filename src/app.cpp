#include "app.h"

#include <iostream>
HWND __stdcall Application::AppInitialize(
    _In_ HINSTANCE imageBaseAddress,
    _In_ LPCSTR applicationTitle,
    _In_ RECT rect,
    _In_ int cmdShow
) {
    memset(&windowClass, 0x00, sizeof(WNDCLASSA));

    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.cbWndExtra = sizeof(PVOID);
    windowClass.hCursor = LoadCursor(0, IDC_ARROW);
    windowClass.hInstance = imageBaseAddress;
    windowClass.lpfnWndProc = MainWindowProcedure;
    windowClass.lpszClassName = classNameMain;

    if (!(RegisterClassA(&windowClass))) { return (HWND)0x00; }

    windowHandle = CreateWindowExA(
        0, classNameMain,
        applicationTitle,
        WS_OVERLAPPED | WS_SYSMENU,
        rect.left, rect.top, rect.right, rect.bottom,
        0, 0, imageBaseAddress, 0);

    if (!(windowHandle)) { return (HWND)0x00; }
    ShowWindow(windowHandle, SW_SHOW);
    return windowHandle;
}

void __stdcall Application::SetWindowPositionToCenter(void)
{
    GetWindowRect(this->windowHandle, &rect);
    SetWindowPos(
        this->windowHandle, 0,
        (GetSystemMetrics(SM_CXSCREEN) - rect.right) / 2,
        (GetSystemMetrics(SM_CYSCREEN) - rect.bottom) / 2,
        0, 0,
        SWP_NOZORDER | SWP_NOSIZE
    );
}

PROCESSENTRY32 __stdcall Application::SearchMinesweeperProcess(void) {
    HANDLE processSnapshotHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    PROCESSENTRY32 process = { process.dwSize = sizeof(PROCESSENTRY32) };
    UINT processListIndex = 0;
    for (; processListIndex < 200; processListIndex++) {
        Process32Next(processSnapshotHandle, &process);
        if (!strcmp(process.szExeFile, "winmine.exe")) {
            CloseHandle(processSnapshotHandle);
            return process;
        }
    }
    CloseHandle(processSnapshotHandle);
    memset(&process, (char)0x00, sizeof(PROCESSENTRY32));
    return process;
}

void __stdcall Application::DisableEntireMines(
    _In_ DWORD pid
) {
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, TRUE, pid);
    ReadProcessMemory(processHandle, (LPCVOID)GAME_BOARD_ADDRESS, gameBoard, GAME_BOARD_SIZE, 0);
    for (UINT v0 = 0; v0 < GAME_BOARD_SIZE; v0++) {
        if (*(gameBoard + v0) == GAME_BOX_MINE_HIDDEN) {
            *(gameBoard + v0) = GAME_BOX_MINE_HIDDEN+1;
        }
    }
    WriteProcessMemory(processHandle, (LPCVOID*)GAME_BOARD_ADDRESS, gameBoard, GAME_BOARD_SIZE, 0);
    CloseHandle(processHandle);
}

void __stdcall Application::ResetTimer(
    _In_ DWORD pid
) {
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, TRUE, pid);
    UINT timerValue = 0x00;
    WriteProcessMemory(processHandle, (LPCVOID*)GAME_TIMER_ADDRESS, &timerValue, sizeof(short), 0);
    CloseHandle(processHandle);
}

void __stdcall Application::Copyright(void) {
    ShellExecute(NULL, "open", "http://github.com/andrewbae", NULL, NULL, SW_SHOWNORMAL);
}
//    AllocConsole();
//    freopen("CONOUT$", "w", stdout);
//    std::cout << "This works" << std::endl;

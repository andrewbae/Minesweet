#include "proc.h"

Application* app = new Application;
LRESULT __stdcall MainWindowProcedure(
	_In_ HWND windowHandle,
	_In_ UINT windowMessage,
	_In_ WPARAM wordParameter,
	_In_ LPARAM longParameter
)
{
	switch (windowMessage) {
    case WM_CREATE: {
        RECT rect;
        SetRect(&rect, 10, 10, 250, 35);
        CreateWindowW(
            L"BUTTON",  
            L"Disable the entire mines",  
            WS_TABSTOP | WS_VISIBLE | WS_CHILD , 
            rect.left,
            rect.top,
            rect.right,
            rect.bottom,
            windowHandle, 
            (HMENU)DISABLE_ENTIRE_MINES, 
            (HINSTANCE)GetWindowLongPtr(windowHandle, GWLP_HINSTANCE),
            0);
        SetRect(&rect, 10, 50, 250, 35);
        CreateWindowW(
            L"BUTTON",
            L"Reset the Timer",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD,
            rect.left,
            rect.top,
            rect.right,
            rect.bottom,
            windowHandle,
            (HMENU)RESET_TIMER,
            (HINSTANCE)GetWindowLongPtr(windowHandle, GWLP_HINSTANCE),
            0);
        SetRect(&rect, 10, 100, 250, 35);
        CreateWindowW(
            L"BUTTON",
            L"GitHub - Andrew Bae",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD,
            rect.left,
            rect.top,
            rect.right,
            rect.bottom,
            windowHandle,
            (HMENU)COPYRIGHT,
            (HINSTANCE)GetWindowLongPtr(windowHandle, GWLP_HINSTANCE),
            0);
        break;
       }
    case WM_COMMAND: {
        switch (wordParameter) {
        case COPYRIGHT:
            app->Copyright();
        case DISABLE_ENTIRE_MINES:
            app->DisableEntireMines(app->SearchMinesweeperProcess().th32ProcessID);
            break;
        case RESET_TIMER:
            app->ResetTimer(app->SearchMinesweeperProcess().th32ProcessID);
            break;
        }
        break;
    }
    case WM_CLOSE: {
        if (MessageBoxA(
                windowHandle, 
                "Are you sure close the program?", 
                "Wait",
                MB_OKCANCEL | MB_ICONEXCLAMATION) == IDOK) {
            DestroyWindow(windowHandle);
        }
        break;
    }
    case WM_DESTROY: {
        PostQuitMessage(0);
    }
    default: {
        return DefWindowProcA(windowHandle, windowMessage, wordParameter, longParameter);
    }
    return 0;
    }
}

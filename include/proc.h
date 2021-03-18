#ifndef _PROC_H
#define _PROC_H

#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

#define COPYRIGHT (WM_USER)
#define DISABLE_ENTIRE_MINES (WM_USER + 1)
#define RESET_TIMER (WM_USER + 2)
#include <windows.h>
#include "app.h"

namespace Ui { class Procedure{}; }

LRESULT __stdcall MainWindowProcedure(
	_In_ HWND windowHandle,
	_In_ UINT windowMessage,
	_In_ WPARAM wordParameter,
	_In_ LPARAM longParameter
	);

#endif
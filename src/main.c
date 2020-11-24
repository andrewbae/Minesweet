#pragma warning(disable: 4996)
#include <windows.h>
#include <TlHelp32.h>
#include <stdio.h>
#include "main.h"

int main()
{
	char iAnswer = 0;
    DWORD pid = 0, time = 0;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;

	system("title Minesweet && mode con cols=64 lines=30");

    printf("Search the minesweeper processs...");
    pe32 = fnSearchMinesweeperProcess();
    if (pe32.th32ProcessID == NULL) {
        puts("FAILED");
		system("pause");
        exit(-1);
    }

    puts("SUCCESS");
    printf("PID: %d\n", pe32.th32ProcessID);
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, 1, pe32.th32ProcessID);

	puts("");
	while (1) {
		fnScreenBanner();
		printf("\nPlease select the options\n> ");
		iAnswer = getch();
		switch (iAnswer) {
		case '0':
			exit(0);
			break;
		case '1':
		    ReadProcessMemory(hProcess, (LPCVOID)TIMER_ADDRESS, &time, sizeof(DWORD), NULL);
			printf("\rTimer: %d\n", time);	
			puts("Enter the desired timer value");
			scanf("%d", &time);
			WriteProcessMemory(hProcess, (LPCVOID)TIMER_ADDRESS, NULL, sizeof(DWORD), NULL);
	        WriteProcessMemory(hProcess, (LPCVOID)TIMER_ADDRESS, &time, sizeof(DWORD), NULL);
			break;
		case '2':
			system("cls");
			fnMineLocationRadar(hProcess);
			break;
		default:
			puts("\nUnknown command");
			system("timeout 1 /nobreak > nul");
			system("cls");
			continue;
		}
		system("cls");
	}
    CloseHandle(hProcess);
}

PROCESSENTRY32 fnSearchMinesweeperProcess() {
    HANDLE hProcessSnap;
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 pe32 = { pe32.dwSize = sizeof(PROCESSENTRY32) };
    char szExeFileCompare[MAX_PATH] = { NULL };
    UINT nProcessRow, nProcessColumn;

    for (nProcessRow = 0; nProcessRow < 200; nProcessRow++) {
        Process32Next(hProcessSnap, &pe32);
        for (nProcessColumn = 0; *(pe32.szExeFile + nProcessColumn) != NULL; nProcessColumn++) {
            *(szExeFileCompare + nProcessColumn) = *(pe32.szExeFile + nProcessColumn);
        }
        if (!strcmp(szExeFileCompare, "winmine.exe")) {
            CloseHandle(hProcessSnap);
            return pe32;
        }
        memset(&szExeFileCompare, NULL, strlen(szExeFileCompare));
    }
    CloseHandle(hProcessSnap);
    memset(&pe32, NULL, sizeof(PROCESSENTRY32));
    return pe32;
}

int fnScreenBanner()
{
	char chBanner[MAP_HEIGHT - 5][MAP_WIDTH * 2] = {
		{"  __  __ _                                   _   "},
		{" |  \\/  (_)                                 | |  "},
		{" | \\  / |_ _ __   ___  _____      _____  ___| |_ "},
		{" | |\\/| | | '_ \\ / _ \\/ __\\ \\ /\\ / / _ \\/ _ \\ __|"},
		{" | |  | | | | | |  __/\\__ \\\\ V  V /  __/  __/ |_ "},
		{" |_|  |_|_|_| |_|\\___||___/ \\_/\\_/ \\___|\\___|\\__|\n\n"},
		{"1. Edit timer"},
		{"2. Show mines"},
		{"0. Exit"}
	};

	UINT x, y;
	for (y = 0; y < (MAP_HEIGHT - 5); y++) {
		for (x = 0; x < MAP_WIDTH * 2; x++) {
			printf("%c", *(*(chBanner + y) + x));
		}
		puts("");
	}
}

int fnMineLocationRadar(HANDLE hProcess)
{
    unsigned char gameMapOnMemory[MAP_HEIGHT * MAP_WIDTH] = { 0 };
    unsigned char gameMap[MAP_HEIGHT][MAP_WIDTH] = { 0 };

    ReadProcessMemory(hProcess, (LPCVOID)MAP_START_ADDRESS, &gameMapOnMemory, 286, NULL);

    UINT nMemoryOffset = 0, x, y;
	for (y = 0; y < MAP_HEIGHT;  y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            if (*(gameMapOnMemory + nMemoryOffset) == ID_NEWLINE) {
                nMemoryOffset += 1;
                while ((*(gameMapOnMemory + nMemoryOffset) != ID_NEWLINE) \
					&& *(gameMapOnMemory + nMemoryOffset) != NULL) {
                    nMemoryOffset += 1;
                }
                nMemoryOffset += 1;
                break;
            }
            *(*(gameMap + y) + x) = *(gameMapOnMemory + nMemoryOffset);
            nMemoryOffset += 1;
        }
    }

for (y = 0; y < MAP_HEIGHT; y++) {
		for (x = 0; *(*(gameMap + y) + x) != NULL; x++) {
			switch (*(*(gameMap + y) + x)) {
			case ID_MINE:
				printf("* ");
				break;
			case ID_MINE_FLAG:
				printf("v ");
				break;
			case ID_UNKNOWN:
				printf("? ");
				break;
			case ID_UNKNOWN_FLAG:
				printf("v ");
				break;
			case ID_BACKGROUND:
				printf(". ");
				break;
			case (ID_BACKGROUND + 1):
				printf("1 ");
				break;
			case (ID_BACKGROUND + 2):
				printf("2 ");
				break;
			case (ID_BACKGROUND + 3):
				printf("3 ");
				break;
			case (ID_BACKGROUND + 4):
				printf("4 ");
				break;
			case (ID_BACKGROUND + 5):
				printf("5 ");
				break;
			case (ID_BACKGROUND + 6):
				printf("6 ");
				break;
			case (ID_BACKGROUND + 7):
				printf("7 ");
				break;
			case (ID_BACKGROUND + 8):
				printf("8 ");
				break;
			}
		}
		puts("");
	}
char iAnswer; 
	while (1) {
		puts("[q] quit");
		iAnswer = getch();
		if (iAnswer == 'q') {
			return 0;
			break;
		}
		else {
			puts("Please choice just \'q\'");
			continue;
		}
	}
}

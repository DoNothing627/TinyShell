#include <stdio.h>
#include <windows.h>

DWORD pid[20];
int count;

void killAllProcesses() {
    for (int i = 0; i < 20; i++)
    {
        if (pid[i] > 0) {
            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid[i]);
            BOOL result = TerminateProcess(hProcess, 1);
            CloseHandle(hProcess);
            if (result == TRUE) {
                count--; 
                pid[i] = 0;
            }
        }
    }
}
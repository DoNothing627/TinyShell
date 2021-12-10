#include <stdio.h>
#include <windows.h>

DWORD Id[20];
int cnt;

void kill() {
    for(int i= 0; i< 20; i++){
        if(Id[i]> 0) {
            HANDLE hProcess= OpenProcess(PROCESS_ALL_ACCESS, FALSE, Id[i]);
            BOOL res= TerminateProcess(hProcess, 1);
            CloseHandle(hProcess);
            if(res) {
                --cnt;
                Id[i]= 0;
            }
        }
    }
}

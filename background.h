#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <signal.h>

DWORD Id[20];
char name[20][30];
int count;
void signal_ctrl_c() {
    printf("test!!!");
}

int run_bg(char* filename)
{
    STARTUPINFO s;
    PROCESS_INFORMATION p;
    ZeroMemory(&s, sizeof(s));
    s.cb = sizeof(s);

    wchar_t* _Tfilename = (wchar_t*)malloc((strlen(filename) + 1) * sizeof(wchar_t)); //memory allocation
    mbstowcs(_Tfilename, filename, strlen(filename) + 1);

    if (!CreateProcess(_Tfilename, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &s, &p)){
        printf("Error!!! Can't open this process\n");
        return 1;
    }

    printf("process has id = %lu is running\n", p.dwProcessId);
    Id[count] = p.dwProcessId;
    strcpy(name[count], filename);
    count++;
    signal(2, signal_ctrl_c);
    CloseHandle(p.hProcess);
    CloseHandle(p.hThread);
    return 0;
}

#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <signal.h>

DWORD Id[20];
char name[20][30];
int cnt;
void ctrlC() {
    printf("END");
}

int run_bg(char* filename)
{
    PROCESS_INFORMATION p;
    STARTUPINFO s;

    ZeroMemory(&s, sizeof(s));
    s.cb = sizeof(s);

    wchar_t* _Tfilename = (wchar_t*)malloc((strlen(filename) + 1) * sizeof(wchar_t)); //memory allocation
    mbstowcs(_Tfilename, filename, strlen(filename) + 1);

    if (!CreateProcess(_Tfilename, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &s, &p)){
        printf("Can't open this process\n");
        return 1;
    }

    printf("process id = %lu is running\n", p.dwProcessId);
    Id[cnt] = p.dwProcessId;
    strcpy(name[cnt], filename);
    cnt++;
    signal(2, ctrlC);
    CloseHandle(p.hProcess);
    CloseHandle(p.hThread);
    return 0;
}

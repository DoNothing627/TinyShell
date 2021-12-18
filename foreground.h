#include <stdio.h>
#include <windows.h>
#include <signal.h>
#include <tchar.h>

void destroy(DWORD id) {
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, id);
    TerminateProcess(hProcess, 1);
    CloseHandle(hProcess);
    return;
}

int run_fg(char* filename)
{
    PROCESS_INFORMATION p;
    STARTUPINFO s;

    ZeroMemory(&s, sizeof(s));
    s.cb = sizeof(s);

    wchar_t* _Tfilename = (wchar_t*)malloc((strlen(filename) + 1) * sizeof(wchar_t));
    mbstowcs(_Tfilename, filename, strlen(filename) + 1);

    if (!CreateProcess(_Tfilename, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &s, &p)){
        printf("Can't open this process\n");
        return 1;
    }

    signal(SIGINT, destroy);
    WaitForSingleObject(p.hProcess, 10000);
    TerminateProcess(p.hProcess, 1);
    CloseHandle(p.hProcess);
    CloseHandle(p.hThread);
    printf("Destroy process with id = %lu\n", p.dwProcessId);
    return 0;
}

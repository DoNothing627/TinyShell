#include <stdio.h>
#include <windows.h>

void stop(DWORD Id)
{
    if (DebugActiveProcess(Id))
        printf("Process with id = %d is stopping", Id);
    else
        printf("Can't stop this process");
}
void resume(DWORD Id)
{
    if (DebugActiveProcessStop(Id))
        printf("Process with id = %d is resumed", Id);
    else
        printf("Can't resume this process");
}

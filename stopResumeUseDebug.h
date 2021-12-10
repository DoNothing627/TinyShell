#include <stdio.h> 
#include <windows.h> 

//== ok done
void suspend(DWORD Id)
{
    if (DebugActiveProcess(Id)) 
        printf("Process with id = %d is stopping", Id);
    else
        printf("Error!!! Can't stop this process");
}
void resume(DWORD Id)
{
    if (DebugActiveProcessStop(Id)) {
        printf("Process with id = %d is resumed", Id);
    }
    else {
        printf("Error!!! Can't resume this process");
    }
}
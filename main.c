#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "menu.h"
#include "directory.h"
#include "kill.h"
#include "local_time.h"
#include "stopResume.h"
#include "background.h"
#include "foreground.h"

char user_input[300], filter_input[300], parameter[300];
char* i;
int count = 0;

int main()
{
    printf("-------------------------------TINY SHELL-----------------------------\n");

    menu();

    while(1)
    {
        printf("\n>");
        scanf("%[^\n]%*c", user_input);
        fflush(stdin);

        i= strchr(user_input, ' ');
        if(i!= NULL)
        {
            strcpy(parameter, i + 1);
            strcpy(filter_input, user_input);
            filter_input[strlen(user_input) - strlen(parameter) - 1]= '\0';
        }
        else strcpy(filter_input, user_input);

        if(!strcmp(filter_input, "ls"))
            printDir(parameter);
        else if(!strcmp(filter_input, "menu"))
            menu();
        else if(!strcmp(filter_input, "time"))
            local_time();
        else if(!strcmp(filter_input, "run_fg"))
            run_fg(parameter);
        else if(!strcmp(filter_input, "run_bg"))
            run_bg(parameter);
        else if(!strcmp(filter_input, "kill"))
            kill();
        else if(!strcmp(filter_input, "stop"))
            stop(parameter);
        else if(!strcmp(filter_input, "resume"))
            resume(parameter);
        else if(!strcmp(filter_input, "run_bat"))
            system(parameter);
        else if(!strcmp(filter_input, "clear"))
            system("cls");
        else if(!strcmp(filter_input, "exit"))
            exit(0);
        else
            printf("Command not found!\n");
    }
    getchar();
    return 0;
}

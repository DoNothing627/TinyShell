#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "menu.h"
#include "directory.h"
#include "kill.h"
#include "local_time.h"
#include "task.h"
#include "stopResumeUseDebug.h"
#include "background.h"
#include "foreground.h"
#include "help.h"

DWORD pid[20];
char space = ' ', name[20][30], user_input[300], filter_input[300], parameter[300];
char* index_space;
int count = 0;

int main()
{
    printf("-------------------------------TINY SHELL-----------------------------\n");

    menu();

    while (1)
    {
        printf("\n>");
        scanf("%[^\n]%*c", user_input);
        fflush(stdin);

        index_space = strchr(user_input, space);
        if (index_space != NULL)
        {
            // tách tham số phía sau input
            strcpy(parameter, index_space + 1);
            // copy toàn bộ input
            strcpy(filter_input, user_input);
            // tách lệnh phía trước input
            filter_input[strlen(user_input) - strlen(parameter) - 1] = '\0';
        }
        // gán input vào cmd
        else strcpy(filter_input, user_input);

        // thuc hien cau lenh
        if (strcmp(filter_input, "dir") == 0)
            printListDir(parameter);
        else if (strcmp(filter_input, "menu") == 0)
            menu();
        else if (strcmp(filter_input, "time") == 0)
            local_time();
        else if (strcmp(filter_input, "run_fg") == 0)
            run_fg(parameter);
        else if (strcmp(filter_input, "run_bg") == 0)
            run_bg(parameter);
        else if (strcmp(filter_input, "list") == 0)
            print_processes();
        else if (strcmp(filter_input, "kill_all") == 0)
            killAllProcesses();
        else if (strcmp(filter_input, "stop") == 0)
            suspend(parameter);
        else if (strcmp(filter_input, "resume") == 0)
            resume(parameter);
        else if (strcmp(filter_input, "run_bat") == 0)
            system(parameter);
        else if (strcmp(filter_input, "help") == 0)
            help();
        else if (strcmp(filter_input, "clear") == 0)
            system("cls");
        else if (strcmp(filter_input, "exit") == 0)
            exit(0);
        else
            printf("Command not found!\n");
    }
    getchar();
    return 0;
}

#define _CRT_SECURE_NO_WARNING
#include <dirent.h>
#include <windows.h>
#include <stdio.h>

void printDir(char* path) {

    struct dirent* directory;
	DIR* ls= opendir(path);

	if (ls!= NULL)
	{
		while((directory= readdir(ls))!= NULL)
			printf("%s \n", directory-> d_name);
		closedir(ls);
	}
	else
		printf("\nCan't open this directory.");
	printf("\n");
}

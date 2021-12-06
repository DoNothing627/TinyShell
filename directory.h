#define _CRT_SECURE_NO_WARNING
#include <dirent.h>
#include <windows.h>
#include <stdio.h>

void printListDir(char* directoryName) {
	DIR* presentDir;
	struct dirent* directory;

	presentDir = opendir(directoryName);
	if (presentDir != NULL)
	{
		while ((directory = readdir(presentDir)) != NULL) 
			printf("%s \n", directory->d_name);
		closedir(presentDir);
	}
	else
		printf(" \nError!!! Can't open this directory.");
	printf("\n");
}

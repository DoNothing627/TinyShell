#define _CRT_SECURE_NO_WARNING
#include <dirent.h>
#include <windows.h>
#include <stdio.h>

void printDir(char* path) {
	DIR* dir;
	struct dirent* directory;

	dir = opendir(path);
	if (dir!= NULL)
	{
		while((directory= readdir(dir))!= NULL)
			printf("%s \n", directory-> d_name);
		closedir(dir);
	}
	else
		printf("\nCan't open this directory.");
	printf("\n");
}

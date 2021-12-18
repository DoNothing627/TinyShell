#include <stdio.h>
#include <time.h>

void local_time()
{
    struct tm* TIME_INFO;
	time_t TIME_T;

	time(&TIME_T);
	TIME_INFO = localtime(&TIME_T);
	printf("%s", asctime(TIME_INFO));
}

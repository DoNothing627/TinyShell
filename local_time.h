#include <stdio.h>
#include <time.h>

void local_time()
{
	time_t TIME_T;
	struct tm* TIME_INFO;
	time(&TIME_T);
	TIME_INFO = localtime(&TIME_T);
	printf("%s", asctime(TIME_INFO));
}

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int i;
	pid_t masp = getpid();
	for(i = 0; i < 5; i++)
	{
		if (masp == getpid())
		{
			pid_t p = fork();
			if (p == 0)
			{
				printf("%d PID: %d\t PPID: %d\n", i, getpid(), getppid());
			}
		}
	}
	if (masp == getpid())
	{
		int status = 0;
		waitpid(0, &status, 0);
		printf("Zakonczył czekanie \n");
	}
	return 0;
}


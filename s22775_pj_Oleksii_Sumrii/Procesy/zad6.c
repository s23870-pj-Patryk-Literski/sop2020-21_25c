#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h> 

int main()
{
	int i;
	for(i = 0; i < 10;i++)
	{
		if (fork() == 0)
		{
			printf("%d PID: %d\t PPID: %d\n", i, getpid() , getppid());
		}else{
			wait(NULL);
			printf("%d  Nie czeka \t Pid: %d\n", i, getpid());
			break;
		}
	}
	return 0;
}


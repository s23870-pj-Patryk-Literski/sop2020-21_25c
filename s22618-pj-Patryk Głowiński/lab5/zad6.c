#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int i;
	for(i = 0; i < 100; i++)
	{
 		pid_t = fork();
		if(pid == 0)
		{	
			printf("%d PID: %d\t PPID; %d\n",i ,getpid(), getppid());
		}else{
			wait(NULL);
			printf("%d Rodzic już nie czeka\t PID: %d\n", i, getpid());
		break;
		}
	
	}


return 0;
}	

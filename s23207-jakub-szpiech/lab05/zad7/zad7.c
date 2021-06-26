#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{

	int i;
	pid_t masterPID = getpid();
	for(i = 0; i < 10; i++)
	{	
		if (masterPID == getpid())
		{
			pid_t pid = fork();
			if(pid == 0)
			{
				printf("%d, PID: %d\t PPID: %d\n", i, getpid(), getppid());
				fflush(stdout);
			}
	
		}
	}
	if (masterPID == getpid())
	{
	/**	int status = 0;**/
		wait(NULL);
		/**waitpid(0, &status, 0);**/
		printf("Rodzic skonczyl czekac\n");
		fflush(stdout);
	}

	return 0;
}


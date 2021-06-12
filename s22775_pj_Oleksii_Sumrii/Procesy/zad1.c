#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("Pid: %d\t Ppid: %d\n", getpid(), getppid());
	return 0;
}


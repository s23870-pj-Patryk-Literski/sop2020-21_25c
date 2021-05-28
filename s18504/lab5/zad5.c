#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	int liczba = atoi(argv[1]);	
	pid_t pid = fork();	
	printf("PID: %d\t PPID: %d\n", getpid(), getppid());
	if (pid > 0)
	{	
		int i;
		int suma = 0;
		for(i = 0; i <= liczba; i++)
		{
			suma += i;

		}
		wait(NULL);
		printf ("SUMA: %d\n", suma);
	}else{
		int i;
		for(i = 1; i <= liczba; i = i + 2)
		{
			printf("Nieparzysta %d\n", i);
		}
	}
	return 0;
}


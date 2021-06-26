#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	pid_t pid = fork();
	printf("PID: %d\t PPID: %d\n", getpid(), getppid());
	if(pid > 0)
	{
		wait(NULL);
		printf("Koniec czekania\n");
	{
	return 0;
}

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	printf("Pid: %d\t ppid: %d\n", getpid(), getppid());
	if(pid > 0){
		wait(NULL);
		printf("Koniec czekania\n");
	}
	return 0;
}


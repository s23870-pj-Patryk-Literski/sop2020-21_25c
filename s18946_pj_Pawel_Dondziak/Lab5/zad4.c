#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int inputPID;
	pid_t pid = fork();
	
	if(pid>0){
		printf("parent PID: %d\tPPID: %d\n",getpid(),getppid());
		waitpid(0,&inputPID,0);
		printf("rodzic zakonczyl czekac na potomka\n");
	}else if(pid==0){
		printf("child PID: %d\tPPID: %d\n",getpid(),getppid());
	}else{
		printf("Nie udalo sie utorzyc procesu potomka\n");	
	}

        return 0;
}

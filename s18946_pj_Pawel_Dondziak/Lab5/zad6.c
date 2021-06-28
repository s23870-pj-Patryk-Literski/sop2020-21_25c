#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int i;
	
	for(i=0;i<100;i++){
		pid_t pid = fork();
		if(pid>0){
			wait(NULL);
			break;
		}
		else{
			printf("numer procesu: %d\tPID: %d\tPPID: %d\n",i,getpid(),getppid());
		}
	}
        return 0;
}

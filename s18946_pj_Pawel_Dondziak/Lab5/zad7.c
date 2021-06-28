#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int i=0,pidRODZIC=getpid();
	printf("pid rodzica glownego: ",pidRODZIC);
	for(i=0;i<100;i++){
		if(getpid()==pidRODZIC){
			if(fork()==0){
				printf("numer procesu: %d\tPID: %d\tPPID: %d\n",i,getpid(),getppid());
			}
		}
	}
	if(pidRODZIC == getpid()){
		int inputPID;
		waitpid(0,&inputPID,0);
		printf("rodzic zaczekal na zakonczenie innych procesow i sam sie zakonczyl");
		fflush(stdout);
	}

        return 0;
}

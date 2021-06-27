#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
	int inputPID;
	int liczba=atoi(argv[1]);
	pid_t pid = fork();
	
	if(pid>0){
		int suma=0,i;
		for(i=0;i<=liczba;i++){
			suma = suma + i;
		}
		waitpid(0,&inputPID,0);
		printf("RODZIC: suma liczb wynosi: %d\n",suma);
	}else if(pid==0){
		int i=0;
		for(i=1;i<=liczba;i=i+2){
			printf("DZIECKO: kolejna liczba nieparzysta %d",i);
		}
	}else{
		printf("Nie udalo sie utorzyc procesu potomka\n");	
	}

        return 0;
}
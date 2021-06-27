#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char **agrv){

    int i;
    for(i=0; i<10; i++){
        pid_t pid = fork();
        if(pid()==0)
            printf("PID: %d\t PPID: %d\n", i, getpid(), getppid());
        else{
            wait(NULL);
            printf("%d Rodzic juz nie czeka! PID: %d\n", i, getpid());
            break;
        }
    }    
    return 0;
}
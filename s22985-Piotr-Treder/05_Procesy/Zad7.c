#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main (){
    int i;
    pid_t masterPid = getpid();

    for( i = 0; i < 2; i++){

        if(masterPid == getpid()){
        pid_t p = fork();
                printf("%d Pid: %d\t ppid: %d\n",i , getpid(), getppid());
                fflush(stdout);
            } 
        
    

    return 0;
}
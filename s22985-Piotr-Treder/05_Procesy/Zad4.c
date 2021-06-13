#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main (){
    
    pid_t p = fork();
    
    printf("Pid: %d\t ppid: %d\n", getpid(), getppid());
    if (p > 0){
        wait(NULL);

        printf("Koniec \n");
    }
    return 0;
}
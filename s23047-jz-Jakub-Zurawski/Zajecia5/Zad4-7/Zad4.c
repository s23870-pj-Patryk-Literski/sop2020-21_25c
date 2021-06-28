#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    __pid_t Fork = fork();
    printf("PID: %d\t PPID: %d\n", getpid(), getppid());
    if(Fork > 0){
        wait(NULL);
        printf("Rodzic zakonczyl czekanie\n");
    }
    return 0;
}
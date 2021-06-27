#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    fork();
    printf("PID: %d, PPID: %d\n", getpid(), getppid());
    
    while(wait(NULL) > 0);

    return 0;
}
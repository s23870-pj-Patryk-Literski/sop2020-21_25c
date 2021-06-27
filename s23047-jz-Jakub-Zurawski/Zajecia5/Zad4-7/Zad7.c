#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char **agrv){

    int i;
    pid_t masterPID = getpid();
    for(i=0; i<100; i++){
        if(masterPID == getpid()){
            pid_t pid = fork();
            if(pid == 0){
                printf("PID: %d\t PPID: %d\n", i, getpid(), getppid());
                fflush(stdout);
            }
        }
    }
    if(masterPID == getpid()){
    int status = 0;
    /** waitpid(0, &status, 0); **/
    wait(NULL);
    printf("Rodzic zakonczyl czekanie!\n");
    fflush(stdout);
    }    
    return 0;
}
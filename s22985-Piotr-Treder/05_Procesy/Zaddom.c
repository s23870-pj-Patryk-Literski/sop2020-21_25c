#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    int i;
    pid_t masterPid = getpid();
        for(i = 0; i<10; i++){
            if (masterPid == getpid()){

            
                pid_t p = fork();
                if (p == 0){
                    printf("%d Pid: %d\t ppid: %d\n",i , getpid(), getppid());
                    
                }
            }
        }
       
    
    return 0;
}
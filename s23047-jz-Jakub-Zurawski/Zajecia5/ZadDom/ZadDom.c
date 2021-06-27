#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc ,char **argv){
    int i;
    for(i=0; i<3; i++){      
        pid_t pid = fork();
        if(pid == 0){            
            printf("%d Pid: %d\t  Ppid: %d\n",i,getpid(),getppid());    
            system("pstree");        
        }else{
            wait(NULL);
        }
    }
    return 0;
}
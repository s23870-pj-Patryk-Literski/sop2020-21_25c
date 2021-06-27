#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main (){
    
    int i;
    pid_t mastePid = getpid();
    for( i = 0; i < 10; i++){
        pid_t p = fork();
        if (mastePid == getpid()){
            
        
            if (p == 0){
                printf("%d Pid: %d\t ppid: %d\n",i , getpid(), getppid());
                fflush(stdout);
            } 
        }
    }
    if (mastePid == getpid()){
        int status = 0;
        waitpid(0, &status, 0);
        printf("Rodzić zakonczyl czekac na swoje dzieci\n");
        fflush(stdout);
    }
    
    
  
    return 0;
}
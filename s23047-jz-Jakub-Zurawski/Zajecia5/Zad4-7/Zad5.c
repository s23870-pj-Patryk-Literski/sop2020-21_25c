#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){

    int numbers = atoi(argv[1]);
    __pid_t Fork = fork();
    printf("PID: %d\t PPID: %d\n", getpid(), getppid());
    int i;
    if(Fork > 0){
        int sum = 0;
        for(i=0; i <= numbers; i++){
            sum += i;
        }
        wait(NULL);
        printf("Suma %d\n", sum);
    }else{
        for(i = 1; i <= numbers; i +=  2)
        printf("Liczba nieparzysta: %d\n", i);
    }
    return 0;
}
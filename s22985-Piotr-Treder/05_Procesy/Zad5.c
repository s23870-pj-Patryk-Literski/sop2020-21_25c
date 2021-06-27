#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main (int argc, char **argv){
    
    int liczba = atoi(argv[1]);
    pid_t p = fork();
    
    printf("Pid: %d\t ppid: %d\n", getpid(), getppid());
    if (p > 0){
        int i;
        int suma = 0;
        for(i = 0; i <= liczba; i++){
            suma += i;
        }
        wait(NULL);
        printf("Suma %d\n", suma);
    } else {
        int i;
        for (i = 1; i <= liczba; i = i + 2){
            printf("Nieparzysta %d\n", i);
        }
    }
    return 0;
}
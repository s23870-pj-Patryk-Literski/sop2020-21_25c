#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char ** argv) {
    int x = 0;
    int doLiczby = 0;
    int suma;

    if(argc != 2) {
        return 1;
    }
    
    doLiczby = atoi(argv[1]);

    if(fork() == 0) {
        printf("Dziecko:  \n");
        for(x = 1; x <= doLiczby; x+=2) {
            printf("%d \n", x);
        }
    } else {
        while(wait(NULL) > 0);

        for(x = 0; x <= doLiczby; x++) {
            suma += x;
        }

        printf("Rodzic: %d \n", suma);
    }

    return 0;
}
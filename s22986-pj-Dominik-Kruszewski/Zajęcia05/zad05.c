#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int x = 0;
    for(; x<=100; x++) {
        if(fork() == 0) {
            printf("Dziecko: %d \n", x);
            sleep(10);
            printf("Dziecko nie zyje: %d \n", x);
        }
    }
    return 0;
}
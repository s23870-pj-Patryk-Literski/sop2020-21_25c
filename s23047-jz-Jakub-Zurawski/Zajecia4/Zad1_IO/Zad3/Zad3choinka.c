#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
    int wiersze = 0;
    int aktualnyWiesz = 0;
    int aktualnyElement= 0;
    if(argc != 2)
        return 1;

    wiersze=atoi(argv[1]);
    printf("drukuje: %d\n", wiersze);
    for(; aktualnyWiesz < wiersze; aktualnyWiesz++){
        for(aktualnyElement = wiersze-aktualnyWiesz; aktualnyElement > 0; aktualnyElement--){
            printf(" ");
        }
        for(aktualnyElement = 0; aktualnyElement < (aktualnyWiesz*2)-1; aktualnyElement++){
            printf("*");
        }
        printf("\n");
    }
    return 0;

}
#include <stdio.h>

int main(int argc, char ** argv) {
    int wiersze = 0;
    int wiersz = 1;
    int element = 0;

    if(argc != 2) {
        return 1;
    }

    wiersze = atoi(argv[1]);
    
    
    for(; wiersz <= wiersze; wiersz++) {
        for(element = wiersze-wiersz; element > 0; element--){
            printf(" ");
        }

        for(element = 0; element < ((wiersz*2)-1); element++){
            printf("*");
        }

        printf("\n");    
    }

}
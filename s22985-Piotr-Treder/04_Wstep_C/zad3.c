#include<stdlib.h>
#include<stdio.h> 
int main(int argc, char** argv ){
    int wiersze = 0;
    int aktualnyWiersz = 0;
    int aktualnyElement = 0;
    if (argc != 2){
        return 1;
    }
    wiersze = atoi(argv[1]);
    printf("Drukuje choinke zlozona z wierszy: %d\n", wiersze);
    for(; aktualnyWiersz < wiersze ; aktualnyWiersz++){
        for(aktualnyElement = wiersze-aktualnyWiersz; aktualnyElement  > 0; aktualnyElement--){
            printf(" ");
        }
        for(aktualnyElement = 0; aktualnyElement < ((aktualnyWiersz*2)-1); aktualnyElement++){
        printf("*");
        }
        printf("\n");
    }


    return 0;
}
    
/* atoi <- asci to integer */
/* gcc -Wall -ansi -pedantic -o zad1 zad1.c */ 
/* int argc <- arg counter - ile argumentów zostalo przekazanych do programu */
/* char** argv <- arg value - warttość */
/* %d */
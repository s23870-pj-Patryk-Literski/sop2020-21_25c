#include<stdio.h> 
int main(){
    int suma = 0;
    int liczba = 0;

    while (scanf ("%d\n", &liczba) > 0 ){ 
        suma+=liczba;
    }
    printf("Suma = %d\n", suma);
    return 0;
}
/* gcc -Wall -ansi -pedantic -o zad1 zad1.c */ 

#include<stdio.h>

int main() {
    int liczba = 0;
    int suma = 0;

    while(scanf("%d", &liczba) > 0) {
        suma += liczba;
    }

    printf("Suma wprowadzonych liczb to %d\n", suma);

    return 0;
}
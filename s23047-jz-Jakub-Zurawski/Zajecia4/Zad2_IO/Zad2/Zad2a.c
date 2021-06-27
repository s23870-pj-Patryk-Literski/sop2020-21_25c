#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    printf("Podaj 4 cyfry: ");
    int *numbers[4];
    int i;
    for(i=0; i<4; i++){
        scanf("%d", &numbers[i]);
    }
}
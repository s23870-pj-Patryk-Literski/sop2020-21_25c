#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Ciag fibo bez rekurencja!*/
int main(){
    int n,i;
    int x=0, y=1, z;
    printf("Input how many numbers you want to print: ");    
    scanf("%d", &n);
    printf("Result: ");
    for(i=0; i<n; i++){
        z=x+y;
        x=y;
        y=z;
    printf("%d\t", z);
    }
    printf("\n");

    return 0;
}

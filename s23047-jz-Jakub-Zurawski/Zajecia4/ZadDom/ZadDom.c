#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Ciag fibo z rekurencja!*/
void fib(int n){
   static int x=0, y=1, z;
    if(n>0){
        z=x+y;
        x=y;
        y=z;                
        printf("%d\t",z);
        fib(n-1);
    }
}
int main(){
    int n;
    printf("Input how many numbers you want to print: ");
    scanf("%d",&n);
    printf("Result: \n");
    fib(n);
    printf("\n");

    return 0;
}
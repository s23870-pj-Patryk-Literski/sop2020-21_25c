#include <stdio.h>
#include <stdlib.h>


void arrayElements(int *tab, int quantity){       
    int i;
    for(i=0; i<quantity; i++){
        printf("Input value: %d\n",i);
        scanf("%d",&tab[i]);
    }
}
int minimum(int *tab,int quantity){
    int i;
    int min;
    min=tab[0];
    for(i=0; i<quantity; i++){
        if(tab[i]<min){
            min=tab[i];             
        }               
    }
    return min;
}
int maximum(int *tab,int quantity){
    int i;
    int max;
    max=tab[0];
    for(i=0; i<quantity; i++){
        if(tab[i]>max){
            max=tab[i];
        }
    }
    return max;
}
int suma(int *tab,int quantity){
	int i;
    int sum=0;
    for(i=0; i<quantity; i++){
        sum=sum+tab[i];
    }
    return sum;
}
int forAll(int *tab, int quantity , int (*function)(int *,int)){
    return function(tab, quantity);
}
int main(){
    int tab[10];   
    arrayElements(tab,10);
    printf("minimum: %d\n ", forAll(tab,10,minimum));
    printf("maximum: %d\n ", forAll(tab,10,maximum));
    printf("sum: %d\n ", forAll(tab,10,suma));
  
    return 0;
}

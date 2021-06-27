#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
    int i = 1;
    for(i = 1; i<argc; i++)
        printf("arg %d = %d\n", i, atoi(argv [i]));
    return 0;

}
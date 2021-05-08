#include<stdio.h>
#include<stdlib.h>


int main(int argc, char** argv){

if(argc != 2 || atoi(argv[1]) <= 0) {printf("error\n");return 1;}
if(atoi(argv[1]) == 1){printf("0\n"); return 0;}
if(atoi(argv[1]) == 2){printf("0 1\n"); return 0;}
 
int k[atoi(argv[1])];
k[0] = 0; k[1] = 1;
printf("%d %d ",k[0],k[1]);
reku(2, atoi(argv[1]), k);
printf("\n");
return 0;
}

int reku(int x, int y, int k[]){
	k[x] = k[x-1] + k[x-2];
	printf("%d ",k[x]);
	x++;
	if(x == y){return 0;}
	reku(x,y,k);
}


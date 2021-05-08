#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv){

if(argc != 2 || atoi(argv[1]) <= 0) {printf("error\n");return 1;}
if(atoi(argv[1]) == 1){printf("0\n"); return 0;}
if(atoi(argv[1]) == 2){printf("0 1\n"); return 0;}


int i = 2;
int k[atoi(argv[1])];
k[0] = 0; k[1] = 1;
printf("%d %d ",k[0],k[1]);
for (; i < atoi(argv[1]); i++){
	k[i] = k[i-1] + k[i-2];
	printf("%d ", k[i]);
	}


printf("\n");
return 0;
}

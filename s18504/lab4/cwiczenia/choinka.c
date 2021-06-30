#include<stdio.h>

int main(int argc, char **argv){
	if(argc != 2){return 1;}
	int wys = atoi(argv[1]);
	int i, j, k;
	for(i=1, k=1;k<= wys;i+=2,k++){
		for(j=(wys*2)-i;j>0;j-=2){
			printf(" ");
		}
		for(j=0;j<i;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

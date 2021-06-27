#include<stdio.h>

int main(int argc, char **argv){
	int x=0;
	int suma=0;
	int temp;
	for (x = 0; x < argc; x++){
		temp=atoi(argv[x]);
		suma+=temp;
	}
	printf("Suma to: %d\n", suma);
}

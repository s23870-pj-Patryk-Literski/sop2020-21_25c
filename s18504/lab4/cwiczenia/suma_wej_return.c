#include<stdio.h>

int main(int argc, char **argv){
	int x, temp;
	int suma=0;
	for (x = 0; x < argc; x++){
		temp=atoi(argv[x]);
		suma+=temp;
	}
	return suma;	
}


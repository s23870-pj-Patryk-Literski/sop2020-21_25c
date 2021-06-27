#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){
	FILE *file;
	char *filename;
	int numberOfLinesToRead = 0;
	int currentLine = 0;
	int *numbers;

	if (argc == 2){
		filename = argv[1];
		file =fopen(filename, "r");
	} else {
		file = stdin;
	}
	
	if (file == NULL) {
		fprintf(stderr,"Error while opening the file\n");
		return 1;
	}
	
	fscanf(file, "%d\n", &numberOfLinesToRead );
	
	printf("Lines to read: %d\n", numberOfLinesToRead );		

	numers = malloc(numberOfLinesToRead * sizeof(int));
	
	for(currentLine=0;currentLine<numberOfLinesToRead;currentLine++){
		int number = 0;
		fscanf(file, "%d\n", &number);
		numbers[currentLine] = number;
	}

	fclose(file);
		
	for(currentLine=numberOfLinesToRead; currentLine > 0; currentLine--){
		printf("n: %d\n", numbers[currentLine-1]);
	}	

	free(numers);
	return 0;
}
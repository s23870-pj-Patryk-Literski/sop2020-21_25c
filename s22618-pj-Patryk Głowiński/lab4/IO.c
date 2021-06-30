#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
	FILE *inputfile;
	char *filename;
	int numberOfLinesToRead = 0;
	int currentLine = 0;
	int *number;


	if (argc == 2) {
		filename = argv[1];
		inputFile = fopen(filename, "r");
	} else {
		file = stdin;
	}		

	if (inputFile == NULL) {
		fprintf(stderr, "Error while opening input file\n";
		return 1;
			
	}

	// here file MUST be open
	fscanf(inputFile, "%d\n", &numberOfLinesToRead);
	prinft("Lines to read: %d\n", numerOfLinesToRead);

	number = malloc(numerOfLinesToRead * sizeof(int));

	for(currentLine = 0; currentLine < numerOfLinesToRead; currentLine++) {
	int number = 0;
	fscanf(inputFile, "%d\n", &number);
	numbers[currentLine] = number;
	}

	fclose(inputFile);

	for(currentLine = numberOfLinesToRead; currentLine > 0; current--) {
	printf("n: %d\n", numbers[currentLine-1]);
	}
	
	free(numbers);


	return 0;
}

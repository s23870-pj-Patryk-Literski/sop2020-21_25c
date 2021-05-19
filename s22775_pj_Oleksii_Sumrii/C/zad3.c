#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv)
{
	FILE *myfile
	char *file
	int nrlines = 0;
	int line =0;
	int *nr;

	if (argc == 2) 
	{
		file = argv[1];
		myfile = fopen(file, "r");
	} else {myfile = stdin;}

	if (myfile == NULL) 
	{
		fprintf(stderr, "Bląd, nie ma plików");
		return 1;
	}

	fscanf(myfile,"%d\n", &nrlines);
	printf("Wierszy do przeczytania %d\n ", nrlines);

	nr = malloc(nrlines * sizeof(int));

	for(line = 0; line < nrlines; line++)
	{
		int num = 0;
		fscanf(myfile, "%d\n", &num);
		nr[line] = num;
	}

	fclose(myfile);

	for(line = nrlines; line > 0; line--)
	{
		printf("n: %d\n", nr[line-1]);
	}

	free(nr);

	return 0;
}


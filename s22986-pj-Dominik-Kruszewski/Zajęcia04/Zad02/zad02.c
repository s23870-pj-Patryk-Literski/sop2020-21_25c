#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
    FILE *inputfile;
    FILE *binFile;
    int x = 0;
    int linesToRead = 0;
    int *numbers;

    printf("%d %s \n", argc, argv[1]);

    inputfile = fopen("input.txt", "r");
    binFile = fopen("input.bin", "wb");

    if(inputfile == NULL || binFile == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku /n");
        return 1;
    }

    if(argc == 2) {
         if(argv[1] == "--print") {
            fread(numbers, sizeof(int), 1, binFile);
            printf("Plik: %d\n", numbers);
            return 0;
         }
    }

    fscanf(inputfile, "%d\n", &linesToRead);

    numbers = malloc(linesToRead * sizeof(int));

    for(x = 0; x < linesToRead; x++) {
        int temp = 0;
        fscanf(inputfile, "%d\n", &temp);
        numbers[x] = temp;
    }
    fclose(inputfile);
    
    fwrite(&numbers, sizeof(numbers), 1, binFile);
    fclose(binFile);

    free(numbers);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
    FILE *inputfile;
    int x = 0;
    int linesToRead = 0;
    int *numbers;


    if(argc == 2) {
        inputfile = fopen(argv[1], "r");
    } else {
        inputfile = stdin;
    }

    if(inputfile == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku /n");
        return 1;
    }

    fscanf(inputfile, "%d\n", &linesToRead);

    numbers = malloc(linesToRead * sizeof(int));

    for(x = 0; x < linesToRead; x++) {
        int temp = 0;
        fscanf(inputfile, "%d\n", &temp);
        numbers[x] = temp;
    }
    fclose(inputfile);
    
    for(x = linesToRead; x > 0; x--){
        printf("n: %d\n", numbers[x-1]);
    }

    free(numbers);

    return 0;
}
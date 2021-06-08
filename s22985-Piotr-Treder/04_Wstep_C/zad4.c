#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){
    FILE *inputFile; 
    char *filename;
    int numberOfLinesToRead = 0;
    int currentLine = 0;
    int *numbers;
    
    if ( argc == 2){
        filename = argv[1];
        inputFile = fopen(filename, "r");
    } else {
        inputFile = stdin;
    }

    if(inputFile == NULL) {
        fprintf(stderr, "Error while opening input file \n");
        return 1;
    }

    
    fscanf(inputFile, "%d\n", &numberOfLinesToRead);
    printf("Lines to read: %d\n", numberOfLinesToRead);

    numbers = malloc(numberOfLinesToRead * sizeof(int));

    for(currentLine = 0; currentLine < numberOfLinesToRead; currentLine++){
        int number = 0;
        fscanf(inputFile, "%d\n", &number);
        numbers[currentLine] = number;
    }
    fclose(inputFile);

    for(currentLine = numberOfLinesToRead; currentLine > 0; currentLine--){
        printf("n: %d\n", numbers[currentLine-1]);
    }

    free(numbers);

    
    
    
    
    return 0;
}

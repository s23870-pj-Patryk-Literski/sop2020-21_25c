#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){    
    FILE *inputFile;
    char *fileName;
    int numberOfLinesRead = 0;
    int currentLine = 0;
    int *numbers;
    if(argc == 2){
        fileName = argv[1];
        inputFile = fopen(fileName, "wb");
    }else {
        inputFile = stdin;
    }
    if(inputFile == NULL){
        fprintf(stderr, "Error while opening input file\n");
        return 1;
    }
    
    fwrite(inputFile, "%d\n", &numberOfLinesRead);    
    printf("Lines to read: %d\n", numberOfLinesRead);
    
    numbers = malloc(numberOfLinesRead * sizeof(int));
    for(currentLine = 0; currentLine < numberOfLinesRead; currentLine++){
        int number = 0;
        fwrite(inputFile, "%d\n", &number);
        numbers[currentLine] = number;
        size_t elements_written = fwrite(&number, sizeof(numbers), 1, inputFile);
        if(elements_written == 0){
            return 2;
        }
    }
    fclose(inputFile);
    for(currentLine = numberOfLinesRead; currentLine > 0; currentLine--){
        printf("n: %d\n", numbers[currentLine-1]);
    }
    free(numbers);

    return 0;

}
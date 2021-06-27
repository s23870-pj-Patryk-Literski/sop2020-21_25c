#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){    /* argc <- liczba argumentów wiersza poleceń z którymi program został wywołany */
                                    /* argv <- wskaźnik do tablicy ciągów znakowych, która zawiera argumenty, po jednym dla każdego przekazanego ciągu */
    FILE *inputFile;        /* zmienna inputFile, która jest wskaźnikiem do FILE */
    char *filename;         /* wskaźnik do obiektu typu char */
    int numberOfLinesToRead = 0;    
    int currentLine = 0;
    int *numbers;
    int i = 1;
    
    if ( argc == 2){        /* liczba przekazanych argumentów jest równa 2 */
        filename = argv[1]; /* ustawienie wskaźnika na pierwszy parametr ( zerowy to nazwa pliku ) */
        inputFile = fopen(filename, "r"); /* otwarcie pliku filename <- wskaźnika powyższego argv, "r" <- otwiera plik do czytania  */
    } else {
        inputFile = stdin;  /*  */
    }

    if(inputFile == NULL) {
        fprintf(stderr, "Error while opening input file \n"); /*  */
        return 1; /*  */
    }
    for( i = 1; i <= argc ; i++ ){
        if (i == argc){
            filename = argv[i];
            if (argv[2] == "--print"){
                filename = argv[1];
                inputFile = fopen(filename, "rb");
                if ( inputFile == NULL ){
                    fprintf(stderr, " Nie mozna otworzyc pliku.\n");
                    exit(1);
                }
            }
        }
    }
    
    fscanf(inputFile, "%d\n", &numberOfLinesToRead);        /*  */
    printf("Lines to read: %d\n", numberOfLinesToRead);     /*  */

    numbers = malloc(numberOfLinesToRead * sizeof(int));    /*  */

    for(currentLine = 0; currentLine < numberOfLinesToRead; currentLine++){  /*  */
        int number = 0;
        fscanf(inputFile, "%d\n", &number); /*  */
        numbers[currentLine] = number;      /*  */
    }
    fclose(inputFile);

    for(currentLine = numberOfLinesToRead; currentLine > 0; currentLine--){
        printf("n: %d\n", numbers[currentLine-1]);
    }

    free(numbers);

    
    
    
    
    return 0;
}

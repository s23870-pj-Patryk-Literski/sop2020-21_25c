#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){  
    FILE *file;
    if (argc == 2) {
        file = fopen(argv[1], "r");
        if ( file == NULL )
            fprintf(stdin, "File %s\" not found\n", argv[1]);
    }
    return 0;
}
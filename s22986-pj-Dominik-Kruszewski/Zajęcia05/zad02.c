#include <stdio.h>
#include <unistd.h>

int main() {
    printf("%d \n", getppid());

    for(;;)
    {
        ;
    }

    return 0;
}
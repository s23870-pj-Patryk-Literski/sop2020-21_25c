#include <stdio.h>
#include <unistd.h>

int main() {
    printf("%d \n", getpid());

    for(;;)
    {
        ;
    }

    return 0;
}
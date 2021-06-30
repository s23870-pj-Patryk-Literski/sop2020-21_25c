#include <stdio.h>
#include <unistd.h>

int main() {
        char input;
        printf("moj PID: %d\nmoj PPID: %d\n",getpid(),getppid());
        scanf("Dane: %s",&input);
        return 0;
}

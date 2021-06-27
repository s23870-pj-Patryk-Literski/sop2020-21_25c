#include <stdio.h>
#include <unistd.h>

int main() {
	printf("moj PID: %d\nmoj PPID: %d\n",getpid(),getppid());
	return 0;
}


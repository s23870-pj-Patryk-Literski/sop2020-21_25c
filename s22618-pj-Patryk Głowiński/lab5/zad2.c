#include <unistd.h>
#include <stdio.h>

	int main(){
	int x;

	printf("Pid: %d\t ppid : %d\n", getpid(), getppid());
	scanf("%d, &x");
	return 0;
}

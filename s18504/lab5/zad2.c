#include<unistd.h>
#include<stdio.h>

int main(){
	
	int x;
	printf("PID: %d\t PPID: %d\n", getpid(), getppid());
	scanf("%d", &x);
	return 0;
}


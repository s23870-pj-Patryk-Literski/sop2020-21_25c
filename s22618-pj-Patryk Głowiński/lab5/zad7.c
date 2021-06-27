#include<stdlib.h>
#include<stdio.h>
include<unistd.h>
#include<sys/wait.h>


int main(int argc ,char **argv){

         int i;
         pid_t masterpid = getpid();
         for(i=0; i<100; i++)
		{      
		if(masterpid == getpid())
                {
                pid_t pid = fork();
                if(pid == 0)
                {
                printf("%d Pid: %d\t  Ppid: %d\n",i,getpid(),getppid());
                fflush(stdout);
		}
                }
		}
		if(masterpid = getpid())
		{
                 wait(NULL);
                 printf("Koniec czekania\n");
                 fflush(stdout);

         }

        return 0;

}
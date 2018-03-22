
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>



int main()
{
    pid_t pid;
    pid = fork();
int cpid,ppid;
    if(pid<0)
    {
            printf("\nNO Parent or child process is present.");
            exit(0);
    }
    else if( pid > 0)
    {   
		ppid=getpid();
            wait(NULL);
            printf("\nPid for Parent process is : %d\n",ppid);
    }
    else if( pid == 0)
    {
                cpid=getpid();
                printf("\nExecuting Child process : ");
                execlp("/home/harshul/Desktop/Harshul/os/test","test",NULL);
                printf("%d",cpid);
    }
}

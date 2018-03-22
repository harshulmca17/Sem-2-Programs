#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>



int main()
{
    pid_t pid;
    pid = fork();
    if(pid<0)
    {
            printf("\nNO Parent or child process is present.");
            exit(0);
    }
    else if( pid > 0)
    {   
            wait(NULL);
            printf("\nI am  Parent\nPid for Parent process is : %d\n",pid);
    }
    else if( pid == 0)
    {
                 
                printf("\nExecuting Child process : ");
                 printf("%d",pid);
    }
}

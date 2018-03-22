#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<cstdlib>

using namespace std;

int main()
{
    pid_t pid;
    pid = fork();
int ppid,cpid;
    if(pid<0)
    {
            cout<<"\nNO Parent or child process is present.";
            exit(0);
    }
    else if( pid > 0)
    {
		ppid=getpid();
            cout<<"\nPid for Parent process is : "<<ppid<<"\n";
    }
    else if( pid == 0)
    {		cpid=getpid();
            cout<<"\nPid for Child process is : "<<cpid<<"\n";
    }
}

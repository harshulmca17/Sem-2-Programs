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
    if(pid<0)
    {
            cout<<"\nNO Parent or child process is present.";
            exit(0);
    }
    else 
    {
            cout<<"\nPid for process is : "<<pid<<"\n";
    }
    return 0;
}
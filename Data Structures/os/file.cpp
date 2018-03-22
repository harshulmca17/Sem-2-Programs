#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

using namespace std;
int main( int argc,char *argv[])
{
	if(argc!=3)
	{
		cout<<"\nInvalid Number of arguments supplied.";
		exit(1);
	}
  	int file_D1 = open(argv[1],O_RDONLY);
	if(file_D1 == -1)
	{
		cout<<"\nError in opening the required file.";
		exit(1);
	}
  	int file_D2 = open(argv[2],O_RDWR|O_CREAT,S_IRWXU);
	if(file_D2 == -1)
	{
		cout<<"\nError in creating the required file.";
		exit(1);
	}
	char buf[1024];
  	int count;
	while(count = read(file_D1,buf,sizeof(buf)))
	{
		if(count)
		{
			if(write(file_D2,buf,count)!=count)
			{
				cout<<"\nWriting Failed to the required file.";
				exit(1);
			}
		}
		else {
			
				cout<<"\nReading Failed from the required file.";
				exit(1);
		}
	}
	cout<<"\nCopying content from the file was successfully completed.";
	
	close(file_D1);
	close(file_D2);
	return 0;
}

#include<iostream>
#include<time.h>
#include<sys/stat.h>
#include<fcntl.h>

using namespace std;
int main(int argc,char *argv[])
{
    struct stat buffer;
    time_t atime,modtime;
    int size,i;
    int status;
    if(argc<2)
	cout<<"\nFilename is needed";
    for(i=1;i<argc;i++)
    {
      status=stat(argv[i],&buffer);
      cout<<"\n"<<argv[i];
      if(status < 0)
	  cout<<"\nError in obtaining stats";
      else if(status == 0)
      {
	  size = buffer.st_size;
	  cout<<"\nSize of file in bytes is "<<size;
	  atime=buffer.st_atime;
	  modtime=buffer.st_mtime;
	  cout<<"\nLast time when the file is accessed is "<<atime;
	  cout<<"\nLast time when the file data was modified is "<<modtime;
	  cout<<"\nFile permission are as follows:\t\t";
	  cout<<(S_ISDIR(buffer.st_mode)?"d":"-");
	  cout<<(buffer.st_mode & S_IRUSR?"r":"-");
	  cout<<(buffer.st_mode & S_IWUSR?"w":"-");
	  cout<<(buffer.st_mode & S_IXUSR?"x":"-");
	  cout<<(buffer.st_mode & S_IRGRP?"r":"-");
	  cout<<(buffer.st_mode & S_IWGRP?"w":"-");
	  cout<<(buffer.st_mode & S_IXGRP?"x":"-");
	  cout<<(buffer.st_mode & S_IROTH?"r":"-");
	  cout<<(buffer.st_mode & S_IWOTH?"w":"-");
	  cout<<(buffer.st_mode & S_IXOTH?"x":"-");
	  cout<<"\n";
	
      }
    }
}
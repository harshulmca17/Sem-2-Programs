#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void cpuInfo()
{
    system("awk 'NR == 1, NR == 5 {print $0} ' /proc/cpuinfo");  
}
void memInfo()
{
    system("awk 'NR == 4 {print} ' /proc/meminfo");  
}
void version()
{
    system("awk '{print $0} ' /proc/version");  
}
int main()
{
  system("clear");
  int ch;
  printf("\nMenu..");
  printf("\nPress 1 To Print CPU info.");
  printf("\nPress 2 To Print Memory info.");
  printf("\nPress 3 To Print Version info.");
  printf("\nPress 4 To Print Exit.");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:{
	    system("clear");
	    printf("\nCpu Info\n\n");
	    cpuInfo();
	    break;}
    case 2:{ 
	    system("clear");
	    printf("\nMemory Info\n\n");
	      memInfo();
	      break;
    }
    case 3:{
	    system("clear");
	    printf("\nVersion\n\n");
	    version();
	    break;}
    case 4:{
	    system("clear");
	    exit(0);
    }
  }
  return 0;
  
}

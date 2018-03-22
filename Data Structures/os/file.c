#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    FILE *from , *to;
    char ch;
    
    if(argc!=3)
    {
      printf("\nUsage: Copy\n");
      exit(1);
    }
    
    if((from = fopen(argv[1],"rb"))==NULL){
      printf("Cannot Open Source File.\n");
      exit(1);
      
    }
    
    if((to = fopen(argv[2],"wb")) == NULL){
      printf("Cannot Open Destination File.\n");
      exit(1);
    }
    while(!feof(from)){
      ch = fgetc(from);
      if(ferror(from)){
	printf("Error reading source file.\n");
	exit(1);
      }
      if(!feof(from)) fputc(ch,to);
      if(ferror(to)){
	printf("'nError riting Destination File.\n");
	exit(1);
      }
      
    }
    
    if(fclose(from) == EOF){
      printf("\nError Closing Source File.\n");
      exit(1);
    }
    if(fclose(to) == EOF){
      printf("ERROR Closing Destination File.\n");
      exit(1);
    }
      printf("\nFile Copyied Successfully.\n");
      return 0;
    
}
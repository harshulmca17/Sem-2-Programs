#include<pthread.h>
#include<stdio.h>

int sum;

void *runner (void *para)
{
    int upper = atoi ((char*)para);
    int i;
    sum = 0;
    if(upper > 0){
	 for(i=1;i <= upper;i++)
	   sum += i;
    }
    pthread_exit(0);
}
  
int main(int argc,char *argv[])
{
  pthread_t tid;
  pthread_attr_t attr;
 if(argc != 2){
   fprintf(stderr,"usage: a.out <Integer Value>\n");
 exit(1);
 }
  if (atoi(argv[1]) < 0){
    fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
    exit(1);
  }
  pthread_attr_init(&attr);
  pthread_create(&tid,&attr,runner,argv[1]);
  pthread_join(tid,NULL);
  printf("sum = %d\n",sum);
 }
  

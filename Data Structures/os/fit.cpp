#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;
void enter(int *pro,int *mem,int sizeM)
{
	cout<<"\nEnter Total No. of Memory Segments:";
	cin>>sizeM;
	mem = new int [sizeM];
	cout<<"\nEnter Size of each memory segment.\n";
	for(int i=0;i<sizeM;i++)
	{
		cout<<"\nM"<<i+1<<": ";cin>>mem[i];
	}
	pro = new int [sizeM];
	cout<<"\nEnter Memory Requirment for each process.\n";
	for(int i=0;i<sizeM;i++)
	{
		cout<<"\nP"<<i+1<<": ";cin>>pro[i];
	}
}

void firstFit(int *p,int *m,int sm){
	cout<<"****************************\n\tFirst Fit.\n";
	  int count=0;
	while(count <= sizeM)
	{
	 
	  
	}
}

void bestFit(int *p,int *m,int sm){
	cout<<"****************************\n\tBest Fit.\n";

	
}

void worstFit(int *p,int *m,int sm){
	cout<<"****************************\n\tWorst Fit.\n";

}

void fit(int *p,int *m,int sm)
{
	firstFit(p,m,sm);
	bestFit(p,m,sm);
	worstFit(p,m,sm);
}

void start()
{
	system("clear");
	cout<<"\n\n\t\t\t\t\tProcess Allocation in Memory Segments.\n\n";
}
int  main()
{	
	
	int *pro,*mem,sizeM;
	start();
	enter(pro,mem,sizeM);
	fit(pro,mem,sizeM);
	return 0;
}

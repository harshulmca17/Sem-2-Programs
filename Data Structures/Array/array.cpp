#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<unistd.h>

using namespace std;

class array
{

        int *arra;
        public:
        int size;
        array()
        {
                size=0;
                arra=new int[size];
                for(int i=0;i<size;i++)
                        arra[i]=-1;
        }
        array(int i)
	{
	    size=i;
	    arra=new int[size];
	    for(int i=0;i<size;i++)
                        arra[i]=-1;	    
	}
        array(array &ob)
        {
                size=ob.size;
                arra=new int[size];
                for(int w=0;w<size;w++)
                arra[w]=ob.arra[w];

        }
        void fillarray();
        void searcharray();
        void mdfyarray();
        void showarray();
	void selectsort();
	void bubblesort();
	void insertsort();
        void linearsearch();
	void binarysearch();
	array operator+(array &);
        int operator==(array &);
        array operator=(array &ob)
        {
                size=ob.size;
                for(int r=0;r<size;r++)
                        arra[r]=ob.arra[r];
                return *this;

        }
        ~array()
	{
	  cout<<"\nProgram Terminated Normaly.\n";
	}
};

void array::linearsearch()
{
  int key,count=0;
  cout<<"\nEnter the Key Element : ";
  cin>>key;
    for(int i=0;i<size;i++)
    {
      if(key==arra[i])
	count++;
    }
    if(count)
    {  
      cout<<"\nElement Present : ";
      cout<<"\nTotal Number of times : "<<count;
    }
      else
      cout<<"\nCannot Find Elementy in the Respected Array.";
      
}
void array::binarysearch()
{
    int key,count=0,first,last,mid;
    cout<<"\nEnter the Key Element : ";
    cin>>key;
    first=0;
    last=size-1;
    mid=(first+last)/2;
    while(first<=last && arra[mid]!=key)
    {
      
     if(arra[mid]>key)
      last=mid-1;
     else if(arra[mid]<key)
       first=mid+1;
     mid=(first+last)/2;
    }
    if(arra[mid]==key)
      cout<<"\nElement Present : ";
    else
      cout<<"\nCannot Find Elementy in the Respected Array.";
    
}

void array::bubblesort()
{ 
	  array *sorted = new array[size];
	  sorted=this;
	
	for(int i=0;i<size;i++)
	      {
		for(int j=0;j<size-i-1;j++)
		{
		  if(sorted->arra[j+1] < sorted->arra[j])
		  {
		    swap( sorted->arra[j+1], sorted->arra[j] );
		  }
		}
	      }
	      
}	
void swap(int& a, int& b)
{ 
    int temp;
    temp=a;
    a=b;
    b=temp;
}
	
	
void array::selectsort()
{
  	  array *sorted=new array[size];
	  sorted=this;

	for(int i=0;i<size-1;i++)
	{
	  int minlocation=i;
		for(int j=i+1;j<size;j++)
		{
		    if(sorted->arra[j] < sorted->arra[minlocation])
		    {
		    minlocation=j;
		    }
		}
		swap( sorted->arra[i],sorted->arra[minlocation] );
	 }
  
}	
void array::insertsort()
{ 
	array *sorted=new array[size];
	sorted=this;
	for(int i=1;i<size;i++)
	{
		int j=i;
		int temp;
		temp = sorted -> arra[i];
		while( (temp < sorted->arra[j-1]) && (j>0) )
 		{
			 // sorted->arra[j]=sorted->arra[j-1];
			swap(sorted->arra[j],sorted->arra[j-1]);  
		      j--;
		}
		//sorted->arra[j]=temp;
	}
}	

void array::showarray()
{
	cout<<"\n\nRespected Array Is:";
	for(int e=0;e<size;e++)
	{	
	  cout<<arra[e];
	  cout<<"\t";	  
	}
	
}
void array::fillarray()
{
	cout<<"\nEnter the Size of the array:";
	cin>>size;int temp;
	cout<<this->size<<"\n";
	cout<<"\nEnter "<<size<<" Elements in the array:";
	for(int j=0;j<size;j++)
	{
		cout<<j<<":";
		cin>>temp;
		arra[j]=temp;
	}
}
void array::searcharray()
{
	int m;
	cout<<"\nINDEX\tELEMENT";
	for(int k=0;k<size;k++)
		cout<<"\n"<<k<<"\t"<<arra[k];
	
	cout<<"\nEnter Index No. To Retrieve A Specific Element:";
	cin>>m;

	if(m>size)
	{
		cout<<"\n\n\t\tINVALID INPUT";
	}
	else 
	{
		cout<<"\nRetrieved Element is "<<arra[m];
	}
}
void array::mdfyarray()
{
	int m;
	cout<<"\nINDEX\tELEMENT";
	for(int l=0;l<size;l++)
		cout<<"\n"<<l<<"\t"<<arra[l];
	cout<<"\nEnter Index No. To Modify A Specific Element:";
	cin>>m;
	if(m>size)
	{
		cout<<"\n\n\t\tINVALID INPUT";
	}
	else 
	{	int a=arra[m]*arra[m];
		arra[m]=a;
		cout<<"\nModified Element is \n"<<a;
	}
}
array array::operator+(array &ob)
{
        for(int i=0;i<size;i++)
                arra[i]+=ob.arra[i];
        return *this;
}
int array::operator==(array &ob)
{
        int c;
        for(int i=0;i<size;i++)
                if(arra[i]==ob.arra[i])
                        c=0;
                else
                        c=1;
        return c;
}
int main()
{
        array ob;
        int n;
        char ch;
        do{
                cout<<"\nPress 1 To Fill Array ";
                cout<<"\nPress 2 To Search for a specific Element";
                cout<<"\nPress 3 To Modify ( REPLACE BY ITS SQUARE ) a specific Element:";
                cout<<"\nPress 4 To Call Copy Constructor ";
                cout<<"\nPress 5 To Call Assignment Operator";
                cout<<"\nPress 6 To Call Addition Operator";
                cout<<"\nPress 7 To Call Equality Operator";
		cout<<"\nPress 8 To Use Selection Sorting ";
                cout<<"\nPress 9 To Use Bubble Sorting ";
		cout<<"\nPress 10 To Use Insertion Sorting ";
		cout<<"\nPress 11 To Search Using Linear Method";
		cout<<"\nPress 12 To Search Using Binary Method";
		cout<<"\nPress 13 To Exit.";
                cin>>n;

                switch(n)
                {
                        case 1: ob.fillarray();
                                break;
                        case 2: ob.searcharray();
                                break;
                        case 3: ob.mdfyarray();
                                break;

				
			 case 4: {
                                        array ob1(ob);
                                        ob1.showarray();
                                }
                                break;
				
                        case 5: {       array ob2;
                                        (ob2.operator=(ob)).showarray();
                                }
                                break;
				
                        case 6: {       array ob2;
                                        ob2.fillarray();
                                        (ob2.operator+(ob)).showarray();
                                }
                                break;
				
                        case 7:{        array ob2;
                                        ob2.fillarray();
                                        if(!(ob2.operator==(ob)))
                                                cout<<"\nGiven Arrays Are Equal";
                                        else
                                                cout<<"\nGiven Arrays Are Not Equal";
                                }
                                break;
				
                        case 8:  ob.showarray();
			 	 ob.selectsort();
				 ob.showarray();
				 break;
			
			case 9:  ob.showarray();
				 ob.bubblesort();
				 ob.showarray();
				 break;
			
			case 10: ob.showarray();
				 ob.insertsort();
				 ob.showarray();
				 break;
			
			case 11: ob.selectsort();
				 ob.linearsearch();
				 break;
			
			case 12: ob.selectsort();
				 ob.binarysearch();
				 break;
			case 13:exit(0);

                        default:cout<<"\n\n\t\tINVALID INPUT";
                }
                cout<<"\nWould You Like to Continue..('Y'es,'N'o)";
                cin>>ch;
        }while(ch=='y'||ch=='Y');
	cout<<"\nPlease Waite While Program Is Exiting.";
	cout<<"\n";
	if(ch=='n')
	  sleep(3);
        return 0;
}
                                                                                                                              

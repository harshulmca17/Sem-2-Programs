#include<iostream>
using namespace std;
int arr[10],l,u,i,j;
void quick(int *,int,int);
int main()
{
    int n;
    cout<<"\nEnter Size of Array : ";
    cin>>n;
    cout <<"\nEnter  elements :";
    for(i=0;i<n;i++)
    cin >> arr[i];
    l=0;
    u=3;
    quick(arr,l,u);
    cout <<"\nSorted elements :";
    for(i=0;i<n;i++)
      cout << arr[i] << " ";
}

void quick(int arr[],int l,int u)
{
   int p,temp;
   if(l<u)
   {
      p=arr[l];
      i=l;
      j=u;
      while(i<j)
      {
	  while(arr[i] <= p && i<j )
	      i++ ;
	  while(arr[j]>p && i<=j )
	      j--;
	  if(i<=j)
	    {
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	  }
    }
    temp=arr[j];
    arr[j]=arr[l];
    arr[l]=temp;
    cout <<"\n";
  //  for(i=0;i<4;i++)
	//cout <<arr[i]<<" ";
    quick(arr,l,j-1);
    quick(arr,j+1,u);
 }
}


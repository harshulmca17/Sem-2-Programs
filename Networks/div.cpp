#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void Start()
{
        system("clear");
        cout<<"\t\t\t\tBINARY DIVISION\n\n";
}
void dXor(int *a,int *b,int n,int sizea)
{       
        int cntr;
        for(cntr=0;a[cntr]==0;cntr++);
            
        cntr++;
        int k=0;
        while((cntr)<(n-sizea+1)){
                //int cntr=0;
          //      q[k]=1;
                for(int i=0;i<sizea;i++)
                {
                    if(a[cntr+i]==b[i])
                        a[cntr+i]=0;
                    else if(a[cntr+i]!=b[i])
                        a[cntr+i]=1;
                }
                for(cntr=0;a[cntr]==0;cntr++);
                
        }
        cout<<"\nRemainder:";for(int i=0;i<n;i++) cout<<a[i];
        cout<<"\n";
}
int main()
{   
        int *a,*b,*c,*q,*r,size,sizea;
        Start();
        cout<<"\nEnter the size of Divident: ";
        cin>>size;
        cout<<"\nEnter the size of Divisor: ";
        cin>>sizea;
        a = new int [size];
        b = new int [sizea];
        cout<<"\nEnter:\n";
        cout<<"\nDividend:";for(int i=0;i<size;i++) cin>>a[i];
        
        cout<<"\nDivisor:";for(int i=0;i<sizea;i++) cin>>b[i];
        dXor(a,b,size,sizea);
        return 0;
    
}
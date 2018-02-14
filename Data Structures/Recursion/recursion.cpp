#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;


int factorial(int element)
{	
  
  if(element==1)
    return element;
  else 
  {
    return (element*factorial(element-1));
  }
}
int fibonacci(int n)
{
  if(n==0)
    return (0);
  
  else if(n==1)
    return (1);
  else    
    return fibonacci(n-1)+fibonacci(n-2);
  
}
int multiplication(int a,int b)
{
  if(b == 0 || a == 0)
    return 0;
  else if(b == 1)
    return a;
  else if(a == 1)
    return b;
  else 
    return a+multiplication(a,b-1);
}
int gcd(int a,int b)
{	
  
  if(b%a==0)
    return a;
  else 
  {
    return gcd((b/a),a);
  }
  
}

int power(int a,int b)
{	

  if(b == 1)
    return a;
  
  else 
    return a*power(a,b-1); 
}

int main()
{	int ch,element,a,b,c;
	char chh;
	do{
	    cout<<"\nPress 1 To Calculate Factorial. ";
	    cout<<"\nPress 2 To Print Fibonacci Series.";
	    cout<<"\nPress 3 To Multiply Two No. .";
	    cout<<"\nPress 4 To Calculate GCD of Two Numbers. ";
	    cout<<"\nPress 5 To Calculate X to the power Y.";
	    cout<<"\nPress 6 To Exit:";
	    cin>>ch;
	    switch(ch)
	    {
		case 1: cout<<"\nEnter Element:";
			cin>>element;
			a=factorial(element);
			cout<<"\n"<<a;	
			break;
	
		case 2: cout<<"\nEnter Length of the factorial Series:";
			cin>>a;
			for(int i=0;i<a;i++)
			cout<<fibonacci(i);
			break;
			
		case 3: cout<<"\nEnter Two Numbers.";
			cin>>c>>b;
			a=multiplication(c,b);
			cout<<"\nResult "<<a;
			break;
			
		case 4: cout<<"\nEnter Two Numbers:";
			cin>>c>>b;
			
			if(c<b)
			  a=gcd(c,b);
			else 
			  a=gcd(b,c);
			
			cout<<"\nResult "<<a;
			break;
		case 5:	cout<<"\nEnter Number:";
			cin>>c;
			cout<<"\nEnter Power:";
			cin>>b;
			a=power(c,b);
			cout<<"\nResult : "<<a;
			break;
		case 6: exit(0);
	    }
	    cout<<"\nWould You Like To Continue.('Y'es,'N'o).";
	    cin>>chh;
	  }while(chh=='Y'||chh=='y');
	  return 0;
}
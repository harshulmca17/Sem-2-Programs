#include<iostream>
#include<string.h>
#include<cstdlib>
#include<cstdio>

using namespace std;

void	infix_to_postfix(char* , int);
void	postfix_to_infix(char* , int);
bool 	isoperand(char );
bool 	isoperator(char );
bool 	checkhigher(char , char );

class Stack
{
	char *array;
	
	public :
	
		int length;
		int top;
		Stack(int length1 = 0)
		{
				top = -1;
				length = length1;
				array = new char[length];
		}
		bool isEmpty()
		{
			if(top != -1)
				return false;
			else
				return true;
		}
		bool isFull()
		{
			if( top != (length-1))
				return false;
			else
				return true;
		}
		void push(char element)
		{
			if(isFull())
			{
				cout<<"Stack is full.";
			}
			else
			{
				top++;
				array[top] = element;
			}
		}
		
		char pop()
		{
			int i ;
			char* msg;
			if(isEmpty())
			{
			  throw " Stack is Empty. ";
			}
			else
			{
				i = array[top];
				top--;
			}
			return i;
		}
		char elementAtTop()
		{
			char* msg; 
			if(isEmpty())
			{
			 throw " Stack is Empty. ";
			}
			else
			{
			 	return array[top];
			}
		}
		void clearStack()
		{
			top = -1;
		}
		void display(int j)
		{
			if(isEmpty())
			{
				cout<<"\nStack is Empty.";
			}
			else
			{
				if(j==1)
				  for(int i = 0 ; i <=top ; i++)
				  {
					  cout<<array[i];
				  }
				 else if(j==2)
				  for(int i = top ; i >=0 ; i--)
				  {
					  cout<<array[i];
				  }
			  
			}
		}
};


void infix_to_postfix(char* infix, int length)
{
	Stack operandObj(length);
	Stack operatorObj(length/2);
	for(int i = 0; i <length ; i++ )
	{
		if(isoperand(infix[i]))
		{
			operandObj.push(infix[i]);
		}
		else 
		{
			if(isoperator(infix[i]))
			{
				if(operatorObj.isEmpty())
				{
					operatorObj.push(infix[i]);
				}
				else 
				{
					if(checkhigher(infix[i],operatorObj.elementAtTop()))
					{
						operatorObj.push(infix[i]);
					}
					else
					{
						do
						{
							operandObj.push(operatorObj.pop());
						}
						while((!operatorObj.isEmpty()) && (!checkhigher(infix[i], operatorObj.elementAtTop())));
						operatorObj.push(infix[i]);
					}
				}
			}
		}
	}
	while(!operatorObj.isEmpty())
	{
		operandObj.push(operatorObj.pop());
	}
	cout<<"\nPostfix Expression is :";
	operandObj.display(1);
	
}
void postfix_to_infix(char* postfix, int length)
{
	Stack operandObj(length);
	Stack infix(length);
	Stack operatorObj(length/2);
	for(int i=length-1;i>=0;i--)
	{
	  
	   if(isoperand(postfix[i]))
	  {
	    operandObj.push(postfix[i]);
	    if(i)
	    operandObj.push(operatorObj.pop());
	    
	    
	    
	  }
	  else if(isoperator(postfix[i]))
	  {
	    operatorObj.push(postfix[i]);
	  } 
	  
	}
	cout<<"\nInfix Expression Is: ";
	operandObj.display(2);
	
	

}
void evaluation(char* postfix, int length)
{
      Stack operatorObj(length/2);
      Stack operandObj(length);
      int ch;
      cout<<postfix;
      int r,k=0;
      int *operand;
      operand = new int[length/2];
      for(int j=0;j<length;j++)
      {
	if(isoperand(postfix[j]))
	{
	  cout<<"\nEnter the VAlue For "<<postfix[j]<<" : ";
	  cin>>ch;
	  operand[k]=ch;
	  k++;
	}
	else if(isoperator(postfix[j]))
	{
	    
	    if(postfix[j]=='+')
	    {	
	        operand[k-2]=operand[k-2]+operand[k-1];
		
	    }
	    else if(postfix[j]=='-')
	    {	operand[k-2]=operand[k-2]-operand[k-1];
	    }
	    else if(postfix[j]=='*')
	    {	operand[k-2]=operand[k-2]*operand[k-1];
	    }
	    else if(postfix[j]=='/')
	    {	operand[k-2]=operand[k-2]/operand[k-1];
	    }
	    k--;
	  
	}
	  
	    
      }      cout<<"\nEvaluated Result Is : ";
	      cout<<operand[0];
}
bool isoperand( char c )
{
	if((c>='a' && c<='z')||(c>='A' && c<='Z'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isoperator(char c)
{
	if((c == '+')||(c == '-')||(c == '/')||(c == '*'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool checkhigher(char op1, char op2)
{
	if(((op1 == '+')||(op1 == '-')) && ((op2 == '+')||(op2 == '-')))
	{
		return false;
	}
	else if(((op1 == '*')||(op1 == '/')) && ((op2 == '*')||(op2 == '/')))
	{
		return false;
	}
	else if(((op1 == '+')||(op1 == '-')) && ((op2 == '*')||(op2 == '/')))
	{
		return false;
	}
	else 
	{
		return true;
	}
}
int main()
{
	char * infix = new char[20];
	int length;
	int ch;
	char chh;	
	do{
	      cout<<"\nPress 1 To Convert Infix --> Postfix.";
	      cout<<"\nPress 2 To Convert Postfix --> Infix.";
	      cout<<"\nPress 3 To Evaluate Postfix Expression.";
	      cout<<"\nPress 4 To Exit:";
	      cin>>ch;
	      switch(ch)
	      {
			case 1: 	cout<<"Enter the Infix Expression :  ";
					cin>>infix;
					length = strlen(infix);
					infix_to_postfix(infix,length);
					break;
			case 2:		cout<<"Enter the Postfix Expression :  ";
					cin>>infix;
					length = strlen(infix);
					postfix_to_infix(infix,length);
					break;		  
			  
			case 3:		cout<<"Enter the Postfix Expression :  ";
					cin>>infix;
					length = strlen(infix);
					evaluation(infix,length);
					break;		  

			  
			case 4:		exit(0); 
			 
	    
	      }
	 
	      cout<<"\nWould You Like To Continue..('Y'es,'N'o).";
	      cin>>chh;
	}while(chh=='y'||chh=='Y');
	    return 0;

}

#include<iostream>
#include<string.h>
#include<cstdlib>
#include<cstdio>

using namespace std;

char * infix_to_prefix(char* , int);
void prefix_to_infix(char* , int);
bool isoperand( char );
bool isoperator(char );
bool checkhigher(char , char );

class Stack
{
	char *array;
	int length;
	public :
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
			char i ;
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
		void display()
		{
			if(isEmpty())
			{
				cout<<"\nStack is Empty.";
			}
			else
			{
				
				for(int i = 0; i <=top ; i++)
				{
					cout<<array[i];
				}
			}
		}
  
};


char* infix_to_prefix(char* infix, int length)
{
	Stack operandObj(length);
	Stack operatorObj(length/2);
	for(int i = (length-1); i >=0 ; i-- )
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
	char* prefix = new char[length];
	int i = 0;
	while(!operandObj.isEmpty())
	{
		prefix[i++] = operandObj.pop();
	}
	prefix[i] = '\0';
	return prefix;
}
void prefix_to_infix(char* prefix, int length)
{
	Stack operandObj(length);
	Stack infix(length);
	Stack operatorObj(length/2);
	for(int i=0;i<length;i++)
	{
	  
	   if(isoperand(prefix[i]))
	  { 
	    operandObj.push(prefix[i]);
	    if(i!=(length-1))
	    {
		char ch;
		ch=operatorObj.pop();
		operandObj.push(ch);
		
		
	    }
	    
	    
	  }
	  else if(isoperator(prefix[i]))
	  {
	    operatorObj.push(prefix[i]);
	  } 
	  
	}
	cout<<"\nInfix Expression Is: ";
	operandObj.display();
	
	

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
		return true;
	}
	else if(((op1 == '*')||(op1 == '/')) && ((op2 == '*')||(op2 == '/')))
	{
		return true;
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
	      cout<<"\nPress 1 To Convert Infix --> Prefix.";
	      cout<<"\nPress 2 To Convert Prefix --> Infix.";
	      cout<<"\nPress 3 To Exit:";
	      cin>>ch;
	      switch(ch)
	      {
			case 1: 	cout<<"Enter the Infix Expression :  ";
					cin>>infix;
					length = strlen(infix);
					cout<<"\n\nPrefix Expression is :  "<<infix_to_prefix(infix,length);
					break;
			case 2:		cout<<"Enter the Infix Expression :  ";
					cin>>infix;
					length = strlen(infix);
					prefix_to_infix(infix,length);
					break;		  
			case 3:		exit(0); 
			 
	    
	      }
	 
	      cout<<"\nWould You Like To Continue..('Y'es,'N'o).";
	      cin>>chh;
	}while(chh=='y'||chh=='Y');
	    return 0;

}

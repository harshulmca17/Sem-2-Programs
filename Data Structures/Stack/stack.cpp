#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

class Stack
{
	int* array;
	int top;
	int lenght;

	public:	
	Stack(int _lenght=0)
	{
		lenght=_lenght;
		array=new int[lenght];
		top=-1;
	}
	void push(int element)
	{
		if(!isfull())
			return;
		else 
		{
			top++;
			array[top]=element;
			
		}
	}
	int pop();
	bool isempty();
	bool isfull();
	int elementAtTop();
	void clearStack();
	void display();
};

int Stack::pop()
{
	if(!isempty())
		return 0;
	else 
	{
		int t=array[top];
		array[top]='\0';		
		top--;
		return t;
	}
}
bool Stack::isempty()
{
	if(top==-1)
	{
		cout<<"\nStack Is Empty";
		return 0;
	}
	else 
		return 1;
}
bool Stack::isfull()
{
	if(top==lenght)
	{
		cout<<"\nStack Is Full";
		return 0;
	
	}
	else 
		return 1;
}
int Stack::elementAtTop()
{
	return array[top];
}
void Stack::clearStack()
{
	if(isempty())
	top=-1;
}
void Stack::display()
{
	for(int i=top;i>=0;i--)
		cout<<endl<<i<<" = "<<array[i];
}
int main()
{
	Stack ob(8);
	int ch;
	char chh='y';
	while(chh=='y'||chh=='Y'){	
		int element;
		cout<<"\nPress 1 To Enter New Element In Stack.";
		cout<<"\nPress 2 To Delete Last Entred Element From Stack.";
		cout<<"\nPress 3 To Show Last Entred Element.";
		cout<<"\nPress 4 To Delete All Elements Of Stack.";
		cout<<"\nPress 5 To Display All Elements Of Stack.";	
		cout<<"\nPress 6 To Exit.";
		cin>>ch;
				
		switch(ch)
		{
			case 1:	{cout<<"\nEnter Element.";
				cin>>element;
				ob.push(element);}
				break;
			case 2: {element=ob.pop();
				cout<<"\nDeleted Element -> "<<element;}
				break;
			case 3: {element=ob.elementAtTop();
				cout<<"\nLast Entred Element -> "<<element;}
				break;
			case 4: ob.clearStack();
				break;
			case 5: ob.display();
				break;
			case 6: exit(0);
		
		}

		cout<<"\nWould You Like To Continue.....('Y'es/'N'o).";
		cin>>chh;
	}
	return 0;
}

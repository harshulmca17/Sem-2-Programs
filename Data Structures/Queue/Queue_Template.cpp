#include<iostream>
#include"Circular_Queue.h"
#include"Double_Ended.h"
#include"Queue.h"

using namespace std;

void queue();
void Cqueue();
void Dqueue();

int main()
{
	int choice;
	char ch;
	do
	{
		cout<<"\n-----------MENU-------------";
		cout<<"\n(1) Simple Queue.";
		cout<<"\n(2) Circular Queue.";
		cout<<"\n(3) Double Ended Queue.";
		cout<<"\n\nEnter your choice :";
		cin>>choice;
		switch(choice)
		{
			case 1 : 
					queue();
					break;
			case 2 :
					Cqueue();
					break;
			case 3 :
					Dqueue();
					break;
			default : 
					cout<<"\nSorry!! Wrong choice..!";
		}
		cout<<"\nDo you want to continue..? ( Y/N )\n";
		cin>>ch;
	}
	while((ch == 'y')||(ch == 'Y'));
	return 0;
}

void queue()
{
	int choice,size,t;
	char ch,ele;
	cout<<"\nEnter the size of the Queue : ";
	cin>>size;
	Queue <char> Q(size);
	do
	{
		cout<<"\n-----------MENU-------------";
		cout<<"\n(1) Add.";
		cout<<"\n(2) Delete.";
		cout<<"\n(3) Display.";
		cout<<"\n(4) Exit.";
		cout<<"\nEnter your choice :";
		cin>>choice;
		
	switch(choice)
	{
		case 1 :
				try
				{
					cout<<"\nEnter the element : ";
					cin>>ele;
					Q.Enqueue(ele);
				}
				catch(char* a)
				{
					cout<<a;
				}
		    	break;
		case 2 :
				try
				{
					cout<<"\nDeleted element is : "<<Q.Dequeue();
				}
				catch(char* a)
				{
					cout<<a;
				}
		    	break;
		case 3 :
				Q.Display();
				break;
		case 4 : 
				break;
		default : 
				cout<<"\nSorry!!  You have entered a wrong choice..!\n";
	}
	cout<<"\n\nDo you want to continue..? ( Y/N )\n";
	cin>>ch; }
	while((ch == 'y')||(ch == 'Y'));
}
void Cqueue()
{
	int choice,size,t;
	char ch,ele;
	cout<<"\nEnter the size of the Queue : ";
	cin>>size;
	CircularQueue <char> Q(size);
	do
	{
		cout<<"\n-----------MENU-------------";
		cout<<"\n(1) Add.";
		cout<<"\n(2) Delete.";
		cout<<"\n(3) Display.";
		cout<<"\n(4) Exit.";
		cout<<"\nEnter your choice :";
		cin>>choice;
		
	switch(choice)
	{
		case 1 :
				try
				{
					cout<<"\nEnter the element : ";
					cin>>ele;
					Q.Enqueue(ele);
				}
				catch(char* a)
				{
					cout<<a;
				}
		    	break;
		case 2 :
				try
				{
					cout<<"\nDeleted element is : "<<Q.Dequeue();
				}
				catch(char* a)
				{
					cout<<a;
				}
		    	break;
		case 3 :
				Q.Display();
				break;
		case 4 : 
				break;
		default : 
				cout<<"\nSorry!!  You have entered a wrong choice..!\n";
	}
	cout<<"\n\nDo you want to continue..?\n ( Y/N )";
	cin>>ch; }
	while((ch == 'y')||(ch == 'Y'));
}

void Dqueue()
{
	int choice,size,t;
	char ch,ele;
	cout<<"\nEnter the size of the Queue : ";
	cin>>size;
	D_Queue <char> Q(size);
	do
	{
		cout<<"\n-----------MENU-------------";
		cout<<"\n(1) Add.";
		cout<<"\n(2) Delete.";
		cout<<"\n(3) Display.";
		cout<<"\n(4) Exit.";
		cout<<"\nEnter your choice :";
		cin>>choice;
		
		switch(choice)
	{
		case 1 :
				try
				{
					cout<<"\nEnter the element : ";
					cin>>ele;
					Q.Enqueue(ele);
				}
				catch(char* a)
				{
					cout<<a;
				}
		    	break;
		case 2 :
				try
				{
					cout<<"\nDeleted element is : "<<Q.Dequeue();
				}
				catch(char* a)
				{
					cout<<a;
				}
		    	break;
		case 3 :
				Q.Display();
				break;
		case 4 : 
				break;
		default : 
				cout<<"\nSorry!! You have entered a wrong choice..!\n";
	}
	cout<<"\n\nDo you want to continue..?\n ( Y/N )";
	cin>>ch; }
	while((ch == 'y')||(ch == 'Y'));
}

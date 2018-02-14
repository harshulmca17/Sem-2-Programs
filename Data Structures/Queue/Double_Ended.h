#include<iostream>
#include<stdio.h>

using namespace std;

template <class T>
class D_Queue
{
	T *array;
	int length;
	int front;
	int rear;
  public :
  	D_Queue(int length);
  	void Enqueue(T element);
  	T Dequeue();
  	bool isFull();
  	bool isEmpty();
  	void Display();
};

template <class T>
D_Queue <T> :: D_Queue(int len)
{
	length = len;
	array = new T[length];
	front = -1;
	rear = -1;
}

template <class T>
void D_Queue <T> :: Enqueue(T element)
{
	int add;
	cout<<"\nWhere you want to add..?";
        cout<<"\n (1)Front";
	cout<<"\n (2)Rear\n";
	cout<<"Enter your choice : ";
	cin>>add;
	char* msg;
	if(isFull())
	{
		msg = "Queue is Full.";
		throw msg;
	}
	else if(add == 2)
	{
		if(rear == length-1)
		{
			cout<<"\nElement can not be inserted ( YOU ARE AT THE LAST LOCATION OF THE QUEUE ).\n";
		}
		else
		{
			rear++;
			array[rear] = element;
		}
	}
	else if(add == 1)
	{
		if(isEmpty())
		{
			front++;
			rear++;
			array[front] = element;
		}
		else
		{
			if(front == 0)
			{
				cout<<"\nElement can not be inserted ( YOU ARE AT THE FIRST LOCATION OF THE QUEUE ).\n";
			}
			else
			{
				front--;
				array[front] = element;
			}
		}
	}
}

template <class T>
T D_Queue <T> :: Dequeue()
{
	T temp;
	int del;
	cout<<"\nWhere you want to delete..?";
	cout<<"\n (1)Front";
	cout<<"\n (2)Rear\n";
	cout<<"Enter your choice : ";
	cin>>del;
	char* msg;
	if(isEmpty())
	{
		msg = "Queue is Empty.";
		throw msg;
	}
	else if(front == rear)
	{
		temp = array[rear];
		front = -1;
		rear = -1;
		return temp;
	}
	else if(del == 1)
	{
		temp = array[front];
		front++;
		return temp;
	}
	else
	{
		temp = array[rear];
		rear--;
		return temp;
	}
}

template <class T>
bool D_Queue <T> :: isFull()
{
	if((rear == length-1)&&(front == -1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool D_Queue <T> :: isEmpty()
{
	if((front == -1)&&(rear == -1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void D_Queue <T> :: Display()
{
	cout<<"\nThe elements of the Queue :\n";
	for(int i = front ; i <= rear ; i++)
	{
		cout<<array[i]<<"\t";
	}
}

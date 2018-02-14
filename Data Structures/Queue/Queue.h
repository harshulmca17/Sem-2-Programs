#include<iostream>
#include<stdio.h>

using namespace std;

template <class T>
class Queue
{
	T *array;
	int length;
	int front;
	int rear;
  public :
  	Queue(int length);
  	void Enqueue(T element);
  	T Dequeue();
  	bool isFull();
  	bool isEmpty();
  	void Display();
};

template <class T>
Queue <T> :: Queue(int len)
{
	length = len;
	array = new T[length];
	front = -1;
	rear = -1;
}

template <class T>
void Queue <T> :: Enqueue(T element)
{
	char* msg;
	if(isFull())
	{
		msg = "Queue is Full.";
		throw msg;
	}
	else if(front == -1)
	{
		front = 0;
		rear = 0;
		array[rear] = element;
	}
	else
	{
		rear++;
		array[rear] = element;
	}
}

template <class T>
T Queue <T> :: Dequeue()
{
	T temp;
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
	else
	{
		temp = array[front];
		front++;
		return temp;
	}
}

template <class T>
bool Queue <T> :: isFull()
{
	if(rear == length-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Queue <T> :: isEmpty()
{
	if(front == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void Queue <T> :: Display()
{
	cout<<"\nThe elements of the Queue :\n";
	for(int i = front ; i <= rear ; i++)
	{
		cout<<array[i]<<"\t";
	}
}

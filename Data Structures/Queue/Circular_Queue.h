#include<iostream>
#include<stdio.h>

using namespace std;

template <class T>
class CircularQueue
{
	T *array;
	int length;
	int front;
	int rear;
  public :
  	CircularQueue(int length);
  	void Enqueue(T element);
  	T Dequeue();
  	bool isFull();
  	bool isEmpty();
  	void Display();
};

template <class T>
CircularQueue <T> :: CircularQueue(int len)
{
	length = len;
	array = new T[length];
	front = -1;
	rear = -1;
}

template <class T>
void CircularQueue <T> :: Enqueue(T element)
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
		rear = (rear + 1) % length;
		array[rear] = element;
	}
}

template <class T>
T CircularQueue <T> :: Dequeue()
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
		front = (front + 1) % length;;
		return temp;
	}
}

template <class T>
bool CircularQueue <T> :: isFull()
{
	if(((front == 0) && (rear == length-1))||(front == rear+1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool CircularQueue <T> :: isEmpty()
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
void CircularQueue <T> :: Display()
{
	if(isEmpty())
	{
		cout<<"\nQueue is Empty.\n";
	}
	else
	{
		cout<<"\nThe elements of the Queue :\n";
		for(int i = front ; i <= rear ; i++)
		{
			cout<<array[i]<<"\t";
		}
	}
}

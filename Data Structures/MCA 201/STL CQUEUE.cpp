#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;

class queue 
	/*   			

	objective: Create a class to implement Queue(circular) using dynamically created array 

	input parameters: none

	output value: none

	description:  Class definition

	approach: Class definition provides data member and member functions for the Queue class

	*/
{
	int *arr;			// array to store queue elements
	int capacity;			// maximum capacity of the Q
	int front;			// front points to front element in the Q
	int rear;			// rear points to last element in the Q
	int count;			// current size of the Q
public:

	queue(int size = SIZE);			// constructor
	~queue();	
	int dequeue();
	void enqueue(int);
	int peek();  				// returns front element
	int size();				// returns current size of Q
	bool isEmpty();
	bool isFull();
};

queue :: queue(int size){

	arr = new int[size];
	capacity = size;
	front = -1;
	rear = -1;
	count = 0;
}

queue :: ~queue(){

	delete(arr);
	capacity = 0;
	front = -1;
	rear = -1;
	count = 0;
}

int queue :: dequeue(){
	int temp;
	if(isEmpty()){
		cout<<"Queue is already empty";
	}
	else if(front == rear)
	{
		count--;
		temp = arr[front];
		front = -1;
		rear = -1;
		return temp;
	}
	else
	{	
		count--;
		temp = arr[front];
		front = (front + 1) % capacity;
		return temp;
	}
}

void queue :: enqueue(int element){
	if(isFull())
	{
		cout<< "Queue is Full.";
	
	}
	else if(front == -1)
	{
		count++;
		front = 0;
		rear = 0;
		arr[rear] = element;
	}
	else
	{
		count++;
		rear = (rear + 1) % capacity;
		arr[rear] = element;
	}
}

int queue :: peek(){
	return(arr[rear]);
}

int queue :: size(){
	return(count);
}

bool queue :: isFull(){
	if(((front == 0) && (rear == capacity-1))||(front == rear+1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool queue :: isEmpty(){
	if(front == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(){

	char ch;
	queue obj(8);
	int choice;
	
	do{
		cout<<"\nPress 1 To Insert an element ";
		cout<<"\nPress 2 To Remove an element ";
		cout<<"\nPress 3 To show size of queue ";
		cout<<"\nPress 4 To show top element ";
		cin>>choice;
		
		switch(choice){
			case 1: int element;
					cout<<"\nEnter element to be inserted:";
					cin>>element;
					obj.enqueue(element);
					break;
			case 2: cout<<"\nRemoved element is "<<obj.dequeue();
					break;
			case 3: cout<<"\nPresent size of queue is "<<obj.size();
					break;
			case 4: cout<<"\nPresent top element of queue is "<<obj.peek();
					break;
			default: cout<<"\nInvalid option ";
					break;
		}
	
	cout<<"\nWould You like to continue ('Y'es,'N'o).? ";
	cin>> ch;	
	}while(ch=='y'||ch=='Y');
	return(0);
}
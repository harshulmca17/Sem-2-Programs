#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
class Node
{
    public:
    int data;
    Node * previous;
    Node * next;
};
class D_Queue
{
	public :
  	D_Queue();
  	Node * rear;
	Node * front;
	void Enqueue(int element);
  	int Dequeue();
  	bool isEmpty();
  	void Display();
};

D_Queue :: D_Queue()
{
	
	front = NULL;
	rear = NULL;
}

void D_Queue :: Enqueue(int element)
{
	Node * temp;
	temp=(Node *)malloc(sizeof(Node));
	temp->data=element;
	 
	if(rear==NULL)
		{
		  rear=temp;
		  front=temp;
		  rear->next=NULL;
		  rear->previous=NULL;
		}
	else{
	  
	int add;
	cout<<"\nWhere you want to add..?";
        cout<<"\n (1)Front";
	cout<<"\n (2)Rear\n";
	cout<<"Enter your choice : ";
	cin>>add;

	if(add == 2)
	{	
		temp->previous=rear;
		rear->next=temp;
		rear=temp;
				
	}
	else if(add == 1)
	{	
		
		temp->next=front;
		front->previous=temp;
		front=temp;
		
		
	}
	}
}


int D_Queue  :: Dequeue()
{	
	Node * temp;
	int del;
	if(front == rear)
	{	
		temp=front;
		del = temp->data;
		delete(temp);
		return del;
	}
	else{
	
	cout<<"\nWhere you want to delete..?";
	cout<<"\n (1)Front";
	cout<<"\n (2)Rear\n";
	cout<<"Enter your choice : ";
	cin>>del;
	if(del == 1)
	{
		temp = front;
		front= front->next;
		front->next->previous=front;
		del=temp->data;
		
		return del;
	}
	else
	{
	      
		temp = rear;
		rear=rear->previous;
		rear->previous->next=rear;
		del=temp->data;
		delete(temp);
		return del;
	}
	}
}

bool D_Queue  :: isEmpty()
{
	if((front == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void D_Queue :: Display()
{
     Node *var=front;
     if(var!=rear->next)
     { 
          cout<<"\nElements are as:\n";
          while(var!=rear->next)
          {
               cout<<"\n"<<var->data;
               var=var->next;
          } 
     cout<<"\n";
     }
     else
     cout<<"\nQueue is Empty";
}
int main()
{
    D_Queue ob;
    int ch,ele;
    char chh;
    do{
      system("clear");
      cout<<"\nPress 1 To Enqueue.";
      cout<<"\nPress 2 To Dequeue.";
      cout<<"\nPress 3 To Display.";
      cout<<"\nPress 4 To Exit : ";
      cin>>ch;
      switch(ch)
      {
	case 1 :cout<<"\nEnter the Element : ";cin>>ele;
		    ob.Enqueue(ele);
		    break;
	case 2 :cout<<"\nDequeued Element is : "<<ob.Dequeue();
		      break;
	case 3 :ob.Display();
		      break;
	case 4 :	cout<<"\nProgram is Exiting.";
			exit(0);
			break;
      }
      cout<<"\nWould You Like to continue....('Y'es,'N'o).";
      cin>>chh;
      }while(chh=='y'||chh=='Y');
      return 0;
}
  

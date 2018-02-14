#include<iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Node
{
public:
    int data;
    Node *previous;
    Node *next;
}*front,*rear;

void dequeue()
{
    Node *var=rear;
    if(var==rear||rear!=front->previous)
    {
        rear = rear->previous;
        free(var);
    }
    else
    cout<<"\nQueue Empty";
}

void enqueue(int value)
{
    Node *temp;
    temp=(Node *)malloc(sizeof(Node));
    temp->data=value;
    if (front == NULL)
    {
	  rear=temp;
         front=temp;
         front->next=NULL;
	  front->previous=NULL;
      
    }
    else
    {
        temp->next=front;
        front->previous=temp;
	front=temp;
    }
}

void display()
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
     int i=0;
     char ch;
      front=NULL;
     
     do{
       system("clear");
      cout<<"\nStack Implementation Using Linked List.\n\n";
      cout<<" \nPress 1 To Enqueue to Queue";
     cout<<" \nPress 2 To  Dequeue from Queue";
     cout<<" \nPress 3 To Display data of Queue";
     cout<<" \nPress 4 To Exit\n";
      cin>>i;
     switch(i)
          {
               case 1:
               {
               int value;
               cout<<"\nEnter a value to Enqueue into Queue: ";
               cin>>value;
               enqueue(value);
               
               break;
               }
               case 2:
               {
               dequeue();
               display();
               break;
               }
               case 3:
               {
               display();
               break;
               }
               case 4:
               {
               struct Node *temp;
               while(rear!=NULL)
               {
                    temp = rear->previous;
                    free(rear);
                    rear=temp;
               }
               exit(0);
               } 
               default:
               {
               cout<<"\nwrong choice for operation";
               }
         }
     
       cout<<"\nWould You Like To Continue...('Y'es,'N'o).";
       cin>>ch;
    }while(ch=='y'||ch=='Y');
}
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
}*top;

void popStack()
{
    Node *var=top;
    if(var==top)
    {
        top = top->next;
        free(var);
    }
    else
    cout<<"\nStack Empty";
}

void push(int value)
{
    Node *temp;
    temp=(Node *)malloc(sizeof(Node));
    temp->data=value;
    if (top == NULL)
    {
         top=temp;
         top->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

void display()
{
     Node *var=top;
     if(var!=NULL)
     { 
          cout<<"\nElements are as:\n";
          while(var!=NULL)
          {
               cout<<"\n"<<var->data;
               var=var->next;
          } 
     cout<<"\n";
     }
     else
     cout<<"\nStack is Empty";
}

int main()
{
     int i=0;
     char ch;
     top=NULL;
     
     do{
       system("clear");
      cout<<"\nStack Implementation Using Linked List.\n\n";
      cout<<" \nPress 1 To Push to stack";
     cout<<" \nPress 2 To  Pop from Stack";
     cout<<" \nPress 3 To Display data of Stack";
     cout<<" \nPress 4 To Exit\n";
      cin>>i;
     switch(i)
          {
               case 1:
               {
               int value;
               cout<<"\nEnter a value to push into Stack: ";
               cin>>value;
               push(value);
               display();
               break;
               }
               case 2:
               {
               popStack();
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
               while(top!=NULL)
               {
                    temp = top->next;
                    free(top);
                    top=temp;
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
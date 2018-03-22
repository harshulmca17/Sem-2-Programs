#include<iostream>
#include<stdlib.h>

using namespace std;
int qt=2,timel=0,pr;
class node
{
      public:
             node *next;
             int burst;
	     int arival;
	     int pid;
	     int burst2;
};

class Queue : public node
{	
	  public:
           node *head;
           int front,rare;
	   
           Queue()
           	{
            	front=-1;
             	rare=-1;
             }
	   int checkBurst();
	   void push(int b,int a,int p,int b2);
	   node* pop();
	   void display();
}s1,s2;

void Queue::push(int b,int a,int p,int b2)
{
            	if (rare < 0 )
             		{
			    head = new node;
			    head->next=NULL;
			    head->burst=b;
			    head->burst2=b2;
			    head->arival=a;
			    head->pid=p;
			    rare ++;
			}
		else
			{
			    node *temp,*temp1;
			    temp=head;
			/*    if(rare >= 4)
			    {
                          	cout <<"queue over flow";
                           	return;
			    }*/
			    rare++;
			    while(temp->next != NULL)
                        	temp=temp->next;
			    temp1=new node;
			    temp->next=temp1;
			    temp1->next=NULL;
			    temp1->burst=b;
			    temp1->burst2=b2;
			    temp1->arival=a;
			    temp1->pid=p;
			 }  
		  
}
void Queue::display()
{
              node *temp;
              temp = head;
              if (rare < 0)
               {
                    return;
               }
               cout<<endl<<" ";
              while(temp != NULL)
               {
		 if(temp->next != NULL)
               	   cout<<"P"<<temp->pid<<" ->";
		 else if(temp->next == NULL)
		   cout<<"P"<<temp->pid; 
		 temp=temp->next;
               }
}
node* Queue::pop()
{
        node *temp;
        temp=head;
        if( rare < 0)
        {
            cout <<"Queue under flow";
	    return 0;
        }
        if(front == rare)
        {
            front = rare =-1;
	    head = NULL;
            return 0;
        }
        front++;
	node* temp1 = head;
        while(temp1->burst2 == 0)
	{
	  temp1=temp1->next;
	}
	head = head->next;
	return temp1;
}
int Queue::checkBurst()
{
	int pl=0;
        node *temp;
        temp=head;
      while(temp != NULL)
	{	
	      if(temp->burst2 > 0)
	       {		  return pl;
	       }
	      else
	      {
		temp=temp->next;
		pl++;
	      }
        }
        return (-1);
}	
void roundRobing()
{	
	while((s1.checkBurst()) > -1)
	{
	    node* temp = s1.pop();
	    if(temp->burst2 < 2 && temp->burst2 > 0)
	    {
		temp->burst2 = temp->burst2 - 1;
		timel = timel+1;
      
	    }
	    else 
	    {
		temp->burst2 = temp->burst2 - 2;
		timel = timel+2;
	    }
	    cout<<"   "<<timel;
	    if(temp->burst2 > 0)
	    {
		s1.push(temp->burst,temp->arival,temp->pid,temp->burst2);
	    }
	    s2.push(temp->burst,temp->arival,temp->pid,temp->burst2);
	   
	}
	s2.display();
	
}
int main()
{
	system("clear");
	int ch;
	cout<<"\nEnter the Number of processes:";
	cin>>pr;
	int i=1;
	while(i<=pr)
	{
	    int a,b;
	    cout<<"\nEnter the Burst Time and Arival Time for Process P"<<i<<"\n";
	    cout<<"\nBurst Time:";cin>>b;
	    s1.push(b,0,i,b);
	    i++;
	}
	
        cout<<"\n\n\n\nGantts Chart is as follows:\n0";
	roundRobing();
	cout<<"\n\n\n";
	return (0);
}

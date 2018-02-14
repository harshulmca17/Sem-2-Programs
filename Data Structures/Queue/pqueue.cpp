#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

class PRIOR_QUEUE
   {
     
	     int *array;
             int length;
             int front,rear;
     
	   public:
	     
	   bool isEmpty();
           bool isFull();
	   void check(int );
           PRIOR_QUEUE(int len);
           void ENQUEUE(int x);
           int DEQUEUE();
           void display();
           void clearqueue();
};

PRIOR_QUEUE::PRIOR_QUEUE(int len)
{
   length=len;
   array=new int[length];
   front=-1;
   rear=-1;
}

bool PRIOR_QUEUE::isFull()
{
 if(rear==length-1)
   return true;
  else
   return false;
}

bool PRIOR_QUEUE::isEmpty()
{
 if(front==-1 && rear==-1)
   return true;
  else
   return false;
}

void PRIOR_QUEUE::ENQUEUE(int x)
{
 if(isFull())
  {
    throw"\t\tQueue is full.\n";
  }
 else if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        array[rear] = x;
        return;
    }    
    else
        check(x);
    rear++;
}
 
/* Function to check priority and place element */
void PRIOR_QUEUE::check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= array[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                array[j] = array[j - 1];
            }
            array[i+1] = data;
            return;
        }
    }
    array[i] = data;
}

int PRIOR_QUEUE::DEQUEUE()
{
 int temp;
 if(isEmpty())
  {
   throw"\t\tQueue is empty\n";
  }
 else if(front==rear)
  {
   temp=array[rear];
   front=rear=-1;
   return temp;
  }
 else
  {
   temp=array[rear];
   rear--;
   return temp;
  }
}

void PRIOR_QUEUE::clearqueue()
{
 front=-1;
 rear=-1;
 cout<<"\t\tThe queue is empty..\n";
}

void PRIOR_QUEUE::display()
{
 cout<<"\t\tThe queue contains elements..\n";
    for(int i=0;i<=rear;i++)
  {
    cout<<array[i]<<"\n";
  }
}

int main()
{
  int choice=0,num,ele;
  char ch;
  cout<<"\nEnter the size of the queue..\n";
  cin>>num;
  PRIOR_QUEUE Q(num);  
  do
  {
    system("clear");
    cout<<"Press 1 To Enqueue\n";
    cout<<"Press 2 To Dequeue\n";
    cout<<"Press 3 To Clearqueue\n";
    cout<<"Press 4 To Display\n";
    cout<<"Press 5 To Exit\n";
    cout<<"Enter your choice : \t";
    cin>>choice;
    switch(choice)
     {
       case 1:
               try
               {
                 cout<<"\t\tEnter the element to be enqueued..\n";
                 cin>>ele;
                 Q.ENQUEUE(ele);
               }
               catch(const char* s) 
               {
                 cout<<s;
               }
               break;
      case 2:
              try
              {
               int temp;
               temp=Q.DEQUEUE();
               cout<<"\t\tThe deleted element is:"<<temp<<"\n";
              }
              catch(const char*d)
              {
                cout<<d;
              }
              break;
     case 3:
              Q.clearqueue();
              break;
     case 4:
             Q.display();
             break;
     case 5:
            cout<<"\t\tNow exiting the program\n";
            exit (0);
            break;
    default:
             cout<<"\t\tWrong choice entered\n";
  }
   cout<<"\t\tWould you Like  to continue('Y'es,'N'o)\n";
   cin>>ch;
  }while(ch=='Y'||ch=='y');
   return 0;
}

                    


    
  
  

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Queue
{
 
    public:
    int rear,front;
    int *pid,*burstt,*wt,*tt,*at;
    int avrwt,avrtt;
    int size; 
    
    void enQueue(int burst,int arival);
    int process();
    void tTurnAround();
    void tWaiting();
    void display();
    void sort();
    void average();
    int isFull();
    int isEmpty();
    
    Queue()
    {   
        avrtt=0;
        avrwt=0;
        rear = 0;
        front = 0;
        cout<<"\nEnter total number of processes:";
        cin>>size;        
        burstt = new int [size];
        wt = new int [size];
        tt = new int [size];
        at = new int [size];
        pid = new int [size];
    }
    
};
void Queue::enQueue(int burst,int arival)
{
    
    if( front == 0 && rear == (size) )
    {
            cout<<"\nAll Processes Inserted.";
    }
    else if(front == -1 && rear == -1)
    {
            front=0;
            rear=0;
            burstt[rear] = burst;
            at[rear] = arival;
            pid[rear] = rear+1;
            rear++;
    }
    else 
    {
            burstt[rear] = burst;
            at[rear] = arival;
            pid[rear] = rear+1;
            rear++;
    }
}
int Queue::process()
{
    if(front==0&&rear==0)
    {
        cout<<"\nNo Process is present in the memory.";
        return 0;
    }
    else 
        return (rear+1);
}
int Queue::isEmpty()
{
    if( front == 0 && rear == 0 )
        return 1;
    else 
        return 0;
}
int Queue::isFull()
{
    if( front == 0 && rear == (size-1) )
        return 1;
    else 
        return 0;
}
void Queue::display()
{
    if( front == 0 && rear == 0)
    {
        cout<<"\nNo Process is present in the memory.";
    }
    else 
    {
        cout<<"\nProcesses\tBurst Time\tArival Time\tWaiting Time\tTurnAround Time.\n";
        for(int i=front;i<rear;i++)
        {
                cout<<"\nP"<<pid[i]<<"\t\t"<<burstt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<".\n";
        }
    }
    
    cout<<"\n\nAverage Waiting Time is "<<avrwt;
    cout<<"\nAverage Turn Around Time is "<<avrtt<<"\n";
}
void Queue::sort()
{
        for(int i=0;i<size;i++)
        {
                for(int j = i+1;j<size;j++)
                {
                    if(burstt[i]>burstt[j])
                    {
                        int temp = burstt[j];
                        burstt[j] = burstt[i];
                        burstt[i] = temp;
                        int temp1 = at[j];
                        at[j] = at[i];
                        at[i] = temp1;
                        int temp3 = pid[i];
                        pid[i] = pid[j];
                        pid[j] = temp3;
                        
                    }
                }                    
        }
        for(int i=0;i<size;i++)
        {
                for(int j = i+1;j<size;j++)
                {
                    if(at[i]>at[j])
                    {
                        int temp = at[j];
                        at[j] = at[i];
                        at[i] = temp;
                        int temp1 = burstt[j];
                        burstt[j] = burstt[i];
                        burstt[i] = temp1;
                        int temp3 = pid[i];
                        pid[i] = pid[j];
                        pid[j] = temp3;
                        
                    }
                }                    
        }
}
void Queue::average()
{   
        int i=0;
        for(i;i<rear;i++)
        {
            avrwt+=wt[i];
            avrtt+=tt[i];
        }
        avrwt=avrwt/i;
        avrtt=avrtt/i;
}
void Queue::tWaiting()
{
        for(int i=0;i<rear;i++)
        {
            wt[i+1]=wt[i]+burstt[i];
        }
}
void Queue::tTurnAround()
{
        for(int i=0;i<rear;i++)
        {
            tt[i]=wt[i]+burstt[i];
        }
}
int main()
{
        system("clear");
        Queue ob;
        cout<<"\nEnter burst time and arival time for processes:\n";
        do{
            int burst,arival;
            cout<<"\nP"<<ob.rear+1<<":";cout<<"\nBurst Time: ";cin>>burst;cout<<"\nArival Time: ";cin>>arival;
            ob.enQueue(burst,arival);            
        }while(ob.rear != (ob.size) );
        ob.sort();
        ob.tWaiting();
        ob.tTurnAround();
        ob.average();
        ob.display();
        return 0;
}
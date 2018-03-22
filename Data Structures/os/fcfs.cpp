#include<iostream>
#include<stdlib.h>
#include<cstdio>

using namespace std;

class Queue
{
    public:
    int rear,front;
    int *burstt,*wt,*tt;
    int avrwt,avrtt;
    void enQueue(int burst);
    int process();
    void tTurnAround();
    void tWaiting();
    void display();
    void average();
    int isFull();
    int isEmpty();
    int size; 
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
    }
    
};
void Queue::enQueue(int burst)
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
            rear++;
    }
    else 
    {
            burstt[rear] = burst;
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
    if(front==0&&rear==0)
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
    if(front==0&&rear==0)
    {
        cout<<"\nNo Process is present in the memory.";
    }
    else 
    {
        cout<<"\nProcesses\tBurst Time\tWaiting Time\tTurnAround Time.\n";
        for(int i=front;i<rear;i++)
        {
                cout<<"\nP"<<i+1<<"\t\t"<<burstt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<".\n";
        }
    }
    cout<<"\n\nAverage Waiting Time is "<<avrwt;
    cout<<"\nAverage Turn Around Time is "<<avrtt<<"\n";
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
        cout<<"\nEnter burst time for processes:\n";
        do{
            int burst;
            cout<<"\nP"<<ob.rear+1<<":";cin>>burst;
            ob.enQueue(burst);            
        }while(ob.rear != (ob.size) );
        ob.tWaiting();
        ob.tTurnAround();
        ob.average();
        ob.display();
        return 0;
}
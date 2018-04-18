#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<cstdlib>
#define maxPacket 10

using namespace std;


typedef enum {data} frame_kind;
typedef enum {frame_arr,error,ack} event_type;
int sent_frame=0;
int previous_data;
bool isFrameArriveAtPL=false;
bool isAckReceived=false;
bool isError=false;

clock_t ts,tr;
struct packet
{
	int data;
};

struct frame
{
	packet info;
	int seq_nr;
	frame_kind kind;
	int ack_no;
		
};

frame PL_data;

void wait_for_event(event_type &event)
{
	if(isFrameArriveAtPL)
	event=frame_arr;
//	event=error;
}

void wait_for_event_S(event_type &event)          //sender side
{
	if(isAckReceived)
	event=ack;
	else
	event=error;
}
  
void from_NL(packet &buffer)
{
//	cout<<"Enter the data\n";
	buffer.data=rand()%maxPacket;
//	cin.getline(buffer.data,maxPacket);
}

void to_PL(frame &s)
{
	PL_data=s;
	isFrameArriveAtPL=true;
}

void to_PL_R(frame &s)							//receiver side
{
	
	PL_data=s;
	isAckReceived=true;
}

void from_PL(frame &r)
{
	if(isFrameArriveAtPL)
	r=PL_data;
}


void to_NL(packet &I)
{	
	
	cout<<"\n\n\nData going to sent : ";
	cout<<I.data;
}


void sender2()
{

	frame s;
	event_type event;
	packet buffer;
	if(sent_frame==0)
	{
		from_NL(buffer);
		previous_data= buffer.data;
		s.info=buffer;
		to_PL(s);
		sent_frame++;
		ts = clock();
	}
	else
	{
		char ch;
		wait_for_event_S(event);
		ts = clock() - ts;
		  if(ts < 8900)
		 {
			if(event==ack)
			{
				cout<<"Ack Received of Frame "<<sent_frame<<"\n----------------------------------------------------------------------------------------------------"<<"\nSending Frame "<<sent_frame+1;
				from_NL(buffer);
				previous_data= buffer.data;
				s.info=buffer;
				to_PL(s);
				sent_frame++;
			
			}
		
			else if(event==error)
		  	{
				cout<<"Negative Ack Recieved\n";
			 	cout<<"Sending Previous Frame i.e"<<sent_frame<<" again";
				buffer.data = previous_data;
				s.info=buffer;
				to_PL(s);
				ts = clock();	
			}

		}
		  else
		  {
			  cout<<"ACK LOST\nSending Previous Frame i.e "<<sent_frame<<" again";
			  buffer.data = previous_data;
			  s.info=buffer;
			  to_PL(s);
			  ts = clock();	
		}
		
			
	}
	
}

void receiver2()
{
	frame r,s;
	event_type event;
	int ch = rand()%100;
		wait_for_event(event);
		if(event==frame_arr)
		{
			from_PL(r);
			to_NL(r.info);
			
				sleep(2);
			
			cout<<"\t\t\t\t\t\tFrame Recieved Successfully and Sending Ack for same.\n\n";		
			if(ch < 60){
				to_PL_R(s);
			}
		}
}

void start()
{
	system("clear");
	cout<<"\n\t\t\t\t\tStop And Wait (Noisy).\t\t\n\n";
}
int main()
{
	srand(time(NULL));
	start();
	char ch;
	cout<<"\nConnection Established\n\n";
	cout<<"\nSender Side.\t\t\t\t\t\t\tReciever Side.";
	cout<<"\n\n**************************************************************************************************************\n\n";
	while(1)
	{
		sender2();
		sleep(2);		
		receiver2();
	}	

	cout<<"\n\nConnection Demolished.\n\n";
	return 0;
}

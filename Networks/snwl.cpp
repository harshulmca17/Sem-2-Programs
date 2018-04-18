#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<cstdlib>
#define maxPacket 10

using namespace std;

typedef enum {data} frame_kind;
typedef enum {frame_arr,ack} event_type;
int sent_frame=0;

bool isFrameArriveAtPL=false;
bool isAckReceived=false;
bool isError=false;


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
//	event=error;
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
	
	cout<<"\nData going to sent : ";
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
		s.info=buffer;
		to_PL(s);
		sent_frame++;
	}
	else
	{
		char ch;
		wait_for_event_S(event);
		if(event==ack)
		{
			cout<<"\nAck Received of Frame "<<sent_frame<<"\nSending Frame "<<sent_frame+1;
			from_NL(buffer);
			s.info=buffer;
			to_PL(s);
			
		}
		sent_frame++;
			
	}
	
}

void receiver2()
{
	frame r,s;
	event_type event;

		wait_for_event(event);
		if(event==frame_arr)
		{
			from_PL(r);
			to_NL(r.info);
			sleep(1);	
			cout<<"\t\t\t\t\t\tFrame Recieved Successfully and Sending Ack for same.\n\n";		
			to_PL_R(s);
		}
}

void start()
{
	system("clear");
	cout<<"\n\t\t\t\t\tStop And Wait (Noisless).\t\t\n\n";
}
int main()
{
	srand(time(NULL));
	start();
	char ch;
	cout<<"\nConnection Established\n\n";
	cout<<"\nSender Side.\t\t\t\t\t\t\tReciever Side.";
	cout<<"\n\n**************************************************************************************************************\n\n";
	int round = 0; 
	while(round<10)
	{
		sender2();
		sleep(2);		
		receiver2();
		round++;		
	}	

	cout<<"\n\nConnection Demolished.\n\n";
	return 0;
}

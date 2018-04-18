#include<iostream>
#include<cstdio>
#include<cstdlib>

#define max_packet 50
using namespace std;

struct packet
{
	char data[max_packet];
};

typedef enum{data} frame_kind;
typedef enum {frame_arrival} event_type ;

struct frame
{
	packet info;
	int seq_nr;
	frame_kind kind;
	int ack_no;
};


bool is_frame_at_physical=false;
bool is_error=false;

void wait_for_event(event_type &event)
{
	 if(is_frame_at_physical)
       event=frame_arrival;	       
}

void from_NL(packet &buffer)
{
  cout<<"\n\n\nEnter the data\n";
  cin.getline(buffer.data,max_packet);	
	
}

frame pl_data;

void to_PL(frame &s)
{	
     pl_data=s;
     is_frame_at_physical=true;
     
}



void from_PL(frame &r)
{
       if(is_frame_at_physical)
    r=pl_data;
    
}

void to_NL(packet &r)
{
 	cout<<"\nMessage received\n";
       cout<<"\nMy data is:  ";
    cout<<r.data;
    cout<<endl;
    	
}


void sender()
{
	
	frame s;
	packet buffer;
	
	from_NL(buffer);
	s.info=buffer;
	to_PL(s);

}
	
	
void receiver()
{
	frame r;
	event_type event;
 
	wait_for_event(event);
	from_PL(r);
	to_NL(r.info);
    
}
void start()
{	
	system("clear");
	cout<<"\n\n\t\t\t\t\t Simplex Protocole.";
}	
int main()
{
	start();
	sender();
	receiver();
}

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class SLLNode
{
	public:
			int data;
			SLLNode* next;
			SLLNode(int _data,SLLNode* _next=NULL)
			{ 
			 	data=_data;
			 	next=_next;
			 	
			}	
};



class SLL
{
	public:
		SLLNode* head;
		SLLNode* tail;
		SLL();
		bool isEmpty();
		void display();
		bool IsInList(int _data);
		void AddToHead(int _data);
		void AddToTail(int _data);
		int deleteFromHead();
		int deleteFromTail();
		void Delete(int ele);
		int deleteBefore(int ele);
		int deleteAfter(int ele);
		void addBefore(int _data,int ele);
		void addAfter(int _data,int ele);
};



SLL :: SLL()
{
		head=tail=0;			
}
		
bool SLL :: isEmpty()
{
	if(head==NULL)
	           return true;
	return false;
}

void SLL :: display()
{
	cout<<"   The Elements of The Link List are \n";
	SLLNode* temp=head;
	while(temp!=NULL)
	{
		cout<<"   "<<temp->data<<" \n";
		temp=temp->next;		
	}
}
		
bool SLL :: IsInList(int _data)
{
	SLLNode* temp=head;
	while(temp!=NULL)
	{
		if(temp->data==_data)
		return true;
		temp=temp->next;
	}
	return false;
}

void SLL :: AddToHead(int _data)
{
	SLLNode* temp;
	if(isEmpty())
	{
		temp=new SLLNode(_data);
		head=temp;
		tail=head;
	}
	else
	{
		temp=new SLLNode(_data,head);
		head=temp;
	}
}
		
void SLL :: AddToTail(int _data)
{
	SLLNode* temp;
	if(isEmpty())
	{
		temp=new SLLNode(_data);
		head=temp;
		tail=head;
	}
	else
	{
		temp=new SLLNode(_data);
		tail->next=temp;
		tail=temp;
	}
}
		
int SLL :: deleteFromHead()
{ 	
	SLLNode* temp=new SLLNode;
	if(isEmpty())
	{
		throw "Linked list is empty";
	}
	else if(head==tail)
	{ 	 
        temp=head;
		head=tail=NULL;
		int i = temp->data;
        delete temp;
        return i; 
	}
	else
	{
		temp=head;
		head=head->next;
		int i= temp->data;
		delete temp;
		return i;
	}
}

int SLL :: deleteFromTail()
{
	SLLNode* temp;
	if(isEmpty())
	{
		throw "Linked list is empty";
	}
    else if(head==tail)
	{ 	 
        temp=new SLLNode; 
		temp=head;
		head=tail=0;
		int i= temp->data;
		delete temp;
		return i; 
	}
	else
	{   
        temp=new SLLNode;
		temp=head;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
        tail=temp;
        temp=temp->next;
		tail->next=NULL;
        int i= temp->data;
		delete temp;
		return i;
	}
}

void SLL :: Delete(int ele)
{	
	SLLNode* temp=head;
	if(isEmpty())
	{
	    char* str="   Linked list is empty";
		throw str;
	}
	else if(temp->next==0)
	{
		if(temp->data==ele)
			deleteFromHead();
		else
			{
			    char* str="   Element not Found";
				throw str;
			}
					
	}
	else if(temp->data==ele)
		deleteFromHead();
	else 
	{
		while(temp->next!=0&&temp->next->data!=ele)
		{
			temp=temp->next;
		}
		if(temp->next==0)
		{
		   char* str="   Element not Found";
		    throw str;
		}
		else
		{
			SLLNode* temp2=temp->next;
			temp->next=temp->next->next;
			delete temp2;
			while(temp->next!=0)
			temp=temp->next;
			tail=temp;
		}
	}	
}
int SLL :: deleteBefore(int ele)
{
	SLLNode* temp=head;
	if(isEmpty())
	{
        char* str="   Linked list is empty";
		throw str;
	}
	else if(temp->next==0)
	{
	    char* str="   Linked list has only one element";
		throw str;
	}
	else if(temp->data==ele)
	{
		char* str="  There is no element before Head(First Element) ";
		throw str;
	}
	else if(temp->next->data==ele)
	{	
        int e;
		e=deleteFromHead();
		return e;
	}
	else
	{
        while(temp->next->next!=0&&temp->next->next->data!=ele)
		{
			temp=temp->next;
		}
		if(temp->next->next==0)
		{
		   char* str="   Element not Found";
		   throw str;
		}
		else
		{
			SLLNode* temp2=temp->next;
			temp->next=temp->next->next;
			return temp2->data;
		}
	}
}
int SLL :: deleteAfter(int ele)
{	
	SLLNode* temp=head;
	if(isEmpty())
	{
	    char* str="   Linked list is empty";
		throw str;
	}
	else if(temp->next==0)
	{
	    char* str="   Linked list has only one element";
		throw str;
	}
	else if(tail->data==ele)
	{
    	char* str="  There is no Element After Tail(Last Element) ";
		throw str;
	}
	else 
	{
		while(temp->next!=0&&temp->data!=ele)
		{
			temp=temp->next;
		}
		if(temp->next==0)
		{
			if(temp->data==ele)
			{
				char* str="  There is no Element After Tail(Last Element) ";
				throw str;
			}
			else
	    	{	
				char* str="  Element not Found";
				throw str;
			}
		}
		else
		{
			SLLNode* temp2=temp->next;
			temp->next=temp->next->next;
			return temp2->data;
		}
	}
}
void SLL :: addBefore(int _data,int ele)
{
	SLLNode* temp=head;
	if(isEmpty())
	{
	    char* str="   Linked list is empty";
		throw str;
	}
	else if(temp->data==ele)
	{
		AddToHead(_data);
	}
	else
	{
		while(temp->next->next!=0&&temp->next->data!=ele)
		{
			temp=temp->next;
		}
		if(temp->next==0)
		{
			char* str="   Element not Found";
			throw str;
		}
		else
		{
			SLLNode* temp2=new SLLNode(_data);
			temp2->next=temp->next;
			temp->next=temp2;
			while(temp->next!=0)
			temp=temp->next;
			tail=temp;
		}
	}
}
void SLL :: addAfter(int _data,int ele)
{
	SLLNode* temp=head;
	if(isEmpty())
	{
	    char* str="   Linked list is empty";
		throw str;
	}
	else if(temp->data==ele)
	{
		SLLNode* temp2=new SLLNode(_data);
		temp2->next=temp->next;
		temp->next=temp2;
		while(temp->next!=0)
		temp=temp->next;
		tail=temp;
	}
	else
	{
		while(temp!=0&&temp->data!=ele)
		{
			temp=temp->next;
		}
		if(temp==0)
		{
			char* str="   Element not Found";
			throw str;
		}
		else
		{
			SLLNode* temp2=new SLLNode(_data);
			temp2->next=temp->next;
			temp->next=temp2;
			while(temp->next!=0)
				temp=temp->next;
			tail=temp;
		}
	}
}

int main()
{
	
	SLL Obj;
	int ch,data,e;
	char c;
	do
	{
	
	system("clear");
	cout<<"\nPress 1 To Add Element From Head \nPress 2 To Add Element from Tail \nPress 3 To Delete Element From Head\nPress 4 To Delete Element From Tail \n";
	cout<<"5: Delete a node by giving its data part \n6: Check whether an element is in List \n";
	cout<<"7: Delete the node before the node of given data \n8: Delete the node after the node of given data \n9: Add node before given element \n";
	cout<<"10: Add node after given element \n11: Display Elements of Linked List \n12: Exit\n   ";
	cin>>ch;
	switch(ch)
	{
		case 1:
				cout<<"   Enter the data to be added to Head \n   ";
				cin>>data;
				Obj.AddToHead(data);
				Obj.display();
				break;
		case 2:
				cout<<"   Enter the data to be added to Tail \n   ";
				cin>>data;
				Obj.AddToTail(data);
				Obj.display();
				break;
		case 3: 
				e=-1;
				try
				{
				e=Obj.deleteFromHead();
				}
				catch(char* str)
				{
					cout<<str<<" \n";
				}
				cout<<"   The deleted element from Head is "<<e<<" \n";
		 		Obj.display();
		 		
				break;
		case 4:
				e=-1;
				try
				{
				e=Obj.deleteFromTail();
				}
				catch(char* str)
				{
					cout<<str<<" \n";
				}
				cout<<"   The deleted element from Tail is "<<e<<" \n   ";
		 		Obj.display();
				 break;
		 		
		case 5:
				int d;
				try
				{
					cout<<"   Enter the data which node is to be Deleted \n   ";
					cin>>d;
					Obj.Delete(d);
				}
				catch(char* str)
				{
					cout<<str<<" \n";
				}
				Obj.display();
				break;
				
		case 6:
				bool b;
				cout<<"   Enter the Element to be searched \n   ";
				cin>>data;
				b=Obj.IsInList(data);
				if(b!=0)
				cout<<"   Element is in link list \n   ";
				else
				cout<<"   Element is not in the link list \n   ";
				break;
		case 7: 
				e=-1;
				cout<<"  Enter the element \n  ";
				cin>>data;
				try
				{
				e=Obj.deleteBefore(data);
				}
				catch(char* str)
				{
					cout<<str<<" \n";
				}
				cout<<"  The deleted element is "<<e<<" \n";
				Obj.display();
				break;
		case 8:
				e=-1;
				cout<<"  Enter the element \n  ";
				cin>>data;
				try
				{
				e=Obj.deleteAfter(data);
				}
				catch(char* str)
				{
					cout<<str<<" \n";
				}
				cout<<"  The deleted element is "<<e<<" \n";
				Obj.display();
				break;
		case 9:
				e=-1;
				cout<<"  Enter the element to be searched \n  ";
				cin>>e;
				cout<<"  Enter the data to be added Before the Element \n  ";
				cin>>data;
				try
				{
					Obj.addBefore(data,e);
				}
				catch(char* str)
				{
					cout<<str<<" \n";
				}
				Obj.display();
				break;
		case 10:
				e=-1;
				cout<<"  Enter the element to be searched \n  ";
				cin>>e;
				cout<<"  Enter the data to be added After the Element \n  ";
				cin>>data;
				try
				{
					Obj.addAfter(data,e);
				}
				catch(char* str)
				{
					cout<<str<<" \n";
				}
				Obj.display();
				break;
			
		case 11:
				Obj.display();
				break;
		case 12:
				break;		
		default:
				cout<<"   Invalid choice \n";
				break; 
			
				
     	}
	}while(ch!=12);
	
	
	
	return 0;
	
	}

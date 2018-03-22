#include <iostream>
#include <cstdlib>

using namespace std;

class node{

public:
	int data;
	node* next;
	node(int _data){
		data = _data;
		next = NULL;
	}
};

class peopleKill{

public:
	node* head;
	node* tail;

	peopleKill(){
		head=tail=0;
	}
	void display();
	int countSize();
	void createList();
};

void peopleKill :: display()
{
	cout<<"\nThe Elements of The Link List are \n";
	node* temp=head;
	while(temp!=NULL)
	{
		if(temp->next!=NULL){
			cout<<temp->data<<" -> ";
		}
		else{
			cout<<temp->data;
		}
		temp=temp->next;		
	}
}

int peopleKill :: countSize()
{	
	int count = 0;
	node* temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;		
	}
	return count;
}

void peopleKill :: createList(){
		int size;
		cout<<"\nEnter the size of Linked List : ";
		cin>>size;

		for (int i = 0; i < size; ++i)
		{
			int temp;
			cout<<"Enter "<<i+1<<"th element : ";
			cin>>temp;

			node* temp1 = new node(temp);

			if( i == 0){
				head = temp1;
			}
			else{
				
				node* temp2 = head;
				while(temp2->next!=0)
				temp2=temp2->next;
				
				temp2->next = temp1;
				tail = temp1;
			}

		}
}

node * leader(node *head)
{
	int m,t;
	cout<<"\nEnter the M : ";
	cin>>m;
	m = m-1;
	t = m;
	node * temp = head;
	node * temp1 = temp->next;
	while(temp1->next != temp1){

		while(m>0){
			temp = temp1;
			temp1 = temp1->next;
			m--;
		}
		temp->next = temp1->next;
		temp1->next = temp->next->next;
		m = t;


	}
	return temp1;
    
}

int main()
{
	int size;
	peopleKill obj;
	node *temp;

	obj.createList();
	obj.display();

	cout<<"\n\nCreating Loop in the given Linked List ";
	obj.tail->next = obj.head;
	temp = leader(obj.head);
	cout<<"\n\nLinked Lists after seperation ";
	cout<<"\n Rank 1 leader : "<<temp->data;
	cout<<"\n\n";
	return 0;
}
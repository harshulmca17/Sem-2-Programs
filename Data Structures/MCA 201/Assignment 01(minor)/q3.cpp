
// Question 3 //

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

class Reverse{

public:
	node* head;
	node* tail;

	Reverse(){
		head=tail=0;
	}
	void swap(int *,int *);
	void display();
	void createList();
	void transformListI();
	void transformListR(node* );
};

void Reverse :: display()
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

void Reverse :: createList(){
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

void Reverse :: transformListR(node* head){
	if(head != NULL && head->next != NULL){
		swap(&head->data,&head->next->data);

		transformListR(head->next->next);
	}
}
void Reverse :: swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	Reverse obj;
	obj.createList();
	obj.display();
	obj.transformListR(obj.head);
	obj.display();
	cout<<"\n\n";
	return 0;
}
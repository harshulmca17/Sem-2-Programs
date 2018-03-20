
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

class splitCircularList{

public:
	node* head;
	node* tail;

	splitCircularList(){
		head=tail=0;
	}
	void display();
	int countSize();
	void createList();
};

void splitCircularList :: display()
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

int splitCircularList :: countSize()
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

void splitCircularList :: createList(){
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

node * seperatList(node *head)
{
    node  *slow_p = head, *fast_p = head,*temp;
 
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (fast_p->next == head)
        {
           fast_p->next = NULL;
           temp = slow_p->next;
           slow_p->next = NULL;
           return temp;
        }
        else if(fast_p->next->next == head){
           fast_p->next->next = NULL;
           temp = slow_p->next;
           slow_p->next = NULL;
           return temp;	
        }
    }

}

int main()
{
	int size;
	splitCircularList obj;
	splitCircularList obj1;
	obj.createList();
	obj.display();

	cout<<"\n\nCreating Loop in the given Linked List ";
	obj.tail->next = obj.head;
	obj1.head = seperatList(obj.head);
	cout<<"\n\nLinked Lists after seperation ";
	obj.display();
	cout<<"\n";
	obj1.display();
	cout<<"\n\n";
	return 0;
}
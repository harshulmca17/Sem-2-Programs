    	// Question 2 //

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

bool siblings(int a ,int b){
	if( (a == b-1) || (a == b+1) || (a-1 == b) || (a+1 == b) )
		return true;
	else
		return false;
}
void showStack(stack <int> gp)
{
   stack <int> g =gp;
   cout<<"\nstack : [";
    while (!g.empty())
    {
        cout<< g.top();
        g.pop();
        if(!g.empty()){
        	cout<<",";
        }
    }
    cout << "]\n";
}
void showQueue(queue <int> gp)
{
   queue <int> g =gp;
   cout<<"\nSibling Queue  : ";
    while (!g.empty())
    {
        cout<<"("<< g.front();
        g.pop();
        cout<<","<<g.front()<<")\t";
        g.pop();
    }
    cout << "\n";
}
queue <int> formQueue(stack <int> temp){

	stack <int> tp,s = temp;
	queue <int> t ;
	if(s.size()%2 != 0){
		s.pop();
	}
	while(!s.empty()){

		t.push(s.top());
		s.pop();
		if(siblings(t.back(),s.top())){
			t.push(s.top());
			s.pop();
				
		}
		else{
			s.pop();
		}

	}
	while(!t.empty()){
		tp.push(t.front());
		t.pop();
	}
	while(!tp.empty()){
		t.push(tp.top());
		tp.pop();
	}
	return(t);
}

stack <int> createStack(){

	stack <int> s;
	int size;
	cout<<"\nEnter the size of stack : ";
	cin>>size;

	for (int i = 0; i < size; ++i)
	{
			int temp;
			cout<<"Enter "<<i+1<<"th element : ";
			cin>>temp;
			s.push(temp);

	}
	return(s);
}
int main(){

	stack <int> s,temp;
	queue <int> q;
	s  = createStack();
//	temp = createStack();
//	while(!temp.empty()){
//		s.push(temp.top());
//		temp.pop();
//	}
	showStack(s);
	q = formQueue(s);
	showQueue(q);
	
	return 0 ;
}

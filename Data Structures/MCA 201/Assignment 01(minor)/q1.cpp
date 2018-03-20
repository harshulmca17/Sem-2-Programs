
// Question 1  //

#include<iostream>
#include<cstdlib>

using namespace std;

void stackDirection(int * a){
	int b;
	cout<<"\nAddress of a :"<<a;
	cout<<"\nAddress of b :"<<&b;

	if(a < &b){
		cout<<"\nStack is going upward";
	}
	else{
		cout<<"\nStack is going downward";
	}

}
int main()
{
	int a;
	stackDirection(&a);
	return 0;
}
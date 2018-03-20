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
class
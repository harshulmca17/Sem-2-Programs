#include<iostream>
#include<cstdlib>
#define MAX_SIZE 100

using namespace std;

template<typename T>

class stack{

    /*
    Class definition for "stack" data structure which follows Last in First out(LIFO) protocol
    */
    
    T *array;
    int top;
    int capacity;

    public:
        stack(int c=MAX_SIZE);
        ~stack();
        T input();
        void push(T);
        T pop();
        T topElement();
        int size();
        bool isEmpty();
        bool isFull();
        void stack_status();
};

template <typename T>
int stack<T> :: size(){
    return (top+1);   
}

template <typename T>
T stack<T> :: topElement(){
    
     return (array[top]);   
    
}
template <typename T>
void stack<T> :: stack_status(){
    int i = 0;
    while(i<=top){
        
            cout<<array[i]<<"\n__\n";
            i++;
    }
    
}


template <typename T>
stack<T> :: stack(int max){
        capacity = max;
        top = -1;
        array = new T[capacity];
}

template <typename T>
stack<T> :: ~stack(){
        capacity = 0;
        delete(array);
        top = -1;
}

template <typename T>
T stack<T> :: input(){
    
    int ele ; 
    cin>>ele;
    return(ele);
    
}
template <typename T>
void stack<T> :: push(T ele){
     if(!isFull()){
     top++;
     array[top] = ele;      
    }
}
template <typename T>
T stack<T> :: pop(){
    int ele; 
    if(!isEmpty()){
     ele = array[top] ;      
     top--;
    }
    return(ele);
}

template <typename T>
bool stack<T> :: isFull(){
    if( top == capacity){
     return true;   
    }
    else{
     return false;   
    }
}

template <typename T>
bool stack<T> :: isEmpty(){
    if( top == -1){
     return true;   
    }
    else{
     return false;   
    }
}


int main(){
    /*
    Objective: To perform various stack operations.
    */
    int c;
    
    cout<<"\nEnter capacity of stack: ";
    cin>>c;
    stack<int> s(c);
    int choice;
    while(1){
    cout<<"\n\n\t\t\tSTACK OPERATIONS\n\n1.PUSH\n2.POP\n3.TOP\n4.SIZE\n5.PRINT STACK\n6.EXIT\n\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    cout<<"\n\n";
    switch(choice){
        case 1: if(!s.isFull()){
                cout<<"\nEnter element: ";
                s.push(s.input());
               
            }
            else
                cout<<"\nStack Full!!Cannot push!!";
            break;
            
        case 2: if(!s.isEmpty()){
                cout<<"\nElement popped: "<<s.pop();
                s.stack_status();
            }
            else
                cout<<"\nStack empty!!Cannot pop!!";
            break;
                
        case 3: if(!s.isEmpty())
                cout<<"\nTop element: "<<s.topElement();
            else
                cout<<"\nStack is empty!!";
            break;
                
        case 4: cout<<"\nSize of stack: "<<s.size();
            break;
                
        case 5: s.stack_status();
            break;
                
        case 6: exit(0);
        
        default: cout<<"Invalid choice!!";
            break;
    }
    }
    return 0;
}

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


#include<iostream>
#include<cstdlib>
#include<cstring>
#define MAX_SIZE 100

using namespace std;


class stack{

    /*
    Class definition for "stack" data structure which follows Last in First out(LIFO) protocol
    */
    
    char *array;
    int top;
    int capacity;

    public:
        stack(int c=MAX_SIZE);
        ~stack();
        void push(char);
        char pop();
        char topElement();
        int size(){
            return(top+1);
        }
        bool isEmpty();
        bool isFull();
        void stack_status();
};


char stack :: topElement(){
    
     return (array[top]);   
    
}

void stack :: stack_status(){
    int i = 0;
    while(i<=top){
        
            cout<<array[i]<<" ";
            i++;
    }
    
}



stack :: stack(int max){
        capacity = max;
        top = -1;
        array = new char [capacity];
}


stack :: ~stack(){
        capacity = 0;
        delete(array);
        top = -1;
}

void stack :: push(char ele){
     if(!isFull()){
     top++;
     array[top] = ele;      
    }
}
char stack :: pop(){
    int ele; 
    if(!isEmpty()){
     ele = array[top] ;      
     top--;
    }
    return(ele);
}

bool stack :: isFull(){
    if( top == capacity){
     return true;   
    }
    else{
     return false;   
    }
}

bool stack :: isEmpty(){
    if( top == -1){
     return true;   
    }
    else{
     return false;   
    }
}

bool isoperand( char c )
{
	if((c>='a' && c<='z')||(c>='A' && c<='Z'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isoperator(char c)
{
	if((c == '+')||(c == '-')||(c == '/')||(c == '*'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool checkhigher(char op1, char op2)
{
	if(((op1 == '+')||(op1 == '-')) && ((op2 == '+')||(op2 == '-')))
	{
		return false;
	}
	else if(((op1 == '*')||(op1 == '/')) && ((op2 == '*')||(op2 == '/')))
	{
		return false;
	}
	else if(((op1 == '+')||(op1 == '-')) && ((op2 == '*')||(op2 == '/')))
	{
        return false;
    }
    else 
    {
        return true;
    }
}
char* infix_to_postfix(char* infix){
    /* 

        function to convert infix expressions to postfix expressions using 
            pre implemented stack


    */
    int length = strlen(infix);
    
    char *post;
    post = new char[length];
    
    stack operandObj(length);
    stack operatorObj(length/2);
    
    for(int i = 0; i <length ; i++ )
    {
        if(isoperand(infix[i]))
        {
            operandObj.push(infix[i]);
        }
        else 
        {
            if(isoperator(infix[i]))
            {
                if(operatorObj.isEmpty())
                {
                    operatorObj.push(infix[i]);
                }
                else 
                {
                    if(checkhigher(infix[i],operatorObj.topElement()))
                    {
                        operatorObj.push(infix[i]);
                    }
                    else
                    {
                        do
                        {
                            operandObj.push(operatorObj.pop());
                        }
                        while((!operatorObj.isEmpty()) && (!checkhigher(infix[i], operatorObj.topElement())));
                        operatorObj.push(infix[i]);
                    }
                }
            }
        }
    }
    while(!operatorObj.isEmpty())
    {
        operandObj.push(operatorObj.pop());
    }
    int i = operandObj.size()-1;
    while(!operandObj.isEmpty())
    {
        post[i] = operandObj.pop();
        i--;
    }
    return(post);

}

int main(){
    char ch;
    do{
        char infixExp[MAX_SIZE];
        cout<<"\n Enter the infix expression : ";
        cin>>infixExp; 
     
        char * postfixExp = new char[MAX_SIZE];
        postfixExp = infix_to_postfix(infixExp);
        cout<<"\n PostFix Expression for "<<infixExp<<" : ";
        cout<<postfixExp<<"\n\n";

        cout<<"\nWould You like to continue ('Y'es/'N'o)?";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0 ;
}

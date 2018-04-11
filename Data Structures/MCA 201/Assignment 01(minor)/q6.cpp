
// Question 6

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

class Tree{
	/*   			
	objective: Create a class for a Node for Binary Search Tree
	input parameters: none
	output value: none
	description: Tree class defines the node structure 
	approach: Class defines data item is names element with datatype int 
			and link is named next pf snode type
	*/
	
	public:
	int data;
	Tree * right;
	Tree * left;
	Tree(int _data,Tree * _left=NULL, Tree * _right=NULL)
	 {
	      data=_data;
	      left=_left;
	      right=_right;   
	  }
};
class BTree{
	/*   			
	objective: Create a Binary Search Tree class 
	input parameters: none
	output value: none
	side effects: Class BTree defines Binary Binary Search Tre class
	approach: Class definition
	*/						
	
	public:
	Tree * root;
	int arr[20] ,pathlen , sum , count;
	BTree(){root=0;}
	Tree *  insert(Tree*,int ele);
	void search(int ele);
	void deleteCopying(Tree *& node);
	void inOrder(Tree* root);
	void postOrder(Tree* root);
	void preOrder(Tree* root);
	void display(int);
	void path(Tree* ,int );
	void printPath(int [],int );

};
void BTree::search(int ele)
{
	system("clear");
	if(root==0)
	{ 
		cout<<"\nElement Not Found.";
		return;
	}
	else
	{	
	      
	      Tree * temp=root;
	      while(temp->left!=0||temp->right!=0)
	      {			
		    if(temp->data==ele)
		    { 
			  cout<<"\nElement Found .";
			  if(temp->left!=0||temp->right!=0)
			  {	cout<<"\nWith Following Children.";
			      if(temp->left!=0)
				cout<<"\nLeft Child : "<<temp->left->data;
			      if(temp->right!=0)
				cout<<"\nRight Child : "<<temp->right->data;
			  }
			  char chh;
			  cout<<"\nWould You Like To Delete this Node...('Y'es,'N'o).";
			  cin>>chh;
			  if(chh=='y'||chh=='Y')
			    deleteCopying(temp);
			  return ;
		    }
		    if(temp->data>ele)
		    {
			  if(temp->left==0)
			  break;
			  else
			  temp=temp->left;
		    }
		  else
		  {
			  if(temp->right==0)
				break;
			  else 
				temp=temp->right;
		  }
      }
  
}
}
void BTree::deleteCopying(Tree *& node)
{
    Tree *prev,*temp=node;
    if(node->left==0)
      node=node->right;
    else if(node->right==0)
      node=node->left;
    else{
	    temp = node->left;
	    prev = node;
	    while(temp->right != 0)
	    {
		prev = temp;
		temp = temp->right;
	    }
	    node->data= temp->data;
	    if(prev == node)
	      prev->left = temp->left;
	    else
	      prev->right = temp->left;
    }
    delete temp;
}

Tree * BTree :: insert(Tree *node, int key)
{
    if (node==NULL)
    {
        node = new Tree(key);
    }
    else
    {
        if (node->data > key)
        {
            node->left = insert(node->left, key);
        }
        else
        {
            node->right = insert(node->right, key);
        }
    }
    return node;
}
void BTree::inOrder(Tree* root)
{
    if(root!=0)
    {
     inOrder(root->left);
     cout<<"\n"<<root->data;
     inOrder(root->right);
     
      
    }
  
}
void BTree::preOrder(Tree* root)
{
    if(root!=0)
    {
     cout<<"\n"<<root->data;
     preOrder(root->left);     
     preOrder(root->right);
      
    }
  
}
void BTree::postOrder(Tree* root)
{
    if(root!=0)
    {
     postOrder(root->left);
     postOrder(root->right);
     cout<<"\n"<<root->data;
      
    }
  
}

void BTree::display(int ch)
{
  system("clear");
  Tree * temp=root ;
  switch(ch)
  {
    case 1 : cout<<"\nInOrder Output of Tree is :";
		  inOrder(root);
		  break;
    case 2 : cout<<"\nPre Order Output of Tree is :";
		  preOrder(root);
		  break;
    case 3 : cout<<"\nPost Order Output of Tree is :";
		  postOrder(root);
		  break;
  }	  
}
void BTree :: path(Tree* root ,int pathlen) {
/*  
	objective : to find path from root to every leaf node
	input : root of tree ( Tree * pointer )
	output : none 
	approach : traversing and finding every leaf node path from root 
*/

    if (root==NULL)
        return;
    arr[pathlen] = root->data;
    pathlen++;
    if (root->left==NULL && root->right==NULL) {
        printPath(arr, pathlen);
    }
    else {
        path(root->left , pathlen);
        path(root->right , pathlen);
    }
}

void BTree ::printPath(int arr[], int len) {
/*  
	objective : to find path from root to every leaf node
	input : array (int) with path of one leaf node, length to be checked
	output : none 
	approach : given path is equal to the entred sum 
*/
    int temp = 0;
    for (int i=0; i<len; i++) {
        temp += arr[i];
    }
    if ( sum == temp ) {
        cout << "\nPossible Path according to given sum\n";
        for (int i = 0; i < len; i++) {
            cout << arr[i] <<"\t";
            count++;
        }
    }
    cout << "\n";
}
int main()
{
  
  int ch,ele;
  char chh;
  BTree ob;
  do{
	system("clear");
	cout<<"\nPress 1 To Enter New Node.";
	cout<<"\nPress 2 To Show Tree In InOrder Format.";
	cout<<"\nPress 3 To Show Tree In PreOrder Format.";
	cout<<"\nPress 4 To Show Tree In PostOrder Format.";
	cout<<"\nPress 5 To Print Path For Perticular Sum.";
	cout<<"\nPress 6 To Exit.";      
	cin>>ch;
	switch(ch)
	{
	  case 1 : cout<<"\nEnter the New Node.";
			cin>>ele;
			ob.root = ob.insert(ob.root,ele);
			break;
	  case 2 : ob.display(1);
			break;
	  case 3 : ob.display(2);
			break;
	  case 4 : ob.display(3);
			break;
	   case 5 : cout<<"\nEnter the Sum.";
			cin>>ele;
			ob.sum = ele;
			ob.path(ob.root,0);
			break;
	  case 6 : exit(0);
      }
      cout<<"\nWould You Like To Continue...('Y'es,'N'o).";
      cin>>chh;
  }while(chh=='y'||chh=='Y');
  return 0;
}
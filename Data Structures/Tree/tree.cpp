#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

class Tree
{
	public:
	int data;
	Tree * right;
	Tree * left;
	Tree(int _data,Tree * _left=0, Tree * _right=0)
	 {
	      data=_data;
	      left=_left;
	      right=_right;   
	  }
};
class BTree
{
	Tree * root;
	public:
	BTree(){root=0;}
	void Insert(int ele);
	void search(int ele);
	void deleteCopying(Tree *& node);
	void inOrder(Tree* root);
	void postOrder(Tree* root);
	void preOrder(Tree* root);
	void display(int);
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
void BTree::Insert(int ele)
{
	system("clear");
	if(root==0)
	{ 
	      root = new Tree(ele,0,0);
	      return;
	}
	else
	{	
	      int q=0;
	      Tree * temp=root;
	      while(temp->left!=0||temp->right!=0)
	      {			
		    if(temp->data==ele)
		    { 
			  cout<<"\nEntered Data already exist.";
			  q=1;
			  return;
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
      if(q==0)
      {
	  if(temp->left==0)
	      temp->left=new Tree(ele,0,0);
	  else 
	      temp->right=new Tree(ele,0,0);
      }
  }
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
	cout<<"\nPress 5 To Search a pre existing Node.";
	cout<<"\nPress 6 To Exit.";      
	cin>>ch;
	switch(ch)
	{
	  case 1 : cout<<"\nEnter the New Node.";
			cin>>ele;
			ob.Insert(ele);
			break;
	  case 2 : ob.display(1);
			break;
	  case 3 : ob.display(2);
			break;
	  case 4 : ob.display(3);
			break;
	   case 5 : cout<<"\nEnter the Node.";
			cin>>ele;
			ob.search(ele);
			break;
	  case 6 : exit(0);
      }
      cout<<"\nWould You Like To Continue...('Y'es,'N'o).";
      cin>>chh;
  }while(chh=='y'||chh=='Y');
  return 0;
}
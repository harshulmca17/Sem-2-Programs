#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

class MATRIX
{
      int *array;
      int **matrix;	
      public:
      
      int l;
      int r;
      int c;
           
      MATRIX(int ,int );
      void Diagonal();
      void TDiagonal();
      void UpperT();
      void LowerT();
  
};
MATRIX::MATRIX(int s,int a)
{
  switch(a)
  {
    case 1 : l=s;
		 r=s;
		 c=s;
		
		 array = new int [l];
		 break;
    case 2 : l=(3*s)-2;
		 r=s;
		 c=s;
		 matrix = new int *[r];
		 for(int i=0;i<r;i++)
		   matrix[i] = new int [c];
		 array = new int [l];
		 break;
    
    case 3 : l=(s*(s+1))/2;
		 r=s;
		 c=s;
		 matrix = new int *[r];
		 for(int i=0;i<r;i++)
		   matrix[i] = new int [c];
		 array = new int [l];
		 break;
      
    case 4 : l=(s*(s+1))/2;
		  r=s;
		 c=s;
		 matrix = new int *[r];
		 for(int i=0;i<r;i++)
		   matrix[i] = new int [c];
		 array = new int [l];
		 break;    
  } 
  
}
void MATRIX::Diagonal()
{
    cout<<"\nEnter Elements In Diagonal Matrix : ";
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
      {		
	  
	  if(i==j)
	  {  l=j;
	      cin>>array[l];
	      l++;
	  }
      }
      cout<<"\nRequired Matrix is :\n";
      int m=0;
      for(int i=0;i<r;i++)
      {	for(int j=0;j<c;j++)
	 {
	    if(i==j)
	    {
		
		cout<<array[m]<<" ";
		m++;
	    }
	    else 
	      cout<<"0"<<" ";
	   
	   
	}
	cout<<"\n";
    }
  
  
}
void MATRIX::TDiagonal()
{
    cout<<"\nEnter Elements In Tri Diagonal Matrix : ";
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
      {		
	  
	  if(i==j || i == (j+1) || i == (j-1) )
	  {  l=2*i+j;
	      cin>>array[l];
	      l++;
	  }
      }
      cout<<"\nRequired Matrix is :\n";
      int m=0;
      for(int i=0;i<r;i++)
      {	for(int j=0;j<c;j++)
	 {
	    if(i==j ||  i == (j+1) || i == (j-1) )
	    {
		
		cout<<array[m]<<" ";
		m++;
	    }
	    else 
	      cout<<"0"<<" ";
	   
	   
	}
	cout<<"\n";
    }
  
  
}
void MATRIX::UpperT()
{
    cout<<"\nEnter Elements In Upper Triangular Matrix : ";
    for(int i=0;i<r;i++)
       for(int j=0;j<c;j++)
      {		
	  
	  if(i<=j)
	  {  l=(i*r)+j-((i*(i+1)))/2;
	      cin>>array[l];
	      l++;
	  }
      }
      cout<<"\nRequired Matrix is :\n";
      int m=0;
      for(int i=0;i<r;i++)
      {	for(int j=0;j<c;j++)
	 {
	    if(i<=j)
	    {
		
		cout<<array[m]<<" ";
		m++;
	    }
	    else 
	      cout<<"0"<<" ";
	   
	   
	}
	cout<<"\n";
    }
  
  
}
void MATRIX::LowerT()
{
    cout<<"\nEnter Elements In Lower Triangular Matrix : ";
    for(int i=0;i<r;i++)
       for(int j=0;j<c;j++)
      {		
	  
	  if(i>=j)
	  {  l=((i*(i+1))/2)+j;
	      cin>>array[l];
	      l++;
	  }
      }
      cout<<"\nRequired Matrix is :\n";
      int m=0;
      for(int i=0;i<r;i++)
      {	for(int j=0;j<c;j++)
	 {
	    if(i>=j)
	    {
		
		cout<<array[m]<<" ";
		m++;
	    }
	    else 
	      cout<<"0"<<" ";
	   
	   
	}
	cout<<"\n";
    }
  
  
}

int main()
{
      int ch,s;
      char chh;
      do{
	system("clear");
      cout<<"\nPress 1 To Create Diagonal Sparse Matrix .";
      cout<<"\nPress 2 To Create Tri Diagonal Sparse Matrix .";
      cout<<"\nPress 3 To Create Upper Triangular Sparse Matrix .";
      cout<<"\nPress 4 To Create Lower Triangular Sparse Matrix .";
      cout<<"\nPress 5 To Exit.";
      cin>>ch;
      switch(ch)
      {
	case 1 :{	cout<<"\nEnter the Size of the Matrix.";
			cin>>s;
			MATRIX ob(s,1);
			ob.Diagonal();
			break;
		    }
			
	case 2 :{	cout<<"\nEnter the Size of the Matrix.";
			cin>>s;
			MATRIX ob1(s,2);
			ob1.TDiagonal();
			break;
		    }
	case 3 : { cout<<"\nEnter the Size of the Matrix.";
			cin>>s;
			MATRIX ob2(s,3);
			ob2.UpperT();
			break;
			}
	case 4 :{	cout<<"\nEnter the Size of the Matrix.";
			cin>>s;
			MATRIX ob3(s,4);
			ob3.LowerT();
			break;
		  }
	case 5 : exit(0);
      }
      cout<<"\nWould You Like To Contniue...('Y'es,'N'o).";
      cin>>chh;
  }while(chh=='y'||chh=='Y');
  return 0;
}
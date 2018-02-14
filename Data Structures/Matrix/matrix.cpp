#include<iostream>
#include<cstdlib>

using namespace std;
class matrix
{
	int **matrx;
	public:
	int r;
	int c;
	matrix();
	void fillmatrix();
		
};
matrix::matrix()
{
	r=0;
	c=0;
	matrx=new int *[r];
	for(int i=0;i<r;i++)
		matrx[i]=new int [c];		
	for(int k=0;k<r;k++)		
		for(int j=0;j<c;j++)
			matrx[k][j]=0;
}
void matrix::fillmatrix()
{
	cout<<"\nEnter the Size of the Matrix:";
	cin>>r>>c;
	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			int m=0;
			cout<<"\nEnter "<<m<<" Element: ";
			cin>>matrx[i][j];
		}
	
}
int main()
{
	matrix ob;
	ob.fillmatrix();
	return 0;
}
			

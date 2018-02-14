// program for projecting a 3D cube using Parallel  projection

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define f 1
void drawcube(int [8][3]);
void multiply(const float[4],const float[4][4],float [4]);
void lline(const int,const int,const int,const int);
void get_projected_point(int &,int &,int &);
int main()
{   int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\bgi");

	int cube[8][3] = {{370,200,50},{470,200,50},{470,300,50},{370,300,50},{370,200,-50},{470,200,-50},{470,300,-50},{370,300,-50},};
	drawcube(cube);
	outtextxy(400,320,"cube");
	getch();
	closegraph();
	return 0;
}

void drawcube(int cb[8][3])
{    line(cb[0][0],cb[0][1],cb[1][0],cb[1][1]);
	line(cb[1][0],cb[1][1],cb[2][0],cb[2][1]);
	line(cb[2][0],cb[2][1],cb[3][0],cb[3][1]);
	line(cb[3][0],cb[3][1],cb[0][0],cb[0][1]);
	line(cb[4][0],cb[4][1],cb[5][0],cb[5][1]);
	line(cb[5][0],cb[5][1],cb[6][0],cb[6][1]);
	line(cb[6][0],cb[6][1],cb[7][0],cb[7][1]);
	line(cb[7][0],cb[7][1],cb[4][0],cb[4][1]);
	line(cb[0][0],cb[0][1],cb[4][0],cb[4][1]);
	line(cb[1][0],cb[1][1],cb[5][0],cb[5][1]);
	line(cb[2][0],cb[2][1],cb[6][0],cb[6][1]);
	line(cb[3][0],cb[3][1],cb[7][0],cb[7][1]);
	getch();
	clrscr();
       for(int i=0;i<8;i++)
	get_projected_point(cb[i][0],cb[i][1],cb[i][2]);
	cout<<"Projection of Unit Cube in xy plane";
	line(cb[0][0],cb[0][1],cb[1][0],cb[1][1]);
	line(cb[1][0],cb[1][1],cb[2][0],cb[2][1]);
	line(cb[2][0],cb[2][1],cb[3][0],cb[3][1]);
	line(cb[3][0],cb[3][1],cb[0][0],cb[0][1]);
	line(cb[4][0],cb[4][1],cb[5][0],cb[5][1]);
	line(cb[5][0],cb[5][1],cb[6][0],cb[6][1]);
	line(cb[6][0],cb[6][1],cb[7][0],cb[7][1]);
	line(cb[7][0],cb[7][1],cb[4][0],cb[4][1]);
	line(cb[0][0],cb[0][1],cb[4][0],cb[4][1]);
	line(cb[1][0],cb[1][1],cb[5][0],cb[5][1]);
	line(cb[2][0],cb[2][1],cb[6][0],cb[6][1]);
	line(cb[3][0],cb[3][1],cb[7][0],cb[7][1]);
}


void get_projected_point(int &x,int &y,int &z)
{   float fcos0 = (f*cos(45*(3.14/180)));
	float fsin0 = (f*sin(45*(3.14/180)));
	float per_v[4][4] = {{1,0,0,0},{0,1,0,0},{fcos0,fsin0,0,0},{0,0,0,1}};
	float xy[4] = {x,y,z,1};
	float new_xy[4] = {0,0,0,0};
	multiply(xy,per_v,new_xy);
	x=(int) (new_xy[0]+.5);
	y=(int) (new_xy[1]+.5);
	z=(int) (new_xy[2]+.5);
}

void multiply(const float mat_1[4],const float mat_2[4][4],float mat_3[4])
{   for(int i=0;i<4;i++)
	{    for(int j=0;j<4;j++)
		mat_3[i] += (mat_1[j]*mat_2[j][i]);
	}

}
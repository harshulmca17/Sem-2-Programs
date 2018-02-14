//PROGRAM TO IMPLEMENT DDA LINE ALGORITHM

#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{
	clrscr();
	int gm,gd=DETECT;
	int mode;
	double  x0,x1,y0,y1;

	initgraph(&gd,&gm,"d:\\tc\\bgi");
	mode=getgraphmode();
	restorecrtmode();
	clrscr();

	cout<<"\nENTER THE STARTING COORDINATES: ";
	cout<<"\nx0:- ";
	cin>>x0;
	cout<<"y0:- ";
	cin>>y0;
	cout<<"\nENTER THE ENDING COORDINATES: ";
	cout<<"\nx1:- ";
	cin>>x1;
	cout<<"y1:- ";
	cin>>y1;

	int color=11;
	double dy=y1-y0;
	double dx=x1-x0;
	double m=dy/dx;
	setgraphmode(mode);
	double y=y0;
	int z;
	for(int x=x0;x<=x1;x++)
	{
		z=floor(y+0.5);
		putpixel(floor(x+0.5)+10,470-floor(z+0.5),color);
		y=y+m;

	}
	getch();
	closegraph();
}

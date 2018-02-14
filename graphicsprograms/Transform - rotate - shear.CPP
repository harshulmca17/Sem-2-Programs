//Program for Translation,shearing and rotation of a Triangle


#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<process.h>
int x1,y1,x2,y2,x3,y3,x,y;
float a;
void enter_triangle();
void main()
{   int ch,gm,gd;
	do
	{    gd=DETECT;
	     initgraph(&gd,&gm,"C:\\tc\\bgi");
	     cout<<"\t\tTransformation\n";
	     cout<<"\t\t1: Translation\n";
	     cout<<"\t\t2: Rotation\n";
	     cout<<"\t\t3: Shearing\n";
	     cout<<"\t\t4: Exit\n";
	     cout<<"\t\tEnter ur choice : ";
	     cin>>ch;
	     switch(ch)
	     {    case 1: enter_triangle();
		  cout<<"Enter Tranlation coordinates\n";
		  cin>>x>>y;
		  moveto(x1+x,y1+y);
		  lineto(x2+x,y2+y);
		  moveto(x2+x,y2+y);
		  lineto(x3+x,y3+y);
		  moveto(x3+x,y3+y);
		  lineto(x1+x,y1+y);
		  getch();
		  break;

		  case 2: enter_triangle();
		  cout<<"Enter angle of Rotation : ";
		  cin>>a;
		  a=a*(3.14/180);
		  x1 = (x1 * cos(a)) - (y1 * sin(a));
		  y1 = (x1 * cos(a)) + (y1 * sin(a));
		  x2 = (x2 * cos(a)) - (y2 * sin(a));
		  y2 = (x2 * cos(a)) + (y2 * sin(a));
		  x3 = (x3 * cos(a)) - (y3 * sin(a));
		  y3 = (x3 * cos(a)) + (y3 * sin(a));
		  line(x1,y1,x2,y2);
		  line(x2,y2,x3,y3);
		  line(x3,y3,x1,y1);
		  getch();
		  break;

		  case 3:  enter_triangle();
		  cout<<"Enter Shear coordinates \n";
		  cin>>x>>y;
		  cout<<"shearing in x axis\n";
		  moveto(x1,y1);
		  lineto(x2*x,y2);
		  moveto(x2*x,y2);
		  lineto(x3*x,y3);
		  moveto(x3*x,y3);
		  lineto(x1,y1);
		  cout<<"shearing in y axis\n";
		  moveto(x1,y1);
		  lineto(x2,y2*y);
		  moveto(x2,y2*y);
		  lineto(x3,y3*y);
		  moveto(x3,y3*y);
		  lineto(x1,y1);
		  getch();
		  break;

		  case 4:exit(0);
	     }
	}while(ch!=4);
}
void enter_triangle()
{   	cout<<"enter coordinates of triangle\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	getch();
}
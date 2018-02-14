

//Implement scan conversion of line using BRESENHAM'S ALGORITHM.


#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void bresenham( int xa, int ya, int xb, int yb );

void main( )
{
	clrscr( );
	int x1, y1, x2, y2;

	cout << " \t ***THIS PROGRAM USE BRESENHAM'S ALGORITHM FOR SCAN CONVERSION OF A LINE*** ";

	cout << " \n\n Enter the value of first x coordinates: ";
	cin >> x1;
	cout << " Enter the value of first y coordinates: ";
	cin >> y1;
	cout << " \n\n Enter the value of second x coordinates: ";
	cin >> x2;
	cout << " Enter the value of second y coordinates: ";
	cin >> y2;

	int gdriver = DETECT;
	int gmode;
	initgraph( &gdriver, &gmode, "..\\BGI" );

	cleardevice( );

	bresenham( x1, y1, x2, y2 );

	getch( );
	closegraph( );
}

void bresenham( int xa, int ya, int xb, int yb )
{

	int dx, dy, x, y;
	int xend, p;

	dx = abs( xa - xb );
	dy = abs( ya - yb );

	setfillstyle( 1, GREEN );
	setcolor( RED );
	outtextxy( 100, 10, " SCAN CONVERTED LINE USING BRESENHAM'S ALGORITHM " );
	line( 10, 480, 10, 0 );
	outtextxy( 0, 10, " Y " );
	line( 0, 470, 640, 470 );
	outtextxy( 620, 472, " X " );

	p = 2 * dy - dx;

	if( xa > xb )
	{
		x = xb;
		y = yb;
		xend = xa;
	}
	else
	{
		x = xa;
		y = ya;
		xend = xb;
	}

	putpixel( x, y, 10 );

	while( x < xend )
	{
		x++;

		if( p < 0 )
			p += 2 * dy;
		else
		{
			y++;
			p += 2 * ( dy - dx );
		}

		putpixel( x, y, 10 );
	}

}

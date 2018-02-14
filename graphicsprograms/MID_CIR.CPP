//Implement scan conversion of circle using MID POINT ALGORITHM.
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void mid_point_circle( int a, int b, int z );

void main( )
{
	clrscr( );
	int x, y, r;

	cout << " \t ***THIS PROGRAM USE MID POINT ALGORITHM FOR SCAN CONVERSION OF A CIRCLE*** ";

	cout << " \n\n Enter the value of x coordinates: ";
	cin >> x;
	cout << " Enter the value of y coordinates: ";
	cin >> y;
	cout << " Enter the radius of the circle: ";
	cin >> r;
	int gdriver = DETECT;
	int gmode;
	initgraph( &gdriver, &gmode, "..\\BGI" );

	cleardevice( );

	mid_point_circle( x, y, r );

	getch( );
	closegraph( );
}

void mid_point_circle( int a, int b, int z )
{
	setfillstyle( 1, GREEN );
	setcolor( RED );
	outtextxy( 100, 10, " SCAN CONVERTED CIRCLE USING MID POINT ALGORITHM " );
	line( 10, 480, 10, 0 );
	outtextxy( 0, 10, " Y " );
	line( 0, 470, 640, 470 );
	outtextxy( 620, 472, " X " );
	int x = 0, y = z, d = 1 - z;
	while( x <= y )
	{
		putpixel( 10 + ( a + x ), 470 - ( b + y ), 2 );
		putpixel( 10 + ( a + x ), 470 - ( b - y ), 2 );
		putpixel( 10 + ( a - x ), 470 - ( b + y ), 2 );
		putpixel( 10 + ( a - x ), 470 - ( b - y ), 2 );
		putpixel( 10 + ( a + y ), 470 - ( b + x ), 2 );
		putpixel( 10 + ( a + y ), 470 - ( b - x ), 2 );
		putpixel( 10 + ( a - y ), 470 - ( b + x ), 2 );
		putpixel( 10 + ( a - y ), 470 - ( b - x ), 2 );

		if( d < 0 )
			d = d + 2 * x + 3;
		else
			d = d + 2 * x - 2 * y-- + 5;
		x++;
	}
}

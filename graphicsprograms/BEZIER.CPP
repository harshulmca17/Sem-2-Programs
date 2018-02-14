
//		Implement BEZIER CURVE with 4 control points.


#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

#define STEPS 10

void cubic_bezier( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int colour )
{
	int cx[4], cy[4];
	int i = 0;
	int AX, AY, BX, BY, CX, CY, DX, DY, x, y;
	double stepsize, t;

	cx[0] = x1;
	cy[0] = y1;
	cx[1] = x2;
	cy[1] = y2;
	cx[2] = x3;
	cy[2] = y3;
	cx[3] = x4;
	cy[3] = y4;

	for( i = 0; i < 4; i++ )
	{
		setcolor( colour );
		circle( cx[i], cy[i], 5 );
	}

	setcolor( colour );
	AX = -cx[0] + 3 * cx[1] + ( -3 * cx[2] ) + cx[3];
	AY = -cy[0] + 3 * cy[1] + ( -3 * cy[2] ) + cy[3];
	BX = 3 * cx[0] + ( -6 * cx[1] ) + 3 * cx[2];
	BY = 3 * cy[0] + ( -6 * cy[1] ) + 3 * cy[2];
	CX = ( -3 * cx[0] ) + 3 * cx[1];
	CY = ( -3 * cy[0] ) + 3 * cy[1];
	DX = cx[0];
	DY = cy[1];

	for( i = 0; i < 4; i++ )
		putpixel( cx[i], cy[i], colour );

	setcolor( abs( colour ) );
	setlinestyle( DOTTED_LINE, 0, NORM_WIDTH );
	moveto( cx[0], cy[0] );

	for( i = 0; i < 4; i++ )
		lineto( cx[i], cy[i] );

	setlinestyle( SOLID_LINE, 0, NORM_WIDTH );
	setcolor( colour );
	stepsize = 1.0 / ( double ) STEPS;
	moveto( DX, DY );

	for( i = 0; i < STEPS; i++ )
	{
		double m, n;
		m = t * t * t;
		n = t * t;
		t = stepsize * ( double ) i;
		x = ( AX * m ) + ( BX * n ) + ( CX * t ) + DX;
		y = ( AY * m ) + ( BY * n ) + ( CY * t ) + DY;
	}

}

void main( )
{
	clrscr( );
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;

	cout << " \t ***THIS PROGRAM PLOTS THE BEZIER CURVE WITH FOUR CONTROL POINTS*** ";

	cout << " \n\n Enter the value of first x coordinates: ";
	cin >> x1;
	cout << " Enter the value of first y coordinates: ";
	cin >> y1;
	cout << " \n\n Enter the value of second x coordinates: ";
	cin >> x2;
	cout << " Enter the value of second y coordinates: ";
	cin >> y2;
	cout << " \n\n Enter the value of third x coordinates: ";
	cin >> x3;
	cout << " Enter the value of third y coordinates: ";
	cin >> y3;
	cout << " \n\n Enter the value of fourth x coordinates: ";
	cin >> x4;
	cout << " Enter the value of fourth y coordinates: ";
	cin >> y4;

	int gdriver = DETECT;
	int gmode;
	initgraph( &gdriver, &gmode, "..\\BGI" );

	cleardevice( );

	outtextxy( 100, 10, " BEZIER CURVE " );

	cubic_bezier( x1, y1, x2, y2, x3, y3, x4, y4, 4 );

	getch( );
	closegraph( );
}

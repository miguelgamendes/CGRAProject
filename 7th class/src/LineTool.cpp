#include "LineTool.h"
#include "math.h"

#define PI 3.14159265359

void LineTool::mousePressed(int x, int y)
{
	// Reset start coordinates and active (current) coordinates
	sx=x;
	sy=y;
	currx=x;
	curry=y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw first line (one pixel)
	drawLine(sx,sy,currx,curry);
}

void LineTool::mouseDragged(int x, int y)
{
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawLine(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new line
	drawLine(sx,sy,currx,curry);
}

void LineTool::mouseReleased(int x, int y)
{
	// Redraw previous line to erase it
	drawLine(sx,sy,currx,curry);

	// Set normal mode and color to draw fianl line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawLine(sx,sy,x,y);
}



void LineTool::drawLine(int xi, int yi, int xf, int yf)
{
	// draws a line; 
	// simple flawed version, only draws in quadrants 1 and 4, 
	// and iterates over x, meaning there will be gaps on octants 2 and 7
	// where abs(delta y) > abs(delta x)

	int a, b, d, inc1, inc2, x, y, incx, incy;
	double ang = acos((xf - xi) / sqrt( (float)(xf - xi)*(xf - xi) + (float)(yf - yi)*(yf - yi) ) );
	ang = ang * PI / 180; //radians to degrees
	if(ang >= 0 && ang <= 45) { //1st octant
	} else if( ang > 45 && ang <= 135 ) { //2nd  & 3rd octant
		int tmp;
		tmp = xi;
		xi = yi;
		yi = tmp;

		tmp = xf;
		xf = yf;
		yf = tmp;
	} //else if( ang > 90 && ang <= 135) {

	if( xf < xi )
		incx = -1;
	else
		incx = 1;
	if(yf < yi)
		incy = -1;
	else
		incy = 1;

	a = xf - xi;
	b = yf - yi;
	inc2 = 2*b;
	d = inc2 - a;
	inc1 = d - a;
	 x = xi;
	 y = yi;

	 for(int i = 0; i < a; i++) {
		 canvas->setPixel(x,y);
		 x += incx;
		 if( d >= 0) {
			 y += incy;
			 d += inc1;
		 } else
			 d += inc2;
	 }
}
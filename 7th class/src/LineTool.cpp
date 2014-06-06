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

	int dx, dy, d, inc1, inc2, x, y, incx, incy;
	
	dx = xf - xi;
	if (dx>0)
		incx = 1;
	else {
		dx = -dx;
		incx = -1;
	}

	dy = yf - yi;
	if (dy > 0)
		incy = 1;
	else {
		dy = -dy;
		incy = -1;
	}

	x = xi;
	y = yi;

	if(dx >= dy) {
		inc2 = 2*dy;
		d = inc2 - dx;
		inc1 = d - dx;


		for(int i = 0; i < dx; i++) {
			canvas->setPixel(x,y);
			x += incx;
			if( d >= 0) {
				y += incy;
				d += inc1;
			} else
				d += inc2;
		}
	} else {
		inc2 = 2*dx;
		d = inc2 - dy;
		inc1 = d - dy;

		for(int i = 0; i < dy; i++) {
			canvas->setPixel(x,y);
			y += incy;
			if( d >= 0) {
				x += incx;
				d += inc1;
			} else
				d += inc2;
		}
	}
}
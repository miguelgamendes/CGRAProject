#include "RectTool.h"

void RectTool::mousePressed(int x, int y)
{
	// Reset start coordinates and active (current) coordinates
	sx=x;
	sy=y;
	currx=x;
	curry=y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw first Rect (one pixel)
	drawRect(sx,sy,currx,curry);
}

void RectTool::mouseDragged(int x, int y)
{
	// Redraw previous Rect (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawRect(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new Rect
	drawRect(sx,sy,currx,curry);
}

void RectTool::mouseReleased(int x, int y)
{
	// Redraw previous Rect to erase it
	drawRect(sx,sy,currx,curry);

	// Set normal mode and color to draw fianl Rect
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final Rect
	drawRect(sx,sy,x,y);
}



void RectTool::drawRect(int xi, int yi, int xf, int yf)
{
	int tmp;

	if(xi >= xf) {
		tmp = xi;
		xi = xf;
		xf = tmp;
	}

	if(yi >= yf) {
		tmp = yf;
		yf = yi;
		yi = tmp;
	}

	for (int x=xi;x<=xf;x++) {	//draw horizontal lines
		canvas->setPixel(x,yi);
		canvas->setPixel(x,yf);
	}

	for(int y=yi; y < yf; y++) { //draw vertical lines
		canvas->setPixel(xi,y);
		canvas->setPixel(xf,y);
	}
}
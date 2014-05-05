#include "Clock.h"

Clock::Clock() {
	myCyl = new myCylinder(12, 1, true);
}

void Clock::draw() {
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
		glScalef(1.0f, 1.0f, 0.5f);
		glTranslatef(7.5f,7.0f,0.0f);
		myCyl->draw();
	glPopMatrix();
}
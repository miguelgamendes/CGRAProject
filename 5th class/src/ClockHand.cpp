#include "ClockHand.h"

void ClockHand::draw(){
	glPushMatrix();
	glBegin(GL_POLYGON);
		glVertex3f(-0.1f, -0.1f, 0.0f);
		glVertex3f(0.1f, -0.1f, 0.0f);
		glVertex3f(0.05f, 0.9f, 0.0f);
		glVertex3f(-0.05f, 0.9f, 0.0f);
	glEnd();
	glPopMatrix();
}

void ClockHand::setAngle(float a) {
	this->angle = a;
}
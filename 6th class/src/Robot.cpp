#include "Robot.h"

#define M_PI 3.1415926535897932384626433832795
float SIXTH = 1/6;

Robot::Robot() {
	face = Face();
};

void Robot::draw() {
	glPushMatrix();
	face.draw();
	for(unsigned int i = 0; i < 3; i++) {
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		face.draw();
	}
	glPopMatrix();
};
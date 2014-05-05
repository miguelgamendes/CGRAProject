#include "Robot.h"
#include "Face.cpp"

float SIXTH = 1/6;

Robot::Robot(int stacks) {
	face(stacks);
};

void Robot::draw() {
	glPushMatrix();
	for(int i = 0; i < 4; i++) {
		glRotatef(i*2*M_PI/3, 1.0, 0.0, 0.0);
		face.draw();
	};
};

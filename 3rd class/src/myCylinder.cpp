#include "myCylinder.h"
#include <math.h>

#define M_PI 3.1415926535897932384626433832795

myCylinder::myCylinder(int slices, int stacks/*, bool smooth*/) {
	this->slices = slices;
	this->stacks = stacks;
	this->angle = 2*M_PI/slices;
}

void myCylinder::draw(){

	glPushMatrix();

	//top
	glBegin(GL_POLYGON);
		glNormal3f(0.0f, 0.0f, 1.0f); //vai ser desenhado sobre o eixo dos z
		for(int i = 0; i < slices; i++)
			glVertex3f(cos(angle * i), sin(angle * i), 1);

	glEnd();
	glPushMatrix();

	//bottom
	glRotatef(180.0f,1.0f,0.0f,0.0f);
	glPopMatrix();

	glPopMatrix();
		
		
}
#include "myCylinder.h"
#include <math.h>

#define M_PI 3.1415926535897932384626433832795

myCylinder::myCylinder(int slices, int stacks/*, bool smooth*/) {
	this->slices = slices;
	this->cellSize = 1 / stacks;
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
	glPopMatrix();

	//bottom
	glPushMatrix();
	glBegin(GL_POLYGON);
		glNormal3f(0.0f, 0.0f, 1.0f); //vai ser desenhado sobre o eixo dos z
		for(int i = 0; i < slices; i++)
			glVertex3f(cos(angle * -i), sin(angle * -i), 0);

	glEnd();
	glPopMatrix();

	//faces
	glPushMatrix();

	for(int j = 1; j >= 0; j-cellSize)
		for(int i = 0; i < slices; i++)
		{
			glBegin(GL_POLYGON);
				glNormal3f((cos(angle * i) + cos(angle *(i+1)) / 2), -(sin(angle * i) + sin(angle * -(i+1)) / 2), 1);
				glVertex3f(cos(angle * i), sin(angle * -i), j);
				glVertex3f(cos(angle * (i+1)), sin(angle * -(i+1)), j);
				glVertex3f(cos(angle * (i+1)), sin(angle * -(i+1)), j - cellSize);
				glVertex3f(cos(angle * i), sin(angle * -i), j - cellSize);
			glEnd();
		}
	glPopMatrix();

}
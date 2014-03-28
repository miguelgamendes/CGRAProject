#include "myCylinder.h"
#include <math.h>

#define M_PI 3.1415926535897932384626433832795

myCylinder::myCylinder(int slices, int stacks, bool smooth) {
	this->slices = slices;
	this->cellSize = 1 / (double)stacks;
	this->delta = 2*M_PI/slices;
	this->stacks = stacks;
	this->smooth = smooth;
}

void myCylinder::draw(){

	glEnable(GL_LINE_SMOOTH);

	glPushMatrix();

	//top
	glBegin(GL_POLYGON);

		for(int i = 0; i < slices; i++)
		{
			glNormal3f(cos(delta * i), sin(delta * i), 1); //vai ser desenhado sobre o eixo dos z
			glVertex3f(cos(delta * i), sin(delta * i), 1);
		}
	glEnd();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glBegin(GL_POLYGON);
		for(int i = 0; i < slices; i++)
		{
			glNormal3f(cos(delta * -i), sin(delta * -i), 0); //vai ser desenhado sobre o eixo dos z
			glVertex3f(cos(delta * -i), sin(delta * -i), 0);
		}

	glEnd();
	glPopMatrix();

	//faces
	glPushMatrix();

		double co1 = 1;
		double si1 = 0;
		double co2 = cos(delta);
		double si2 = sin(delta);

		double angle = 0;
		

	if(smooth)
		for(int j = 0; j <= slices; j++) //slices
		{
				co1 = co2;
				si1 = si2;
				co2 = cos(angle);
				si2 = sin(angle);

			for(int i = 0; i < stacks; i++) //stacks
			{
				glPushMatrix();
				glBegin(GL_POLYGON);
					glNormal3f(co1, si1, 0);
					glVertex3f(co1, si1, 1 - i*cellSize);
					glNormal3f(co1, si1, 0);
					glVertex3f(co1, si1, 1 - (i+1)*cellSize);
					glNormal3f(co2, si2, 0);
					glVertex3f(co2, si2, 1 - (i+1)*cellSize);
					glNormal3f(co2, si2, 0);
					glVertex3f(co2, si2, 1 - i*cellSize);
				glEnd();
				glPopMatrix();

			}
			angle += delta;
		}
	else
		for(int j = 0; j <= slices; j++) //slices
		{
			co1 = co2;
			si1 = si2;
			co2 = cos(angle);
			si2 = sin(angle);

			for(int i = 0; i < stacks; i++) //stacks
			{
				glPushMatrix();
				glBegin(GL_POLYGON);
					glNormal3f((co1 + co2) / 2, (si1 + si2) / 2, 0);
					glVertex3f(co1, si1, 1 - i*cellSize);
					glVertex3f(co1, si1, 1 - (i+1)*cellSize);
					glVertex3f(co2, si2, 1 - (i+1)*cellSize);
					glVertex3f(co2, si2, 1 - i*cellSize);
				glEnd();
				glPopMatrix();
			}
			angle += delta;
		}
	glPopMatrix();

}
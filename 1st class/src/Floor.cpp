#include "Floor.h"

void Floor::draw(){
	glPushMatrix();
	glTranslatef(0.0f, 0.05f, 0.0f);
	glScalef(8.0f, 0.1f, 6.0f);
	myCube.draw();
	glPopMatrix();
}
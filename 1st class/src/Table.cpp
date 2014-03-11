#include "Table.h"

void Table::draw(){
	//draw table-top
	glPushMatrix();
	glTranslatef(0.0f, 1.75f, 0.0f);
	glScalef(5.0f, 0.3f, 3.0f);
	myCube.draw();
	glPopMatrix();

	//draw legs
	//front left leg
	glPushMatrix();
	glTranslatef(-2.1f, -0.15f, 1.1f);
	glScalef(0.3f, 3.5f, 0.3f);
	myCube.draw();
	glPopMatrix();

	//front right leg
	glPushMatrix();
	glTranslatef(2.1f, -0.15f, 1.1f);
	glScalef(0.3f, 3.5f, 0.3f);
	myCube.draw();
	glPopMatrix();

	//back right leg
	glPushMatrix();
	glTranslatef(2.1f, -0.15f, -1.1f);
	glScalef(0.3f, 3.5f, 0.3f);
	myCube.draw();
	glPopMatrix();

	//back left leg
	glPushMatrix();
	glTranslatef(-2.1f, -0.15f, -1.1f);
	glScalef(0.3f, 3.5f, 0.3f);
	myCube.draw();
	glPopMatrix();
}
#include "Table.h"

Table::Table(float r, float t): angle(r), trans(t)
{
}

Table::Table(): angle(0), trans(0)
{
}

void Table::draw(){

	glPushMatrix();
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 1.9f, trans);

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

	glPopMatrix();
}
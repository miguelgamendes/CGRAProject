#include "Chair.h"

Chair::Chair(float r, float t): angle(r), trans(t)
{
}

Chair::Chair(): angle(0), trans(0)
{
}

void Chair::draw(){

	glPushMatrix();
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 1.95f, trans);

	//Seat *Ibiza*
	glPushMatrix();
	glScalef(2.5f, 0.2f,2.5f);
	myCube.draw();
	glPopMatrix();

	//Front Left Leg *Ibiza*
	glPushMatrix();
	glTranslatef(1.0f, -1.025f, 1.0f);
	glScalef(0.25f, 1.85f, 0.25f);
	myCube.draw();
	glPopMatrix();

	//Front Right Leg *Ibiza*
	glPushMatrix();
	glTranslatef(-1.0f, -1.025f, 1.0f);
	glScalef(0.25f, 1.85f, 0.25f);
	myCube.draw();
	glPopMatrix();

	//Back Left Leg *Ibiza*
	glPushMatrix();
	glTranslatef(1.0f, -1.025f, -1.0f);
	glScalef(0.25f, 1.85f, 0.25f);
	myCube.draw();
	glPopMatrix();

	//Back Right Leg *Ibiza*
	glPushMatrix();
	glTranslatef(-1.0f, -1.025f, -1.0f);
	glScalef(0.25f, 1.85f, 0.25f);
	myCube.draw();
	glPopMatrix();

	//Back back *Ibiza*
	glPushMatrix();
	glTranslatef(0.0f, 1.35f, -1.15f);
	glScalef(2.5f, 2.5f, 0.2f);
	myCube.draw();
	glPopMatrix();

	glPopMatrix();
}
#include "UnitCube.h"

void UnitCube::draw(){
	//frontal face
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.5f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//back face
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.5f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//right face
	glPushMatrix();
	glTranslatef(0.5f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//left face
	glPushMatrix();
	glTranslatef(-0.5f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//upper face
	glPushMatrix();
	glTranslatef(0.0f, 0.5f, 0.0f);
	glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//lower face
	glPushMatrix();
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();
}
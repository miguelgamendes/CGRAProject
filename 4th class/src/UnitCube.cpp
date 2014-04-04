#include "UnitCube.h"

void UnitCube::draw(){
	glDisable(GL_TEXTURE_2D);

	//frontal face
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.5f);
	glNormal3f(0.0f,0.0f,1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//back face
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.5f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	glNormal3f(0.0f,0.0f,1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//right face
	glPushMatrix();
	glTranslatef(0.5f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glNormal3f(0.0f,0.0f,1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//left face
	glPushMatrix();
	glTranslatef(-0.5f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glNormal3f(0.0f,0.0f,1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//upper face
	glPushMatrix();
	glTranslatef(0.0f, 0.5f, 0.0f);
	glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f,0.0f,1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();

	//lower face
	glPushMatrix();
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f,0.0f,1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glPopMatrix();
}

void UnitCube::draw(CGFappearance* appearance){
	glEnable(GL_TEXTURE_2D);
	appearance->apply();

	//frontal face
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.5f);
	drawRectangle();
	glPopMatrix();

	//back face
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.5f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	drawRectangle();
	glPopMatrix();

	//right face
	glPushMatrix();
	glTranslatef(0.5f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawRectangle();
	glPopMatrix();

	//left face
	glPushMatrix();
	glTranslatef(-0.5f, 0.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	drawRectangle();
	glPopMatrix();

	//upper face
	glPushMatrix();
	glTranslatef(0.0f, 0.5f, 0.0f);
	glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
	drawRectangle();
	glPopMatrix();

	//lower face
	glPushMatrix();
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	drawRectangle();
	glPopMatrix();
}

void UnitCube::drawRectangle(){
	glNormal3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(-0.5f, -0.5f);
		glTexCoord2f(1.0, 0.0f);
		glVertex2f(0.5f, -0.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(0.5f, 0.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-0.5f, 0.5f);
	glEnd();
}
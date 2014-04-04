#include "Table.h"

Table::Table(float r, float t): angle(r), trans(t)
{
	// Coefficients for table texture
	float ambTable[3] = {0.2, 0.2, 0.2};
	float difTable[3] = {0.8, 0.8, 0.8};
	float specTable[3] = {0.2, 0.2, 0.2};
	float shininessTable = 50.0f;

	tableAppearance = new CGFappearance(ambTable, difTable, specTable, shininessTable);
	tableAppearance->setTexture("table.png");
}

Table::Table(): angle(0), trans(0)
{
	// Coefficients for table texture
	float ambTable[3] = {0.2, 0.2, 0.2};
	float difTable[3] = {0.8, 0.8, 0.8};
	float specTable[3] = {0.2, 0.2, 0.2};
	float shininessTable = 50.0f;

	tableAppearance = new CGFappearance(ambTable, difTable, specTable, shininessTable);
	tableAppearance->setTexture("table.png");
}

void Table::draw(){

	glPushMatrix();
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 1.9f, trans);

	//draw table-top
	glPushMatrix();
	glTranslatef(0.0f, 1.75f, 0.0f);
	glScalef(5.0f, 0.3f, 3.0f);
	myCube.draw(tableAppearance);
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
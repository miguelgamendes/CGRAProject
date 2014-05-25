#include "Robot.h"

#define M_PI 3.1415926535897932384626433832795
float SIXTH = 1/6;

Robot::Robot() {
	face = Face();

	//coefficients for robot texture
	float ambRobot[3] = {0.2f, 0.2f, 0.2f};
	float difRobot[3] = {0.3f, 0.3f, 0.3f};
	float specRobot[3] = {0.7f, 0.7f, 0.7f};
	float shininessRobot = 100.0f;

	robotAppearance = new CGFappearance(ambRobot, difRobot, specRobot, shininessRobot);
	robotAppearance->setTexture("robot1.jpg");
};

void Robot::draw() {
	glPushMatrix();
	face.drawTextured(robotAppearance, 'f');
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	face.drawTextured(robotAppearance, 'l');
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	face.drawTextured(robotAppearance, 'b');
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	face.drawTextured(robotAppearance, 'r');
	glPopMatrix();
};
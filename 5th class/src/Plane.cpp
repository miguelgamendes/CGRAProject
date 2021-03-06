#include "Plane.h"
#include <GL/glu.h>

Plane::Plane(void)
{
	_numDivisions = 1;
}

Plane::Plane(int n)
{
	_numDivisions = n;
}


Plane::~Plane(void)
{
}

void Plane::draw()
{
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glVertex3f(bx + 1, 0, bz);
					glVertex3f(bx, 0, bz + 1);
				}
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}


void Plane::draw(CGFappearance* appearance)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	appearance->apply();

	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
				glTexCoord2f(float(bx)/_numDivisions, 0.0f);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glTexCoord2f((float(bx) + 1.0f)/_numDivisions, float(bz)/_numDivisions);
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2f(float(bx)/_numDivisions, (float(bz) + 1.0f)/_numDivisions);
					glVertex3f(bx, 0, bz + 1);
				}
				glTexCoord2f((float(bx) + 1)/_numDivisions, 1.0f);
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();
	glPopMatrix();
}

void Plane::drawClampSquare(CGFappearance* appearance, float xwidth, float ywidth)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	appearance->apply();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
				glTexCoord2f(1.5 - (_numDivisions/_numDivisions) * xwidth, ((_numDivisions - float(bx))/_numDivisions) * ywidth);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glTexCoord2f(1.5 - ((_numDivisions - float(bz))/_numDivisions) * xwidth, ((_numDivisions - (float(bx) + 1.0f))/_numDivisions) * ywidth);
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2f(1.5 - ((_numDivisions - (float(bz) + 1.0f))/_numDivisions) * xwidth, ((_numDivisions - float(bx))/_numDivisions) * ywidth);
					glVertex3f(bx, 0, bz + 1);
				}
				glTexCoord2f(1.5 - 0.0f * xwidth, ((_numDivisions - (float(bx) + 1.0f))/_numDivisions) * ywidth);
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();
	glPopMatrix();
}

void Plane::drawRepeated(CGFappearance* appearance, float xrepeat, float yrepeat)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	appearance->apply();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
				glTexCoord2f(float(bx)/_numDivisions * xrepeat, 0.0f * yrepeat);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glTexCoord2f((float(bx) + 1.0f)/_numDivisions * xrepeat, float(bz)/_numDivisions * yrepeat);
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2f(float(bx)/_numDivisions * xrepeat, (float(bz) + 1.0f)/_numDivisions * yrepeat);
					glVertex3f(bx, 0, bz + 1);
				}
				glTexCoord2f((float(bx) + 1.0f)/_numDivisions * xrepeat, 1.0f * yrepeat);
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();
	glPopMatrix();
}
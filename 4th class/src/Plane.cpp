#include "Plane.h"
#include <GL/glu.h>


Plane::Plane(void)
{
	_numDivisions = 1;

	// Coefficients for slides material
	float ambSlides[3] = {0.2, 0.2, 0.2};
	float difSlides[3] = {0.8, 0.8, 0.8};
	float specSlides[3] = {0.3, 0.3, 0.3};
	float shininessSlides = 40.0f;
	
	slidesAppearance = new CGFappearance(ambSlides, difSlides, specSlides, shininessSlides);
	slidesAppearance->setTexture("slides.png");
}

Plane::Plane(int n)
{
	_numDivisions = n;
	
	// Coefficients for slides material
	float ambSlides[3] = {0.2, 0.2, 0.2};
	float difSlides[3] = {0.8, 0.8, 0.8};
	float specSlides[3] = {0.3, 0.3, 0.3};
	float shininessSlides = 40.0f;
	
	slidesAppearance = new CGFappearance(ambSlides, difSlides, specSlides, shininessSlides);
	slidesAppearance->setTexture("slides.png");
}


Plane::~Plane(void)
{
}

void Plane::draw()
{
	glEnable(GL_TEXTURE_2D);
	slidesAppearance->apply();

	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
				if(bx == 0)
					glTexCoord2f(0.0f, 0.0f);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					if(bx == _numDivisions - 1)
						glTexCoord2f(1.0f, 0.0f);
					glVertex3f(bx + 1, 0, bz);
					if(bz == _numDivisions - 1)
						glTexCoord2f(0.0f, 1.0f);
					glVertex3f(bx, 0, bz + 1);
				}
				if(bx == _numDivisions - 1)
					glTexCoord2f(1.0f, 1.0f);
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}

#include <math.h>
#include "Face.h"

#define M_PI 3.1415926535897932384626433832795

float THIRD = 1/3;
float DELTALPHA = 90/4;

Face::Face(int stacks) {
	this->stacks = stacks;

	//bottom
	for(unsigned int i = 0; i < 4; i++) {
		vertex[0][i].x = -0.5f + i * THIRD;
		vertex[0][i].y = 0.0f;
		vertex[0][i].z = 0.5f;
	}

	//top
	for(unsigned int i = 0; i < 4; i++) {
		vertex[stacks - 1][i].x = 0.25 * cos(-135.0f + DELTALPHA*i);
		vertex[stacks - 1][i].y = 1;
		vertex[stacks - 1][i].z = 0.25 * sin(-135.0f + DELTALPHA*i);
	}

	//interpolation
	for(unsigned int i = 1; i < stacks - 2; i++) {
		for(unsigned int j = 0; j < 4; j++) {
			vertex[i][j].x = vertex[0][j].x * (stacks - i)/stacks + vertex[stacks - 1][j].x * i/stacks;
			vertex[i][j].y = i / stacks;
			vertex[i][j].z = vertex[0][j].z * (stacks - i)/stacks + vertex[stacks - 1][j].z * i/stacks;
		}	
	}
};

void Face::draw() {
	glBegin(GL_POLYGON);
		for(unsigned int i = 0; i < stacks - 2; i++) {
			for(unsigned int j = 0; j < 3; j++) {
				glVertex3f(vertex[i][j].x, vertex[i][j].y, vertex[i][j].z);
				glVertex3f(vertex[i][j + 1].x, vertex[i][j + 1].y, vertex[i][j + 1].z);
				glVertex3f(vertex[i + 1][j + 1].x, vertex[i + 1][j + 1].y, vertex[i + 1][j + 1].z);
				glVertex3f(vertex[i + 1][j].x, vertex[i + 1][j].y, vertex[i + 1][j].z);
			}
		}
	glEnd();
};
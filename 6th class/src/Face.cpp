#include <iostream>
#include <math.h>
#include "Face.h"

#define M_PI 3.1415926535897932384626433832795

float THIRD = 1.0f/3;
float DELTALPHA = 90.0f/3;

Face::Face() {
	stacks = 6;

	//bottom
	for(unsigned int i = 0; i < 4; i++) {
		vertex[0][i].x = -0.5f + (float)i * THIRD;
		vertex[0][i].y = 0.0f;
		vertex[0][i].z = 0.5f;
		normal[0][i].x = 0.0f;
		normal[0][i].y = 0.0f;
		normal[0][i].z = 1.0f;
	}

	//top
	for(unsigned int i = 0; i < 4; i++) {
		vertex[stacks - 1][i].x = 0.25f * cos(((-135.0f + DELTALPHA*i)*M_PI) / 180.0f);
		vertex[stacks - 1][i].y = 1.0f;
		vertex[stacks - 1][i].z = -0.25f * sin(((-135.0f + DELTALPHA*i)*M_PI) / 180.0f);
		normal[0][i].x = 0.25f * cos(((-135.0f + DELTALPHA*i)*M_PI) / 180.0f);
		normal[0][i].y = 0.0f;
		normal[0][i].z = -0.25f * sin(((-135.0f + DELTALPHA*i)*M_PI) / 180.0f);
		float distance = sqrt(vertex[stacks - 1][i].x * vertex[stacks - 1][i].x + vertex[stacks - 1][i].z * vertex[stacks - 1][i].z);
		std::cout << distance << std::endl;
	}

	//interpolation
	for(unsigned int i = 1; i < 5; i++) {
		for(unsigned int j = 0; j < 4; j++) {
			vertex[i][j].x = vertex[0][j].x * (float)(stacks - i)/stacks + vertex[stacks - 1][j].x * (float)i/stacks;
			vertex[i][j].y = (float)i / stacks;
			vertex[i][j].z = vertex[0][j].z * (float)(stacks - i)/stacks + vertex[stacks - 1][j].z * (float)i/stacks;
			normal[i][j].x = vertex[0][j].x * (float)(stacks - i)/stacks + vertex[stacks - 1][j].x * (float)i/stacks;
			normal[i][j].y = 0.0f;
			normal[i][j].z = vertex[0][j].z * (float)(stacks - i)/stacks + vertex[stacks - 1][j].z * (float)i/stacks;
		}	
	}
	/*
	for(unsigned int i = 0; i < 6; i++) {
		for(unsigned int j = 0; j < 4; j++) {
			std::cout << i << " " << j << " " << vertex[i][j].x << " " << vertex[i][j].y << " " << vertex[i][j].z << std::endl;
		}
	}*/
}

void Face::draw() {
	glBegin(GL_QUADS);
		for(unsigned int i = 0; i < stacks - 1; i++) {
			for(unsigned int j = 0; j < 3; j++) {
				glNormal3f(normal[i][j].x, normal[i][j].y, normal[i][j].z);
				glVertex3f(vertex[i][j].x, vertex[i][j].y, vertex[i][j].z);
				glNormal3f(normal[i][j + 1].x, normal[i][j + 1].y, normal[i][j + 1].z);
				glVertex3f(vertex[i][j + 1].x, vertex[i][j + 1].y, vertex[i][j + 1].z);
				glNormal3f(normal[i + 1][j + 1].x, normal[i + 1][j + 1].y, normal[i + 1][j + 1].z);
				glVertex3f(vertex[i + 1][j + 1].x, vertex[i + 1][j + 1].y, vertex[i + 1][j + 1].z);
				glNormal3f(normal[i + 1][j].x, normal[i + 1][j].y, normal[i + 1][j].z);
				glVertex3f(vertex[i + 1][j].x, vertex[i + 1][j].y, vertex[i + 1][j].z);
			}
		}
	glEnd();
}

void Face::drawTextured(CGFappearance * appearance, char direction) {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	appearance->apply();

	switch(direction) {
		case 'f': //front
			glBegin(GL_QUADS);
				for(unsigned int i = 0; i < stacks - 1; i++) {
					for(unsigned int j = 0; j < 3; j++) {
						glNormal3f(normal[i][j].x, normal[i][j].y, normal[i][j].z);
						glTexCoord2f(j / 3.0f + (0.5f - j / 3.0f) * (float)i / stacks, (i * 0.5f) / stacks);
						glVertex3f(vertex[i][j].x, vertex[i][j].y, vertex[i][j].z);
						glNormal3f(normal[i][j + 1].x, normal[i][j + 1].y, normal[i][j + 1].z);
						glTexCoord2f((j + 1) / 3.0f + (0.5f - (j + 1) / 3.0f) * (float)i / stacks, (i * 0.5f) / stacks);
						glVertex3f(vertex[i][j + 1].x, vertex[i][j + 1].y, vertex[i][j + 1].z);
						glNormal3f(normal[i + 1][j + 1].x, normal[i + 1][j + 1].y, normal[i + 1][j + 1].z);
						glTexCoord2f((j + 1) / 3.0f + (0.5f - (j + 1) / 3.0f) * (float)(i + 1) / stacks, ((i + 1) * 0.5f) / stacks);
						glVertex3f(vertex[i + 1][j + 1].x, vertex[i + 1][j + 1].y, vertex[i + 1][j + 1].z);
						glNormal3f(normal[i + 1][j].x, normal[i + 1][j].y, normal[i + 1][j].z);
						glTexCoord2f(j / 3.0f + (0.5f - j / 3.0f) * (float)(i + 1) / stacks, ((i + 1) * 0.5f) / stacks);
						glVertex3f(vertex[i + 1][j].x, vertex[i + 1][j].y, vertex[i + 1][j].z);
					}
				}
			glEnd();
			break;
		case 'l': //left
			glBegin(GL_QUADS);
				for(unsigned int i = 0; i < stacks - 1; i++) {
					for(unsigned int j = 0; j < 3; j++) {
						glNormal3f(normal[i][j].x, normal[i][j].y, normal[i][j].z);
						glTexCoord2f(1.0f - (0.5f * (float)i / stacks), j / 3.0f + (0.5f - j / 3.0f) * (float)i / stacks);
						glVertex3f(vertex[i][j].x, vertex[i][j].y, vertex[i][j].z);
						glNormal3f(normal[i][j + 1].x, normal[i][j + 1].y, normal[i][j + 1].z);
						glTexCoord2f(1.0f - (0.5f * (float)i / stacks), (j + 1) / 3.0f + (0.5f - (j + 1) / 3.0f) * (float)i / stacks);
						glVertex3f(vertex[i][j + 1].x, vertex[i][j + 1].y, vertex[i][j + 1].z);
						glNormal3f(normal[i + 1][j + 1].x, normal[i + 1][j + 1].y, normal[i + 1][j + 1].z);
						glTexCoord2f(1.0f - (0.5f * (float)(i + 1) / stacks), (j + 1) / 3.0f + (0.5f - (j + 1) / 3.0f) * (float)(i + 1) / stacks);
						glVertex3f(vertex[i + 1][j + 1].x, vertex[i + 1][j + 1].y, vertex[i + 1][j + 1].z);
						glNormal3f(normal[i + 1][j].x, normal[i + 1][j].y, normal[i + 1][j].z);
						glTexCoord2f(1.0f - (0.5f * (float)(i + 1) / stacks), j / 3.0f + (0.5f - j / 3.0f) * (float)(i + 1) / stacks);
						glVertex3f(vertex[i + 1][j].x, vertex[i + 1][j].y, vertex[i + 1][j].z);
					}
				}
			glEnd();
			break;
		case 'r': //right
			glBegin(GL_QUADS);
				for(unsigned int i = 0; i < stacks - 1; i++) {
					for(unsigned int j = 0; j < 3; j++) {
						glNormal3f(normal[i][j].x, normal[i][j].y, normal[i][j].z);
						glTexCoord2f((float)i / stacks * 0.5f, 1 - j / 3.0f + (0.5f - (1 - j / 3.0f)) * (float)i / stacks);
						glVertex3f(vertex[i][j].x, vertex[i][j].y, vertex[i][j].z);
						glNormal3f(normal[i][j + 1].x, normal[i][j + 1].y, normal[i][j + 1].z);
						glTexCoord2f((float)i / stacks * 0.5f, 1 - (j + 1) / 3.0f + (0.5f - (1 - (j + 1) / 3.0f)) * (float)i / stacks);
						glVertex3f(vertex[i][j + 1].x, vertex[i][j + 1].y, vertex[i][j + 1].z);
						glNormal3f(normal[i + 1][j + 1].x, normal[i + 1][j + 1].y, normal[i + 1][j + 1].z);
						glTexCoord2f((float)(i + 1) / stacks * 0.5f, 1 - (j + 1) / 3.0f + (0.5f - (1 - (j + 1) / 3.0f)) * (float)(i + 1) / stacks);
						glVertex3f(vertex[i + 1][j + 1].x, vertex[i + 1][j + 1].y, vertex[i + 1][j + 1].z);
						glNormal3f(normal[i + 1][j].x, normal[i + 1][j].y, normal[i + 1][j].z);
						glTexCoord2f((float)(i + 1) / stacks * 0.5f, 1 - j / 3.0f + (0.5f - (1 - j / 3.0f)) * (float)(i + 1) / stacks);
						glVertex3f(vertex[i + 1][j].x, vertex[i + 1][j].y, vertex[i + 1][j].z);
					}
				}
			glEnd();
			break;
		case 'b': //back
			glBegin(GL_QUADS);
				for(unsigned int i = 0; i < stacks - 1; i++) {
					for(unsigned int j = 0; j < 3; j++) {
						glNormal3f(normal[i][j].x, normal[i][j].y, normal[i][j].z);
						glTexCoord2f(1 - j / 3.0f + (0.5f - (1 - j / 3.0f)) * (float)i / stacks, 1.0f - (i * 0.5f) / stacks);
						glVertex3f(vertex[i][j].x, vertex[i][j].y, vertex[i][j].z);
						glNormal3f(normal[i][j + 1].x, normal[i][j + 1].y, normal[i][j + 1].z);
						glTexCoord2f(1 - (j + 1) / 3.0f + (0.5f - (1 - (j + 1) / 3.0f)) * (float)i / stacks, 1.0f - (i * 0.5f) / stacks);
						glVertex3f(vertex[i][j + 1].x, vertex[i][j + 1].y, vertex[i][j + 1].z);
						glNormal3f(normal[i + 1][j + 1].x, normal[i + 1][j + 1].y, normal[i + 1][j + 1].z);
						glTexCoord2f(1 - (j + 1) / 3.0f + (0.5f - (1 - (j + 1) / 3.0f)) * (float)(i + 1) / stacks, 1.0f - ((i + 1) * 0.5f) / stacks);
						glVertex3f(vertex[i + 1][j + 1].x, vertex[i + 1][j + 1].y, vertex[i + 1][j + 1].z);
						glNormal3f(normal[i + 1][j].x, normal[i + 1][j].y, normal[i + 1][j].z);
						glTexCoord2f(1 - j / 3.0f + (0.5f - (1 - j / 3.0f)) * (float)(i + 1) / stacks, 1.0f - ((i + 1) * 0.5f) / stacks);
						glVertex3f(vertex[i + 1][j].x, vertex[i + 1][j].y, vertex[i + 1][j].z);
					}
				}
			glEnd();
			break;
	};

	glPopMatrix();
}
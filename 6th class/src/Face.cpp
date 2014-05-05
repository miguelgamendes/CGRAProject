#include <math.h>
#include "Face.h"

#define M_PI 3.1415926535897932384626433832795

float SIXTH = 1/6;

Face::Face(int stacks) {
	bot[0].x = -0.5;
	bot[1].x = -SIXTH;
	bot[2].x = SIXTH;
	bot[3].x = 0.5;

	for(int i = 0; i < 4; i++) {
		bot[i].y = 0;
		bot[i].z = 0.5;
	}

	int delta = 2*M_PI/3;
	for(int i = 0; i < 4; i++) {
		top[i].x = cos(M_PI/4 + i*delta);
		top[i].y = 1;
		top[i].z = sin(M_PI/4 + i*delta);
	}
};

void Face::draw() {
	vertex tmp_bot1, tmp_bot2;
};
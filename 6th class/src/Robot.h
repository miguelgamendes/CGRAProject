#ifndef ROBOT_H
#define ROBOT_H

#include "CGFobject.h"
#include "Face.h"

class Robot: public CGFobject {
private:
	int stacks;

public:
	Face face;
	Robot();
	void draw();
};

#endif
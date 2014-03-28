#ifndef CHAIR_H
#define CHAIR_H

#include "CGFobject.h"
#include "UnitCube.h"

class Chair : public CGFobject
{
private:
	UnitCube myCube;

public:
	Chair(float r, float t);
	Chair();
	void draw();
	float angle;
	float trans;
};

#endif
#ifndef TABLE_H
#define TABLE_H

#include "CGFobject.h"
#include "UnitCube.h"
#include "CGFappearance.h"

class Table : public CGFobject{
private:
	UnitCube myCube;
public:
	void draw();
	Table(float r, float t);
	Table();
	float angle;
	float trans;
	CGFappearance* tableAppearance;
};

#endif
#ifndef UNITCUBE_H
#define UNITCUBE_H

#include "CGFobject.h"
#include "CGFappearance.h"

class UnitCube: public CGFobject{
public:
	void draw();
	void draw(CGFappearance* appearance);
	void drawRectangle();
};

#endif
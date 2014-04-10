#pragma once

#include "CGF/CGFobject.h"
#include "CGFAppearance.h"

class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw();
	void draw(CGFappearance* appearance); 
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
};


#ifndef FLOOR_H
#define FLOOR_H

#include "CGFobject.h"
#include "UnitCube.h"

class Floor : public CGFobject{
private:
	UnitCube myCube;
public:
	void draw();

};

#endif
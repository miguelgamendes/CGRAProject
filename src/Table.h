#ifndef TABLE_H
#define TABLE_H

#include "CGFobject.h"
#include "UnitCube.h"

class Table : public CGFobject{
private:
	UnitCube myCube;
public:
	void draw();
};

#endif
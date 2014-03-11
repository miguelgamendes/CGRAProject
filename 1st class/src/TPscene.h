#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
#include "ExampleObject.h"
#include "UnitCube.h"
#include "Table.h"
#include "Floor.h"

class TPscene : public CGFscene{
private:
	ExampleObject myObject;
	Table myTable;
	Floor myFloor;
public:
	void init();
	void display();
};

#endif
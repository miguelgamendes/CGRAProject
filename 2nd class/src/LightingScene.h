#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "Table.h"
#include "Plane.h"
#include "Chair.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();

	CGFlight* light0;
	CGFlight* light1;

	Table* table;
	Chair* chair;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;

	~LightingScene();
};

#endif
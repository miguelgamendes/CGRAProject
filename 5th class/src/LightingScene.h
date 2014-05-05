#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "Table.h"
#include "Plane.h"
#include "Chair.h"
#include "myCylinder.h"
#include "Clock.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	myCylinder* myCyl;
	myCylinder* myCyl2;
	Clock* myClock;

	Table* table;
	Chair* chair;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;

	~LightingScene();
};

#endif
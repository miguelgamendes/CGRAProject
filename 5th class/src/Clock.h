#ifndef CLOCK_H
#define CLOCK_H

#include "myCylinder.h"
#include "CGFappearance.h"

class Clock {
public:
	Clock();
	void draw();
private:
	CGFappearance* appearance;
	myCylinder* myCyl;
	ClockHand* h;
	ClockHand* m;
	ClockHand* s;
};

#endif
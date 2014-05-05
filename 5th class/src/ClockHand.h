#ifndef CLOCKHAND_H
#define CLOCKHAND_H

#include "CGFobject.h"

class ClockHand : public CGFObject{
	float angle;
public:
	void setAngle(float a);
	void draw();
};

#endif
#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"

class myCylinder : public CGFobject {
private:
	int slices, stacks;
	double angle;
public:
	myCylinder(int slices, int stacks/*, bool smooth*/);
	void draw();
};



#endif
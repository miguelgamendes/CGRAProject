#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"

class myCylinder : public CGFobject {
private:
	int slices, stacks;
	double cellSize;
	double delta;
	bool smooth;
public:
	myCylinder(int slices, int stacks, bool smooth);
	void draw();
};



#endif

#ifndef FACE_H
#define FACE_H

#include "CGFObject.h"

class Face: public CGFobject {
private:
	int stacks;
	struct Vector3f{ float x; float y; float z;};
	Vector3f vertex[stacks][4];
public:
	Face(int stacks);
	void draw();
};
#endif
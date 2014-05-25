#ifndef FACE_H
#define FACE_H

#include "CGFObject.h"
#include "CGFAppearance.h"

class Face: public CGFobject {
private:
	int stacks;
	struct Vector3f{ float x; float y; float z;};
	Vector3f vertex[6][4];
	Vector3f normal[6][4];
public:
	Face();
	void draw();
	void drawTextured(CGFappearance * appearance, char direction);
};

#endif
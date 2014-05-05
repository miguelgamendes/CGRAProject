#ifndef FACE_H
#define FACE_H

class Face: public CGFobject {
private:
	int stacks;
	struct vertex{ float x; float y; float z;};
	vertex bot[4];
	vertex top[4];
public:
	Face(int stacks);
	void draw();
}
#endif
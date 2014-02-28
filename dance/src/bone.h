// class declaration for human body bone

#ifndef BONE_H
#define BONE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Bone {

public:

	float angleX, angleY, angleZ;

	GLuint DL;

	void showBone(float radius, float height); // displays bone of human figure

	void rotateBoneRight(); // rotates bone of human figure to right

	void rotateBoneLeft(); // rotates bone of human figure to left

	void rotateBoneFront(); // rotates bone of human figure to front

	void rotateBoneBack(); // rotates bone of human figure to back
	
	void rotateBoneClockWise(); // rotates Bone of human figure Clock Wise

	void rotateBoneAntiClockWise(); // rotates Bone of human figure Anti-Clock Wise

};

#endif
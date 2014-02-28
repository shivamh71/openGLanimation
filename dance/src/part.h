// class declaration for human body part

#ifndef PART_H
#define PART_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Part {

public:

	float angleX, angleY, angleZ;

	GLuint DL;

	void showPart(float up, float down, float height); // displays part of human figure

	void rotatePartRight(); // rotates part of human figure to right

	void rotatePartLeft(); // rotates part of human figure to left

	void rotatePartFront(); // rotates part of human figure to front

	void rotatePartBack(); // rotates part of human figure to back
	
	void rotatePartClockWise(); // rotates Part of human figure Clock Wise

	void rotatePartAntiClockWise(); // rotates Part of human figure Anti-Clock Wise

};

#endif
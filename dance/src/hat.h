// class declaration for human Hat

#ifndef Hat_H
#define Hat_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Hat {

public:

	float angleX, angleY, angleZ;

	GLuint DL1,DL2, texture;

	void showHat(float discr,float up, float down, float height); // displays Hat of human figure

	void rotateHatRight(); // rotates Hat of human figure to right

	void rotateHatLeft(); // rotates Hat of human figure to left

	void rotateHatFront(); // rotates Hat of human figure to front

	void rotateHatBack(); // rotates Hat of human figure to back

	void rotateHatClockWise(); // rotates Hat of human figure clockwise

	void rotateHatAntiClockWise(); // rotates Hat of human figure anti-clockwise

};

#endif

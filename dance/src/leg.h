// class declaration for human body Leg

#ifndef LEG_H
#define LEG_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Leg {

public:

	float angleX, angleY, angleZ;

	GLuint DL, texture;

	void showLeg(float radius, float height); // displays Leg of human figure

	void rotateLegRight(); // rotates Leg of human figure to right

	void rotateLegLeft(); // rotates Leg of human figure to left

	void rotateLegFront(); // rotates Leg of human figure to front

	void rotateLegBack(); // rotates Leg of human figure to back
	
	void rotateLegClockWise(); // rotates Leg of human figure Clock Wise

	void rotateLegAntiClockWise(); // rotates Leg of human figure Anti-Clock Wise

};

#endif
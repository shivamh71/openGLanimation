// class declaration for human body Feet

#ifndef FEET_H
#define FEET_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Feet {

public:

	float angleX, angleY, angleZ;

	GLuint DL, texture;

	void showFeet(float radius, float height); // displays Feet of human figure

	void rotateFeetRight(); // rotates Feet of human figure to right

	void rotateFeetLeft(); // rotates Feet of human figure to left

	void rotateFeetFront(); // rotates Feet of human figure to front

	void rotateFeetBack(); // rotates Feet of human figure to back
	
	void rotateFeetClockWise(); // rotates Feet of human figure Clock Wise

	void rotateFeetAntiClockWise(); // rotates Feet of human figure Anti-Clock Wise

};

#endif
// class declaration for human body Arm

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#ifndef ARM_H
#define ARM_H

class Arm {

public:

	float angleX, angleY, angleZ;

	GLuint DL, texture;

	void showArm(float radius, float height); // displays Arm of human figure

	void rotateArmRight(); // rotates Arm of human figure to right

	void rotateArmLeft(); // rotates Arm of human figure to left

	void rotateArmFront(); // rotates Arm of human figure to front

	void rotateArmBack(); // rotates Arm of human figure to back
	
	void rotateArmClockWise(); // rotates Arm of human figure Clock Wise

	void rotateArmAntiClockWise(); // rotates Arm of human figure Anti-Clock Wise

};

#endif
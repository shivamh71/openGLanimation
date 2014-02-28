// class declaration for human body Thigh

#ifndef THIGH_H
#define THIGH_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Thigh {

public:

	float angleX, angleY, angleZ;

	GLuint DL, texture;

	void showThigh(float radius, float height); // displays Thigh of human figure

	void rotateThighRight(); // rotates Thigh of human figure to right

	void rotateThighLeft(); // rotates Thigh of human figure to left

	void rotateThighFront(); // rotates Thigh of human figure to front

	void rotateThighBack(); // rotates Thigh of human figure to back
	
	void rotateThighClockWise(); // rotates Thigh of human figure Clock Wise

	void rotateThighAntiClockWise(); // rotates Thigh of human figure Anti-Clock Wise

};

#endif
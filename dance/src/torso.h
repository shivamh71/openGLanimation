// class declaration for human body Torso

#ifndef TORSO_H
#define TORSO_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Torso {

public:

	float angleX, angleY, angleZ;

	GLuint DL, texture;

	void showTorso(float up, float down, float height); // displays Torso of human figure

	void rotateTorsoRight(); // rotates Torso of human figure to right

	void rotateTorsoLeft(); // rotates Torso of human figure to left

	void rotateTorsoFront(); // rotates Torso of human figure to front

	void rotateTorsoBack(); // rotates Torso of human figure to back
	
	void rotateTorsoClockWise(); // rotates Torso of human figure Clock Wise

	void rotateTorsoAntiClockWise(); // rotates Torso of human figure Anti-Clock Wise

};

#endif
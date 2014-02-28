// class declaration for human body Hand

#ifndef HAND_H
#define HAND_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Hand {

public:

	float angleX, angleY, angleZ;

	GLuint DL, texture;

	void showHand(float radius, float height); // displays Hand of human figure

	void rotateHandRight(); // rotates Hand of human figure to right

	void rotateHandLeft(); // rotates Hand of human figure to left

	void rotateHandFront(); // rotates Hand of human figure to front

	void rotateHandBack(); // rotates Hand of human figure to back
	
	void rotateHandClockWise(); // rotates Hand of human figure Clock Wise

	void rotateHandAntiClockWise(); // rotates Hand of human figure Anti-Clock Wise

};

#endif
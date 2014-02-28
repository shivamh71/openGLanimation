// class declaration for human body Palm

#ifndef PALM_H
#define PALM_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Palm {

public:

	float angleX, angleY, angleZ;

	GLuint DL, texture;

	void showPalm(float radius, float height); // displays Palm of human figure

	void rotatePalmRight(); // rotates Palm of human figure to right

	void rotatePalmLeft(); // rotates Palm of human figure to left

	void rotatePalmFront(); // rotates Palm of human figure to front

	void rotatePalmBack(); // rotates Palm of human figure to back
	
	void rotatePalmClockWise(); // rotates Palm of human figure Clock Wise

	void rotatePalmAntiClockWise(); // rotates Palm of human figure Anti-Clock Wise

};

#endif
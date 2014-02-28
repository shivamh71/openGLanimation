// class declaration for human head

#ifndef HEAD_H
#define HEAD_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Head {

public:

	float angleX, angleY, angleZ;

	GLuint DL, texture;

	void showHead(float up, float down, float height); // displays head of human figure

	void rotateHeadRight(); // rotates head of human figure to right

	void rotateHeadLeft(); // rotates head of human figure to left

	void rotateHeadFront(); // rotates head of human figure to front

	void rotateHeadBack(); // rotates head of human figure to back

	void rotateHeadClockWise(); // rotates Head of human figure clockwise

	void rotateHeadAntiClockWise(); // rotates Head of human figure anti-clockwise

};

#endif
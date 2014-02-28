// class definition for human body Palm

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "palm.h"
#include "draw.h"

void Palm::showPalm(float radius, float height) { // displays Palm of human figure
	angleX = 0;
	angleY = 0;
	angleZ = 0;
	DL = glGenLists(4);
	glNewList(DL,GL_COMPILE);
	GLUquadric *quadric = gluNewQuadric();
	gluQuadricTexture(quadric,1);
	glNewList(DL,GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricOrientation(quadric, GLU_INSIDE);
	solid_cylinder(quadric,radius,radius, height,20,20);
	gluDeleteQuadric(quadric);
	glDisable(GL_TEXTURE_2D);
	glEndList();	
}

void Palm::rotatePalmRight() { // rotates Palm of human figure to right
	angleY++;
}

void Palm::rotatePalmLeft() { // rotates Palm of human figure to left
	angleY--;
}

void Palm::rotatePalmFront() { // rotates Palm of human figure to front
	angleX++;
}

void Palm::rotatePalmBack() { // rotates Palm of human figure to back
	angleX--;
}

void Palm::rotatePalmClockWise() { // rotates Palm of human figure Clock Wise
	angleZ++;
}

void Palm::rotatePalmAntiClockWise() { // rotates Palm of human figure Anti-Clock Wise
	angleZ--;
}
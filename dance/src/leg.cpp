// class definition for human body Leg

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "leg.h"
#include "draw.h"

void Leg::showLeg(float radius, float height) { // displays Leg of human figure
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

void Leg::rotateLegRight() { // rotates Leg of human figure to right
	angleY++;
}

void Leg::rotateLegLeft() { // rotates Leg of human figure to left
	angleY--;
}

void Leg::rotateLegFront() { // rotates Leg of human figure to front
	angleX++;
}

void Leg::rotateLegBack() { // rotates Leg of human figure to back
	angleX--;
}

void Leg::rotateLegClockWise() { // rotates Leg of human figure Clock Wise
	angleZ++;
}

void Leg::rotateLegAntiClockWise() { // rotates Leg of human figure Anti-Clock Wise
	angleZ--;
}
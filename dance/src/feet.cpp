// class definition for human body Feet

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "feet.h"
#include "draw.h"

void Feet::showFeet(float radius, float height) { // displays Feet of human figure
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

void Feet::rotateFeetRight() { // rotates Feet of human figure to right
	angleY++;
}

void Feet::rotateFeetLeft() { // rotates Feet of human figure to left
	angleY--;
}

void Feet::rotateFeetFront() { // rotates Feet of human figure to front
	angleX++;
}

void Feet::rotateFeetBack() { // rotates Feet of human figure to back
	angleX--;
}

void Feet::rotateFeetClockWise() { // rotates Feet of human figure Clock Wise
	angleZ++;
}

void Feet::rotateFeetAntiClockWise() { // rotates Feet of human figure Anti-Clock Wise
	angleZ--;
}
// class definition for human body part

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "part.h"
#include "draw.h"

void Part::showPart(float up, float down, float height) { // displays Part of human figure
	angleX = 0;
	angleY = 0;
	angleZ = 0;
	DL = glGenLists(1);
	glNewList(DL,GL_COMPILE);
	GLUquadric *quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricOrientation(quadric, GLU_INSIDE);
	glTranslatef(0.0f,0.0f,0.0f);
	solid_cylinder(quadric, up, down, height,22,22);
	gluDeleteQuadric(quadric);
	glEndList(); 
}

void Part::rotatePartRight() { // rotates Part of human figure to right
	angleY++;
}

void Part::rotatePartLeft() { // rotates Part of human figure to left
	angleY--;
}

void Part::rotatePartFront() { // rotates Part of human figure to front
	angleX++;
}

void Part::rotatePartBack() { // rotates Part of human figure to back
	angleX--;
}

void Part::rotatePartClockWise() { // rotates Part of human figure Clock Wise
	angleZ++;
}

void Part::rotatePartAntiClockWise() { // rotates Part of human figure Anti-Clock Wise
	angleZ--;
}
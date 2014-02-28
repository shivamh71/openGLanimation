// class definition for human body Head

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "head.h"
#include "draw.h"

void Head::showHead(float up, float down, float height) { // displays Head of human figure
	angleX = 0;
	angleY = 0;
	angleZ = 0;
	DL = glGenLists(1);
	GLUquadric *quadric = gluNewQuadric();
	gluQuadricTexture(quadric,1);
	glNewList(DL,GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricOrientation(quadric, GLU_OUTSIDE);
	glTranslatef(0.0f,0.0f,0.0f);
	solid_cylinder(quadric, up, down, height,22,22);
	gluDeleteQuadric(quadric);
	glDisable(GL_TEXTURE_2D);
	glEndList(); 
}

void Head::rotateHeadRight() { // rotates Head of human figure to right
	angleY++;
}

void Head::rotateHeadLeft() { // rotates Head of human figure to left
	angleY--;
}

void Head::rotateHeadFront() { // rotates Head of human figure to front
	angleX++;
}

void Head::rotateHeadBack() { // rotates Head of human figure to back
	angleX--;
}

void Head::rotateHeadClockWise() { // rotates Head of human figure Clock Wise
	angleZ++;
}

void Head::rotateHeadAntiClockWise() { // rotates Head of human figure Anti-Clock Wise
	angleZ--;
}
// class definition for human body Thigh

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "thigh.h"
#include "draw.h"

void Thigh::showThigh(float radius, float height) { // displays Thigh of human figure
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

void Thigh::rotateThighRight() { // rotates Thigh of human figure to right
	angleY++;
}

void Thigh::rotateThighLeft() { // rotates Thigh of human figure to left
	angleY--;
}

void Thigh::rotateThighFront() { // rotates Thigh of human figure to front
	angleX++;
}

void Thigh::rotateThighBack() { // rotates Thigh of human figure to back
	angleX--;
}

void Thigh::rotateThighClockWise() { // rotates Thigh of human figure Clock Wise
	angleZ++;
}

void Thigh::rotateThighAntiClockWise() { // rotates Thigh of human figure Anti-Clock Wise
	angleZ--;
}
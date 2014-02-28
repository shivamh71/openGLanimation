// class definition for human body Arm

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "arm.h"
#include "draw.h"

void Arm::showArm(float radius, float height) { // displays Arm of human figure
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

void Arm::rotateArmRight() { // rotates Arm of human figure to right
	angleY++;
}

void Arm::rotateArmLeft() { // rotates Arm of human figure to left
	angleY--;
}

void Arm::rotateArmFront() { // rotates Arm of human figure to front
	angleX++;
}

void Arm::rotateArmBack() { // rotates Arm of human figure to back
	angleX--;
}

void Arm::rotateArmClockWise() { // rotates Arm of human figure Clock Wise
	angleZ++;
}

void Arm::rotateArmAntiClockWise() { // rotates Arm of human figure Anti-Clock Wise
	angleZ--;
}
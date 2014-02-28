// class definition for human body joints

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "joint.h"
#include "draw.h"

void Joint::showJoint(float radius) { // displays joint of human figure
	angleX = 0;
	angleY = 0;
	angleZ = 0;
	DL = glGenLists(5);
	glNewList(DL,GL_COMPILE);
	drawsphere(radius,texture);
	glEndList();
}

void Joint::rotateJointRight() { // rotates Joint of human figure to right
	angleY++;
}

void Joint::rotateJointLeft() { // rotates Joint of human figure to left
	angleY--;
}

void Joint::rotateJointFront() { // rotates Joint of human figure to front
	angleX++;
}

void Joint::rotateJointBack() { // rotates Joint of human figure to back
	angleX--;
}

void Joint::rotateJointClockWise() { // rotates Joint of human figure Clock Wise
	angleZ++;
}

void Joint::rotateJointAntiClockWise() { // rotates Joint of human figure Anti-Clock Wise
	angleZ--;
}
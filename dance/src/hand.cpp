// class definition for human body Hand

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "hand.h"
#include "draw.h"

void Hand::showHand(float radius, float height) { // displays Hand of human figure
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

void Hand::rotateHandRight() { // rotates Hand of human figure to right
	angleY++;
}

void Hand::rotateHandLeft() { // rotates Hand of human figure to left
	angleY--;
}

void Hand::rotateHandFront() { // rotates Hand of human figure to front
	angleX++;
}

void Hand::rotateHandBack() { // rotates Hand of human figure to back
	angleX--;
}

void Hand::rotateHandClockWise() { // rotates Hand of human figure Clock Wise
	angleZ++;
}

void Hand::rotateHandAntiClockWise() { // rotates Hand of human figure Anti-Clock Wise
	angleZ--;
}
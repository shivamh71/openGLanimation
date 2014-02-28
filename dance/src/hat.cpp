// class definition for human body Hat

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "hat.h"
#include "draw.h"

void Hat::showHat(float discr,float up, float down, float height) { // displays Hat of human figure
	angleX = 0;
	angleY = 0;
	angleZ = 0;
	DL1 = glGenLists(16);
	GLUquadric *quadric = gluNewQuadric();
	gluQuadricTexture(quadric,1);
	glNewList(DL1,GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricOrientation(quadric, GLU_INSIDE);
	glTranslatef(0.0f,0.0f,0.0f);
	glRotatef(90.,1.0,0.0,0.0);
	gluDisk(quadric, 0.6f, discr, 20, 20);
	
	gluDeleteQuadric(quadric);
	glDisable(GL_TEXTURE_2D);
	glEndList();
	
	DL2 = glGenLists(17);
	GLUquadric *quadric2 = gluNewQuadric();
	gluQuadricTexture(quadric2,2);
	glNewList(DL2,GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	gluQuadricDrawStyle(quadric2, GLU_FILL);
	gluQuadricOrientation(quadric2, GLU_INSIDE);
	
	//glRotatef(90.,1.0,0.0,0.0);
	
	gluCylinder(quadric2, up, down, height,20,20);
	gluDeleteQuadric(quadric2);
	glDisable(GL_TEXTURE_2D);
	glEndList();
}

void Hat::rotateHatRight() { // rotates Hat of human figure to right
	angleY++;
}

void Hat::rotateHatLeft() { // rotates Hat of human figure to left
	angleY--;
}

void Hat::rotateHatFront() { // rotates Hat of human figure to front
	angleX++;
}

void Hat::rotateHatBack() { // rotates Hat of human figure to back
	angleX--;
}

void Hat::rotateHatClockWise() { // rotates Hat of human figure Clock Wise
	angleZ++;
}

void Hat::rotateHatAntiClockWise() { // rotates Hat of human figure Anti-Clock Wise
	angleZ--;
}

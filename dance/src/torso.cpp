// class definition for human body Torso

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "torso.h"
#include "draw.h"

void Torso::showTorso(float up, float down, float height) { // displays Torso of human figure
	angleX = 0;
	angleY = 0;
	angleZ = 0;
	DL = glGenLists(1);
	glNewList(DL,GL_COMPILE);
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

void Torso::rotateTorsoRight() { // rotates Torso of human figure to right
	angleY++;
}

void Torso::rotateTorsoLeft() { // rotates Torso of human figure to left
	angleY--;
}

void Torso::rotateTorsoFront() { // rotates Torso of human figure to front
	angleX++;
}

void Torso::rotateTorsoBack() { // rotates Torso of human figure to back
	angleX--;
}

void Torso::rotateTorsoClockWise() { // rotates Torso of human figure Clock Wise
	angleZ++;
}

void Torso::rotateTorsoAntiClockWise() { // rotates Torso of human figure Anti-Clock Wise
	angleZ--;
}
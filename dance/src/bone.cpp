// class definition for human body bone

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "bone.h"
#include "draw.h"

void Bone::showBone(float radius, float height) { // displays bone of human figure
	angleX = 0;
	angleY = 0;
	angleZ = 0;
	DL = glGenLists(4);
	glNewList(DL,GL_COMPILE);
	GLUquadric *quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricOrientation(quadric, GLU_INSIDE);
	solid_cylinder(quadric,radius,radius, height,20,20);
	gluDeleteQuadric(quadric);
	glEndList();	
}


void Bone::rotateBoneRight() { // rotates Bone of human figure to right
	angleY++;
}

void Bone::rotateBoneLeft() { // rotates Bone of human figure to left
	angleY--;
}

void Bone::rotateBoneFront() { // rotates Bone of human figure to front
	angleX++;
}

void Bone::rotateBoneBack() { // rotates Bone of human figure to back
	angleX--;
}

void Bone::rotateBoneClockWise() { // rotates Bone of human figure Clock Wise
	angleZ++;
}

void Bone::rotateBoneAntiClockWise() { // rotates Bone of human figure Anti-Clock Wise
	angleZ--;
}

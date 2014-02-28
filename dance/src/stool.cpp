// class definition for Stool

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "stool.h"
#include "draw.h"

void Stool::createStool() { // creates Stool
	
	GLuint texture = loadBMP_custom("./images/tableTop.bmp");
	GLuint texture1 = loadBMP_custom("./images/tableLeg.bmp");
	DL = glGenLists(1);
	
	// creates top of stool in scene
	glNewList(DL,GL_COMPILE);
	GLUquadric *quadric1 = gluNewQuadric();
	gluQuadricTexture(quadric1,1);
	glNewList(DL,GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	gluQuadricDrawStyle(quadric1, GLU_FILL);
	gluQuadricOrientation(quadric1, GLU_INSIDE);
	solid_cylinder(quadric1,3.0,3.0,0.3,20,20);
	gluDeleteQuadric(quadric1);
	glDisable(GL_TEXTURE_2D);
	glEndList();	
	
	// creates legs of stool in scene
	tleg = glGenLists(4);
	glNewList(tleg,GL_COMPILE);
	GLUquadric *quadric = gluNewQuadric();
	gluQuadricTexture(quadric,1);
	glNewList(tleg,GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glEnable(GL_TEXTURE_2D);
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricOrientation(quadric, GLU_INSIDE);
	solid_cylinder(quadric,0.25,0.25,2.8,20,20);
	gluDeleteQuadric(quadric);
	glDisable(GL_TEXTURE_2D);
	glEndList();	
}


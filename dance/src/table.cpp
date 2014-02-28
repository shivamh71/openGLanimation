// class definition for Table

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "table.h"
#include "draw.h"

void Table::createTable() { // displays table
	
	GLuint texture = loadBMP_custom("./images/tableTop.bmp");
	GLuint texture1 = loadBMP_custom("./images/tableLeg.bmp");

	// creates table top
	DL = glGenLists(1);
	glNewList(DL,GL_COMPILE);
	glBindTexture( GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	
		glTexCoord2d(1.0,1.0); glVertex3f( 4.0f, -1.0f, -3.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(4.0f, -1.3f, -3.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-4.0f, -1.3f, -3.0f);
		glTexCoord2d(0.0,1.0); glVertex3f( -4.0f, -1.0f, -3.0f);
	
		glTexCoord2d(1.0,1.0); glVertex3f( 4.0f, -1.0f, 3.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(4.0f, -1.3f, 3.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-4.0f, -1.3f,3.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -4.0f, -1.0f,3.0f);
		
		glTexCoord2d(1.0,0.0); glVertex3f( 4.0f, -1.0f, -3.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(4.0f, -1.0f, 3.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-4.0f, -1.0f, 3.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -4.0f, -1.0f, -3.0f);
		
		glTexCoord2d(1.0,0.0); glVertex3f( 4.0f, -1.3f, -3.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(4.0f, -1.3f, 3.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-4.0f, -1.3f, 3.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -4.0f, -1.3f, -3.0f);
		
		glTexCoord2d(1.0,0.0); glVertex3f( 4.0f, -1.0f, -3.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(4.0f, -1.3f, -3.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(4.0f, -1.3f, 3.0f);
		glTexCoord2d(1.0,1.0); glVertex3f( 4.0f, -1.0f, 3.0f);
		
		glTexCoord2d(1.0,0.0); glVertex3f(-4.0f, -1.0f, -3.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-4.0f, -1.3f, -3.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-4.0f, -1.3f, 3.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(-4.0f, -1.0f, 3.0f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();
	
	// creates table legs
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


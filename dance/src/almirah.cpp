// class definition for Almirah

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "almirah.h"
#include "draw.h"

void Almirah::createAlmirah() { // displays Almirah in the room
	angle=0;	
	GLuint texture = loadBMP_custom("./images/almirah.bmp");
	GLuint texture2 = loadBMP_custom("./images/tableTop.bmp");
	DL = glGenLists(1);
	glNewList(DL,GL_COMPILE);
	glBindTexture( GL_TEXTURE_2D, texture2);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		
		// back
		glNormal3f(0,0,1);
		glTexCoord2d(1.0,0.0); glVertex3f( 10.0f, -10.0f, -10.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(10.0f, 10.0f, -10.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-15.0f, 10.0f, -10.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -15.0f, -10.0f, -10.0f);
	
		// right
		glNormal3f(-1,0,0);
		glTexCoord2d(0.0,1.0); glVertex3f( 10.0f, -10.0f, 10.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(10.0f, 10.0f, 10.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(10.0f, 10.0f, -10.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(10.0f, -10.0f, -10.0f);

		// bottom
		glNormal3f(0,1,0);
		glTexCoord2d(1.0,1.0); glVertex3f( 10.0f, -10.0f, 10.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-15.0f, -10.0f, 10.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-15.0f, -10.0f, -10.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(10.0f, -10.0f, -10.0f);

		// top
		glNormal3f(0,-1,0);
		glTexCoord2d(1.0,1.0); glVertex3f( 10.0f, 10.0f, 10.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-15.0f, 10.0f, 10.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-15.0f, 10.0f, -10.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(10.0f, 10.0f, -10.0f);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glBindTexture( GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);

		// left
		glNormal3f(-1,0,0);
		glTexCoord2d(0.0,1.0); glVertex3f( -15.0f, -10.0f, 10.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(-15.0f, 10.0f, 10.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(-15.0f, 10.0f, -10.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -15.0f, -10.0f, -10.0f);
			
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();
	
	door = glGenLists(1);
	glNewList(door,GL_COMPILE);
	glBindTexture( GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	
		glColor3f(1.0,1.0,1.0);

		// front
		glNormal3f(0,0,1);
		glTexCoord2d(1.0,0.0); glVertex3f( -15.0f, -10.0f, 10.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(-15.0f, 10.0f, 10.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(10.0f, 10.0f, 10.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(10.0f, -10.0f, 10.0f);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();
}


void Almirah::openDoor() { // opens almirah door
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(-angle*0.1,-3.0,-2.0);
}


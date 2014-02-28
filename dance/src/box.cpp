// class definition for music box

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "box.h"
#include "draw.h"

void Box::createBox() { // create music box

	angle = 0;

	GLuint texture = loadBMP_custom("./images/musicBoxTop.bmp");
	musicBoxBase = glGenLists(1);
	glNewList(musicBoxBase,GL_COMPILE);
	glBindTexture( GL_TEXTURE_2D, texture );
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);

		// Bottom
		glColor3f(0.57f, 0.19f, 0.21f);     
		glTexCoord2d(1.0,1.0); glVertex3f( 3.0f, -1.0f, 2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-3.0f, -1.0f, 2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-3.0f, -1.0f, -2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f( 3.0f, -1.0f, -2.0f);

		// Front
		glColor3f(0.57f, 0.19f, 0.21f);     
		glTexCoord2d(1.0,1.0); glVertex3f( 3.0f, 1.0f, 2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-3.0f, 1.0f, 2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-3.0f, -1.0f, 2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f( 3.0f, -1.0f, 2.0f);

		// Back
		glColor3f(0.57f, 0.19f, 0.21f);     
		glTexCoord2d(1.0,1.0); glVertex3f( 3.0f, 1.0f, -2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-3.0f, 1.0f, -2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-3.0f, -1.0f, -2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f( 3.0f, -1.0f, -2.0f);

		// Right
		glColor3f(0.57f, 0.19f, 0.21f);    
		glTexCoord2d(1.0,1.0); glVertex3f( 3.0f, 1.0f, 2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f( 3.0f, -1.0f, 2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( 3.0f, -1.0f, -2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f( 3.0f, 1.0f, -2.0f);

		// Left
		glColor3f(0.57f, 0.19f, 0.21f);     
		glTexCoord2d(1.0,1.0); glVertex3f( -3.0f, 1.0f, 2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f( -3.0f, -1.0f, 2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -3.0f, -1.0f, -2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f( -3.0f, 1.0f, -2.0f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();
	// Create the id for the list
	musicBoxTop = glGenLists(2);
	glNewList(musicBoxTop,GL_COMPILE);
	glBindTexture( GL_TEXTURE_2D, texture );
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);

		// Lid
		glColor3f(1.0f, 1.0f, 1.0f);     
		glTexCoord2d(1.0,1.0); glVertex3f( 3.0f, 1.0f, 2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-3.0f, 1.0f, 2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-3.0f, 1.0f, -2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f( 3.0f, 1.0f, -2.0f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();
	
	musicBoxPlatform = glGenLists(3);
	glNewList(musicBoxPlatform,GL_COMPILE);
	glBindTexture( GL_TEXTURE_2D, texture );
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glColor3f(0.87f, 0.19f, 0.21f);     
		glTexCoord2d(1.0,1.0); glVertex3f( 3.0f, 0, 2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-3.0f, 0, 2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-3.0f, 0, -2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f( 3.0f, 0, -2.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();

}

void Box::openBox() { // opens music box
	glPushMatrix();
	glTranslatef(3.0,1.0,-2.0);
	glRotatef(-angle*5.,1.0,0.0,0.0);
	glTranslatef(-3.0,-1.0,2.0);
}

void Box::closeBox() { // closes music box
	
}
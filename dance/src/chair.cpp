// class definition for Chair

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "chair.h"
#include "table.h"
#include "draw.h"

void Chair::createChair() { // creates chair object
	t.createTable();
	GLuint texture = loadBMP_custom("./images/chairBack.bmp");
	upper = glGenLists(1);
	glNewList(upper,GL_COMPILE);
	glBindTexture( GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	
		glNormal3f(0,0,1);
		glTexCoord2d(1.0,0.0); glVertex3f( 4.0f, -1.0f, -3.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(4.0f, 5.0f, -3.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-4.0f, 5.0f, -3.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -4.0f, -1.0f, -3.0f);
		
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();
}

void Chair::showChair() { // displays chair in the scene

		glScalef(0.8,0.8,0.8);
		glCallList(upper);
		glCallList(t.DL);

		glPushMatrix();
			glTranslatef(-2.0,-4.0,2.8);
			glRotatef(-90.,1.0,0.0,0.0);
			glCallList(t.tleg);
		glPopMatrix();	
	
		glPushMatrix();
			glTranslatef(-2.0,-4.0,-2.8);
			glRotatef(-90.,1.0,0.0,0.0);
			glCallList(t.tleg);
		glPopMatrix();	
	
		glPushMatrix();
			glTranslatef(2.0,-4.0,2.8);
			glRotatef(-90.,1.0,0.0,0.0);
			glCallList(t.tleg);
		glPopMatrix();	
	
		glPushMatrix();
			glTranslatef(2.0,-4.0,-2.8);
			glRotatef(-90.,1.0,0.0,0.0);
			glCallList(t.tleg);
		glPopMatrix();	
	glPopMatrix();
}

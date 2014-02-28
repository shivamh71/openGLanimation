// class definition for Room

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "room.h"
#include "draw.h"

void Room::createRoom() { // creates the room
	angle=18;	
	GLuint texture = loadBMP_custom("./images/wall.bmp");
	GLuint texture2 = loadBMP_custom("./images/door.bmp");
	DL = glGenLists(1);
	glNewList(DL,GL_COMPILE);
	glBindTexture( GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		
		glNormal3f(0,0,1);
		glTexCoord2d(1.0,0.0); glVertex3f( 10.0f, -10.0f, -22.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(10.0f, 10.0f, -22.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-15.0f, 10.0f, -22.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -15.0f, -10.0f, -22.0f);
	
		glNormal3f(1,0,0);
		glTexCoord2d(0.0,1.0); glVertex3f( -15.0f, -10.0f, -2.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(-15.0f, 10.0f, -2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(-15.0f, 10.0f, -22.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -15.0f, -10.0f, -22.0f);
		
		glNormal3f(-1,0,0);
		glTexCoord2d(0.0,1.0); glVertex3f( 10.0f, -10.0f, -2.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(10.0f, 10.0f, -2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(10.0f, 10.0f, -22.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(10.0f, -10.0f, -22.0f);
		
		glNormal3f(0,1,0);
		glTexCoord2d(1.0,1.0); glVertex3f( 10.0f, -10.0f, -2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-15.0f, -10.0f, -2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-15.0f, -10.0f, -22.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(10.0f, -10.0f, -22.0f);
		
		glNormal3f(0,-1,0);
		glTexCoord2d(1.0,1.0); glVertex3f( 10.0f, 10.0f, -2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-15.0f, 10.0f, -2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-15.0f, 10.0f, -22.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(10.0f, 10.0f, -22.0f);
		
		glNormal3f(0,0,-1);
		glTexCoord2d(1.0,0.0); glVertex3f( 10.0f, -2.0f, -2.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(10.0f, 10.0f, -2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-15.0f, 10.0f, -2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -15.0f, -2.0f, -2.0f);
		
		glNormal3f(0,0,-1);
		glTexCoord2d(1.0,0.0); glVertex3f( -10.0f, -10.0f, -2.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(-10.0f, -2.0f, -2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-15.0f, -2.0f, -2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f( -15.0f, -10.0f, -2.0f);
		
		glNormal3f(0,0,-1);
		glTexCoord2d(0.0,0.0); glVertex3f( -3.0f, -10.0f, -2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-3.0f, -2.0f, -2.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(10.0f, -2.0f, -2.0f);
		glTexCoord2d(1.0,0.0); glVertex3f(10.0f, -10.0f, -2.0f);
		
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();
	
	// door of the room
	door = glGenLists(1);
	glNewList(door,GL_COMPILE);
	glBindTexture( GL_TEXTURE_2D, texture2);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	
		glColor3f(1.0,1.0,1.0);
		glNormal3f(0,0,-1);
		glTexCoord2d(1.0,0.0); glVertex3f( -2.0f, -10.0f, -2.0f);
		glTexCoord2d(1.0,1.0); glVertex3f(-2.0f, -2.0f, -2.0f);
		glTexCoord2d(0.0,1.0); glVertex3f(-10.0f, -2.0f, -2.0f);
		glTexCoord2d(0.0,0.0); glVertex3f(-10.0f, -10.0f, -2.0f);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEndList();
}


void Room::openDoor() { // opens door in the scene
	glPushMatrix();
	glTranslatef(-10.0,-3.0,-4.0);
	glRotatef(-angle*5.,0.0,1.0,0.0);
	glTranslatef(10.0,0.0,2.0);
}


// File supporting drawing of basic openGL figures

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

GLuint loadBMP_custom(const char * imagepath) {
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;
	// Open the file
	FILE * file = fopen(imagepath,"rb");
	if (!file) {
		printf("Image could not be opened\n"); return 0;
	}
	if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
	    printf("Not a correct BMP file\n");
	    return false;
	}
	if ( header[0]!='B' || header[1]!='M' ){
	    printf("Not a correct BMP file\n");
	    return 0;
	}
	// Read ints from the byte array
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);
	// Some BMP files are misformatted, guess missing information
	if (imageSize==0)    
		imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      
		dataPos=54; // The BMP header
	// Create a buffer
	data = new unsigned char [imageSize];
	 
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
	 
	//Everything is in memory now, the file can be closed
	fclose(file);
		// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
	 
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	 
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return textureID;
}

// draws circle with given parameters
void drawCircle(float radius, float cx, float cy, float cz) { 
   glBegin(GL_LINE_LOOP);
   glTranslatef(cx,cy,cz);
   glColor3f(0,0,0);
	for(int i =0; i <= 300; i++){
		double angle = 2 * 3.14 * i / 300;
		double x = cx+radius*cos(angle);
		double y = cy+radius*sin(angle);
		glVertex2d(x,y);
	}
	glEnd(); 
}

// draws a solid cylinder with given parameters
void solid_cylinder(GLUquadric* QUAD, float BASE, float TOP, float HEIGHT, int SLICES, int STACKS) {
	gluCylinder(QUAD, BASE, TOP, HEIGHT, SLICES, STACKS);
	glRotatef(180, 1,0,0);
	gluDisk(QUAD, 0.0f, BASE, SLICES, 1);
	glRotatef(180, 1,0,0);
	glTranslatef(0.0f, 0.0f, HEIGHT);
	gluDisk(QUAD, 0.0f, TOP, SLICES, 1);
	glTranslatef(0.0f, 0.0f, -HEIGHT);
}

// draws a sphere with given parameters
void drawsphere(float radius, GLuint texture) { 	
  	GLUquadric *quadric = gluNewQuadric();
  	gluQuadricTexture(quadric,1);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricOrientation(quadric, GLU_OUTSIDE);
	gluSphere(quadric,radius,20,20);
	gluDeleteQuadric(quadric);
	glDisable(GL_TEXTURE_2D);	
}
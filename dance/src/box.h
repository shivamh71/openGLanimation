// class declaration for music box

#ifndef BOX_H
#define BOX_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>

class Box {

public:

	GLuint musicBoxTop;

	GLuint musicBoxBase;

	GLuint musicBoxPlatform;

	float angle;

	void createBox(); // create music box

	void openBox(); // opens music box

	void closeBox(); // closes music box

};

#endif
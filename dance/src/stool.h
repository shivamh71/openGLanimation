// class declaration for Stool

#ifndef Stool_H
#define Stool_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Stool {

public:

	GLuint DL, tleg;
	
	void createStool(); // creates Stool in scene
	
};

#endif

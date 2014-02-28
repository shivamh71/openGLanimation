// class declaration for Almirah

#ifndef Almirah_H
#define Almirah_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Almirah {

public:

	GLuint DL;
	
	float angle;
	
	GLuint door;

	void createAlmirah(); // displays Almirah
	
	void openDoor(); // opens door

};

#endif

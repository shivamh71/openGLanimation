// class declaration for Chair

#ifndef Chair_H
#define Chair_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include "table.h"
using namespace std;

class Chair {

public:

	Table t;
	GLuint upper;
	
	void createChair(); // creates Chair
	
	void showChair(); // displays chair in room scene
};

#endif

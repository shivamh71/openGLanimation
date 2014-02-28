// class declaration for Table

#ifndef Table_H
#define Table_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Table {

public:

	GLuint DL, tleg;
	
	void createTable(); // creates central Table in the scene
	
};

#endif

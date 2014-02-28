// class declaration for Room

#ifndef ROOM_H
#define ROOM_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Room {

public:

	GLuint DL;
	
	float angle;
	
	GLuint door;

	void createRoom(); // displays Room
	
	void openDoor(); // opens door

};

#endif

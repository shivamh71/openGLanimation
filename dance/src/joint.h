// class declaration for human body joints

#ifndef JOINT_H
#define JOINT_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Joint {

public:

	float angleX, angleY, angleZ;

	GLuint DL, texture;

	void showJoint(float radius); // displays joint of human figure

	void rotateJointRight(); // rotates joint of human figure to right

	void rotateJointLeft(); // rotates joint of human figure to left

	void rotateJointFront(); // rotates joint of human figure to front

	void rotateJointBack(); // rotates joint of human figure to back
	
	void rotateJointClockWise(); // rotates Joint of human figure Clock Wise

	void rotateJointAntiClockWise(); // rotates Joint of human figure Anti-Clock Wise

};

#endif
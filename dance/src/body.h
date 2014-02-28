// class declaration for human body

#ifndef BODY_H
#define BODY_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "head.h"
#include "torso.h"
#include "arm.h"
#include "bone.h"
#include "hand.h"
#include "thigh.h"
#include "leg.h"
#include "palm.h"
#include "feet.h"
#include "joint.h"
#include "hat.h"
#include "room.h"

class Body {

public:

	GLuint eyesDL;

	Head bodyHead;
	
	Hat bodyHat;

	Torso upperBodyTorso, lowerBodyTorso;

	Joint bodyNeck;

	Joint midTorso;
	
	Arm leftArm, rightArm;

	Hand leftHand, rightHand;

	Thigh leftThigh, rightThigh;

	Leg leftLeg, rightLeg;

	Palm leftPalm, rightPalm;

	Feet leftFeet, rightFeet;

	Joint leftShoulder, rightShoulder, leftElbow, rightElbow;

	Joint leftWrist, rightWrist, leftHip, rightHip;

	Joint leftKnee, rightKnee, leftAnkle, rightAnkle;
	
	void createEyes(); // creates eyes of human figure

	void createBody(); // draws body of human figure

	void showBody(); // displays human figure on window

};

#endif

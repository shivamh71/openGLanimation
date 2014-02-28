// class definition for human body

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "body.h"
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
#include "room.h"
#include "draw.h"

void Body::createEyes() { // creates eyes of human figure
	eyesDL = glGenLists(3);
	glNewList(eyesDL,GL_COMPILE);
	drawCircle(0.1f,-0.1f,0.0f,0.0f);
	drawCircle(0.1f,0.3f,0.0f,0.0f);
	glEndList();
}

void Body::createBody() { // draws body of human figure
	GLuint texture1 = loadBMP_custom("./images/skin.bmp");
	GLuint texture2 = loadBMP_custom("./images/shirt.bmp");
	GLuint texture3 = loadBMP_custom("./images/jeans.bmp");
	GLuint texture4 = loadBMP_custom("./images/pant.bmp");
	GLuint texture5 = loadBMP_custom("./images/shoe.bmp");
	bodyHead.texture = texture1;
	bodyHead.showHead(0.7,0.5,1.0);
	createEyes();
	bodyNeck.texture = texture1;
	bodyNeck.showJoint(0.45);
	upperBodyTorso.texture = texture3;
	upperBodyTorso.showTorso(1.0,0.75,1.0);
	lowerBodyTorso.texture = texture3;
	lowerBodyTorso.showTorso(0.75,0.65,0.6);
	leftShoulder.texture = texture3;
	leftShoulder.showJoint(0.2);
	rightShoulder.texture = texture3;
	rightShoulder.showJoint(0.2);
	leftElbow.texture = texture3;
	leftElbow.showJoint(0.2);
	rightElbow.texture = texture3;
	rightElbow.showJoint(0.2);
	leftArm.texture = texture3;
	leftArm.showArm(0.2,0.7);
	rightArm.texture = texture3;
	rightArm.showArm(0.2,0.7);
	leftHand.texture = texture3;
	leftHand.showHand(0.2,0.7);
	rightHand.texture = texture3;
	rightHand.showHand(0.2,0.7);
	midTorso.texture = texture3;
	midTorso.showJoint(0.75);
	leftWrist.texture = texture3;
	leftWrist.showJoint(0.18);
	rightWrist.texture = texture3;
	rightWrist.showJoint(0.18);
	leftHip.texture = texture4;
	leftHip.showJoint(0.18);
	rightHip.texture = texture4;
	rightHip.showJoint(0.18);
	leftThigh.texture = texture4;
	leftThigh.showThigh(0.2,0.8);
	rightThigh.texture = texture4;
	rightThigh.showThigh(0.2,0.8);
	leftKnee.texture = texture4;
	leftKnee.showJoint(0.18);
	rightKnee.texture = texture4;
	rightKnee.showJoint(0.18);
	leftLeg.texture = texture4;
	leftLeg.showLeg(0.2,0.9);
	rightLeg.texture = texture4;
	rightLeg.showLeg(0.2,0.9);
	leftAnkle.texture = texture4;
	leftAnkle.showJoint(0.18);
	rightAnkle.texture = texture4;
	rightAnkle.showJoint(0.18);
	leftPalm.texture = texture1;
	leftPalm.showPalm(0.17,0.5);
	rightPalm.texture = texture1;
	rightPalm.showPalm(0.17,0.5);
	leftFeet.texture = texture5;
	leftFeet.showFeet(0.17,0.7);
	rightFeet.texture = texture5;
	rightFeet.showFeet(0.17,0.7);
	bodyHat.texture = texture5;
	bodyHat.showHat(1.2,0.6,0.6,0.6);
	
}

void Body::showBody() { // displays human figure on window
	glTranslatef(0,3.0,-12.0);
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(3.0f,-3.1f,0.0f);
	glRotatef(90.,1.0,0.0,0.0);
	glRotatef(midTorso.angleX*10.,1.0,0.0,0.0);
	glRotatef(midTorso.angleY*10.,0.0,1.0,0.0);
	glRotatef(midTorso.angleZ*10.,0.0,0.0,1.0);
	glCallList(midTorso.DL);	

		glPushMatrix();
		glColor3f(1,1,1);
		glRotatef(upperBodyTorso.angleX*10.,1.0,0.0,0.0);
		glRotatef(upperBodyTorso.angleY*10.,0.0,1.0,0.0);
		glRotatef(upperBodyTorso.angleZ*10.,0.0,0.0,1.0);
		glRotatef(-90.,1.0,0.0,0.0);
		glTranslatef(0.0f,0.9f,0.0f);
		glRotatef(70.,1.0,0.0,0.0);
		glCallList(upperBodyTorso.DL);
		
			glPushMatrix();
			glColor3f(1,1,1);
			glRotatef(-70.,1.0,0.0,0.0);
			glTranslatef(0.0f,0.45f,0.0f);
			glRotatef(80.,1.0,0.0,0.0);
			glRotatef(bodyNeck.angleX*10.,1.0,0.0,0.0);
			glRotatef(bodyNeck.angleY*10.,0.0,1.0,0.0);
			glRotatef(bodyNeck.angleZ*10.,0.0,0.0,1.0);
			glCallList(bodyNeck.DL);	
			
				glPushMatrix();
				glColor3f(1.0,1.0,1.0);
				glRotatef(-80.,1.0,0.0,0.0);
				glTranslatef(0.0f,1.1f,0.0f);
				glRotatef(80.,1.0,0.0,0.0);
				glRotatef(bodyHead.angleX*10.,1.0,0.0,0.0);
				glRotatef(bodyHead.angleY*10.,0.0,1.0,0.0);
				glRotatef(bodyHead.angleZ*10.,0.0,0.0,1.0);
				glCallList(bodyHead.DL);
			  
					glPushMatrix(); 
					glColor3f(1,1,1);
					glTranslatef(0.0,0.0,-1.0);
					glRotatef(-80.,1.0,0.0,0.0);
					glTranslatef(0.0,-1.5,1.0);
					glCallList(eyesDL);
					glPopMatrix();  
					
					glPushMatrix();
					glColor3f(1,1,1);
					glRotatef(-80.,1.0,0.0,0.0);
					glTranslatef(0.0,0.15,0.0);
					glCallList(bodyHat.DL1);
					glPopMatrix();
					
				
				glPopMatrix();  
				
				
				glPushMatrix();
				glColor3f(1.0,1.0,1.0);
				glRotatef(-80.,1.0,0.0,0.0);
				glTranslatef(0.0f,1.8f,0.0f);
				glRotatef(80.,1.0,0.0,0.0);
				glCallList(bodyHat.DL2);  
				glPopMatrix(); 
			glPopMatrix();
		
			glPushMatrix();
			glColor3f(1,1,1);
			glRotatef(-70.,1.0,0.0,0.0);
			glTranslatef(1.2,0.1,0.0);
			glRotatef(80.,1.0,0.0,0.0);
			glRotatef(leftShoulder.angleX*10.,1.0,0.0,0.0);
			glRotatef(leftShoulder.angleY*10.,0.0,1.0,0.0);
			glRotatef(leftShoulder.angleZ*10.,0.0,0.0,1.0);
			glCallList(leftShoulder.DL);	
		
				glPushMatrix();
				glColor3f(1,1,1);
				glRotatef(-80.,1.0,0.0,0.0);
				glTranslatef(0.0,-0.1,0.0);
				glRotatef(90.,1.0,0.0,0.0);
				glRotatef(leftArm.angleX*10.,1.0,0.0,0.0);
				glRotatef(leftArm.angleY*10.,0.0,1.0,0.0);
				glRotatef(leftArm.angleZ*10.,0.0,0.0,1.0);
				glCallList(leftArm.DL);	
	
					glPushMatrix();
					glColor3f(1,1,1);
					glRotatef(-90.,1.0,0.0,0.0);
					glTranslatef(0.0,-0.75,0.0);
					glRotatef(80.,1.0,0.0,0.0);
					glRotatef(leftElbow.angleX*10.,1.0,0.0,0.0);
					glRotatef(leftElbow.angleY*10.,0.0,1.0,0.0);
					glRotatef(leftElbow.angleZ*10.,0.0,0.0,1.0);
					glCallList(leftElbow.DL);

						glPushMatrix();
						glColor3f(1,1,1);
						glRotatef(-90.,1.0,0.0,0.0);
						glTranslatef(0.0,-0.15,0.0);
						glRotatef(90.,1.0,0.0,0.0);
						glRotatef(leftHand.angleX*10.,1.0,0.0,0.0);
						glRotatef(leftHand.angleY*10.,0.0,1.0,0.0);
						glRotatef(leftHand.angleZ*10.,0.0,0.0,1.0);
						glCallList(leftHand.DL);	
		
							glPushMatrix();
							glColor3f(1.0,1.0,1.0);
							glRotatef(-90.,1.0,0.0,0.0);
							glTranslatef(0.0,-0.8,0.0);
							glRotatef(80.,1.0,0.0,0.0);
							glRotatef(leftWrist.angleX*10.,1.0,0.0,0.0);
							glRotatef(leftWrist.angleY*10.,0.0,1.0,0.0);
							glRotatef(leftWrist.angleZ*10.,0.0,0.0,1.0);
							glCallList(leftWrist.DL);

								glPushMatrix();
								glColor3f(1,1,1);
								glRotatef(-80.,1.0,0.0,0.0);
								glTranslatef(0.0,-0.1,0.0);
								glRotatef(leftPalm.angleX*10.,1.0,0.0,0.0);
								glRotatef(leftPalm.angleY*10.,0.0,1.0,0.0);
								glRotatef((leftPalm.angleZ+2)*10.,0.0,0.0,1.0);
								glRotatef(90.,1.0,0.0,0.0);
								glCallList(leftPalm.DL);	
								glPopMatrix();

							glPopMatrix();

						glPopMatrix();

					glPopMatrix();
	
				glPopMatrix();
		
			glPopMatrix();
	
			glPushMatrix();
			glColor3f(1,1,1);
			glRotatef(-70.,1.0,0.0,0.0);
			glTranslatef(-1.1,0.1,0.0);
			glRotatef(80.,1.0,0.0,0.0);
			glRotatef(rightShoulder.angleX*10.,1.0,0.0,0.0);
			glRotatef(rightShoulder.angleY*10.,0.0,1.0,0.0);
			glRotatef(rightShoulder.angleZ*10.,0.0,0.0,1.0);
			glCallList(rightShoulder.DL);	
		
				glPushMatrix();
				glColor3f(1,1,1);
				glRotatef(-80.,1.0,0.0,0.0);
				glTranslatef(0.0,-0.1,0.0);
				glRotatef(rightArm.angleX*10.,1.0,0.0,0.0);
				glRotatef(rightArm.angleY*10.,0.0,1.0,0.0);
				glRotatef(rightArm.angleZ*10.,0.0,0.0,1.0);
				glRotatef(90.,1.0,0.0,0.0);
				glCallList(rightArm.DL);	
	
					glPushMatrix();
					glColor3f(1,1,1);
					glRotatef(-90.,1.0,0.0,0.0);
					glTranslatef(0.0,-0.75,0.0);
					glRotatef(80.,1.0,0.0,0.0);
					glRotatef(rightElbow.angleX*10.,1.0,0.0,0.0);
					glRotatef(rightElbow.angleY*10.,0.0,1.0,0.0);
					glRotatef(rightElbow.angleZ*10.,0.0,0.0,1.0);
					glCallList(rightElbow.DL);

						glPushMatrix();
						glColor3f(1,1,1);
						glRotatef(-90.,1.0,0.0,0.0);
						glTranslatef(0.0,-0.15,0.0);
						glRotatef(90.,1.0,0.0,0.0);
						glRotatef(rightHand.angleX*10.,1.0,0.0,0.0);
						glRotatef(rightHand.angleY*10.,0.0,1.0,0.0);
						glRotatef(rightHand.angleZ*10.,0.0,0.0,1.0);
						glCallList(rightHand.DL);	
		
							glPushMatrix();
							glColor3f(1.0,1.0,1.0);
							glRotatef(-90.,1.0,0.0,0.0);
							glTranslatef(0.0,-0.8,0.0);
							glRotatef(80.,1.0,0.0,0.0);
							glRotatef(rightWrist.angleX*10.,1.0,0.0,0.0);
							glRotatef(rightWrist.angleY*10.,0.0,1.0,0.0);
							glRotatef(rightWrist.angleZ*10.,0.0,0.0,1.0);
							glCallList(rightWrist.DL);

								glPushMatrix();
								glColor3f(1,1,1);
								glRotatef(-80.,1.0,0.0,0.0);
								glTranslatef(0.0,-0.1,0.0);
								glRotatef(rightPalm.angleX*10.,1.0,0.0,0.0);
								glRotatef(rightPalm.angleY*10.,0.0,1.0,0.0);
								glRotatef((rightPalm.angleZ-2)*10.,0.0,0.0,1.0);
								glRotatef(90.,1.0,0.0,0.0);
								glCallList(rightPalm.DL);	
								glPopMatrix();

							glPopMatrix();
						
						glPopMatrix();

					glPopMatrix();
	
				glPopMatrix();	
		
			glPopMatrix();
	
		glPopMatrix();

		glPushMatrix();
		glColor3f(1,1,1);
		glRotatef(lowerBodyTorso.angleX*10.,1.0,0.0,0.0);
		glRotatef(lowerBodyTorso.angleY*10.,0.0,1.0,0.0);
		glRotatef(lowerBodyTorso.angleZ*10.,0.0,0.0,1.0);
		glRotatef(-90.,1.0,0.0,0.0);
		glTranslatef(0.0f,-0.2f,0.0f);
		glRotatef(70.,1.0,0.0,0.0);
		glCallList(lowerBodyTorso.DL);		
		
			glPushMatrix();
			glColor3f(1,1,1);
			glRotatef(-70.,1.0,0.0,0.0);
			glTranslatef(0.3f,-0.75f,0.0f);
			glRotatef(70.,1.0,0.0,0.0);
			glRotatef(leftHip.angleX*10.,1.0,0.0,0.0);
			glRotatef(leftHip.angleY*10.,0.0,1.0,0.0);
			glRotatef(leftHip.angleZ*10.,0.0,0.0,1.0);
			glCallList(leftHip.DL);	
		
				glPushMatrix();
				glColor3f(1,1,1);
				glRotatef(-70.,1.0,0.0,0.0);
				glTranslatef(0.0f,-0.05f,0.0f);
				glRotatef(leftThigh.angleX*10.,1.0,0.0,0.0);
				glRotatef(leftThigh.angleY*10.,0.0,1.0,0.0);
				glRotatef(leftThigh.angleZ*10.,0.0,0.0,1.0);
				glRotatef(90.,1.0,0.0,0.0);
				glCallList(leftThigh.DL);	
			
					glPushMatrix();
					glColor3f(1,1,1);
					glRotatef(-90.,1.0,0.0,0.0);
					glTranslatef(0.0f,-0.95f,0.0f);
					glRotatef(90.,1.0,0.0,0.0);
					glRotatef(leftKnee.angleX*10.,1.0,0.0,0.0);
					glRotatef(leftKnee.angleY*10.,0.0,1.0,0.0);
					glRotatef(leftKnee.angleZ*10.,0.0,0.0,1.0);
					glCallList(leftKnee.DL);	

						glPushMatrix();
						glColor3f(1,1,1);
						glRotatef(-90.,1.0,0.0,0.0);
						glTranslatef(0.0f,-0.05f,0.0f);
						glRotatef(90.,1.0,0.0,0.0);
						glRotatef(leftLeg.angleX*10.,1.0,0.0,0.0);
						glRotatef(leftLeg.angleY*10.,0.0,1.0,0.0);
						glRotatef(leftLeg.angleZ*10.,0.0,0.0,1.0);
						glCallList(leftLeg.DL);
					
							glPushMatrix();
							glColor3f(1,1,1);
							glRotatef(-90.,1.0,0.0,0.0);
							glTranslatef(0.0f,-1.05f,0.0f);
							glRotatef(90.,1.0,0.0,0.0);
							glRotatef(leftAnkle.angleX*10.,1.0,0.0,0.0);
							glRotatef(leftAnkle.angleY*10.,0.0,1.0,0.0);
							glRotatef(leftAnkle.angleZ*10.,0.0,0.0,1.0);
							glCallList(leftAnkle.DL);

								glPushMatrix();
								glColor3f(1,1,1);
								glRotatef(-90.,1.0,0.0,0.0);
								glTranslatef(0.0,-0.05,0.0);
								glRotatef(leftFeet.angleX*10.,1.0,0.0,0.0);
								glRotatef(leftFeet.angleY*10.,0.0,1.0,0.0);
								glRotatef((leftFeet.angleZ+2)*10.,0.0,0.0,1.0);
								glRotatef(90.,1.0,0.0,0.0);
								glCallList(leftFeet.DL);	
								glPopMatrix();	

							glPopMatrix();
						
						glPopMatrix();

					glPopMatrix();
			
				glPopMatrix();
		
			glPopMatrix();
		
			glPushMatrix();
			glColor3f(1,1,1);
			glRotatef(-70.,1.0,0.0,0.0);
			glTranslatef(-0.3f,-0.75f,0.0f);
			glRotatef(70.,1.0,0.0,0.0);
			glRotatef(rightHip.angleX*10.,1.0,0.0,0.0);
			glRotatef(rightHip.angleY*10.,0.0,1.0,0.0);
			glRotatef(rightHip.angleZ*10.,0.0,0.0,1.0);
			glCallList(rightHip.DL);	
		
				glPushMatrix();
				glColor3f(1,1,1);
				glRotatef(-70.,1.0,0.0,0.0);
				glTranslatef(0.0f,-0.05f,0.0f);
				glRotatef(90.,1.0,0.0,0.0);
				glRotatef(rightThigh.angleX*10.,1.0,0.0,0.0);
				glRotatef(rightThigh.angleY*10.,0.0,1.0,0.0);
				glRotatef(rightThigh.angleZ*10.,0.0,0.0,1.0);
				glCallList(rightThigh.DL);	
			
					glPushMatrix();
					glColor3f(1,1,1);
					glRotatef(-90.,1.0,0.0,0.0);
					glTranslatef(0.0f,-0.95f,0.0f);
					glRotatef(70.,1.0,0.0,0.0);
					glRotatef(rightKnee.angleX*10.,1.0,0.0,0.0);
					glRotatef(rightKnee.angleY*10.,0.0,1.0,0.0);
					glRotatef(rightKnee.angleZ*10.,0.0,0.0,1.0);
					glCallList(rightKnee.DL);	

						glPushMatrix();
						glColor3f(1,1,1);
						glRotatef(-90.,1.0,0.0,0.0);
						glTranslatef(0.0f,-0.05f,0.0f);
						glRotatef(90.,1.0,0.0,0.0);
						glRotatef(rightLeg.angleX*10.,1.0,0.0,0.0);
						glRotatef(rightLeg.angleY*10.,0.0,1.0,0.0);
						glRotatef(rightLeg.angleZ*10.,0.0,0.0,1.0);
						glCallList(rightLeg.DL);	
							
							glPushMatrix();
							glColor3f(1,1,1);
							glRotatef(-90.,1.0,0.0,0.0);
							glTranslatef(0.0f,-1.05f,0.0f);
							glRotatef(90.,1.0,0.0,0.0);
							glRotatef(rightAnkle.angleX*10.,1.0,0.0,0.0);
							glRotatef(rightAnkle.angleY*10.,0.0,1.0,0.0);
							glRotatef(rightAnkle.angleZ*10.,0.0,0.0,1.0);
							glCallList(rightAnkle.DL);	

								glPushMatrix();
								glColor3f(1,1,1);
								glRotatef(-90.,1.0,0.0,0.0);
								glTranslatef(0.0,-0.05,0.0);
								glRotatef(rightFeet.angleX*10.,1.0,0.0,0.0);
								glRotatef(rightFeet.angleY*10.,0.0,1.0,0.0);
								glRotatef((rightFeet.angleZ-2)*10.,0.0,0.0,1.0);
								glRotatef(90.,1.0,0.0,0.0);
								glCallList(rightFeet.DL);	
								glPopMatrix();

							glPopMatrix();

						glPopMatrix();

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

		glPopMatrix();

	glPopMatrix();
	
	
    glutSwapBuffers();
}

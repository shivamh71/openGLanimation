// Header Files
/********************************************************************************/
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
/********************************************************************************/

// Include Files
/********************************************************************************/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "box.h"
#include "body.h"
#include "joint.h"
#include "table.h"
#include "stool.h"
#include "chair.h"
#include "room.h"
#include "almirah.h"
#include "draw.h"
/********************************************************************************/

// Parameters for video frame generation
/********************************************************************************/
vector<float> param1(51,0.0); 
vector<float> param2(51,0.0);
vector<float> change(51,0.0);
float maxChange = 0.0;
string lamp1Status1, lamp2Status1, lamp1Status2, lamp2Status2;
string frameFileName;
ifstream movieIn;
float eofReader;
string lampReader;
bool movieStart = false;
/********************************************************************************/

// Global Variables
/********************************************************************************/
static float angle=0.0, ratio, manPos = -3.0; 
static float eyex=-8.0f, eyey=-3.0f, eyez=2.0f; // eye initial position
static float lx=-3.0f, ly=-3.0f, lz=-12.0f; // look at vector position
GLfloat mat_dif[] = { 1.0, 1.0, 1.0, 1.0 }; // diffused light set
GLfloat light_position[] = { 0.0, 4.0, -2.0, 1.0 }; // positioning first light
GLfloat light_pos[] = { 9.0, 11.0, -5.0, 1.0 }; // positioning second light
Box* musicBox; // music Box object
Table* table; // table object
Stool* stool; // stool object
Chair* chair; // chair object
Body* human; // human figure
Room* room; // room
Almirah* almirah; // almirah in room
string mode = "NULL"; // mode to monitor human body movements
GLdouble ax, ay, az = 0; // 3D points draw in the scene for camera animation
GLuint lamp1DL, lampTexture; // lamp display list and its texture
vector<float> curvePointX, curvePointY, curvePointZ;
bool m = false, l1 = true, l2 = true;
int pos = 0;
ofstream fout, ftemp; // ofstream object to write frames
ifstream fin;
string playMode = "frame";
/********************************************************************************/

// Capturing frames for movie generation
/********************************************************************************/
bool recording=false; // toggle switch to on/off recording frames
unsigned int framenum=0; // frame number
unsigned char *pRGB;
int SCREEN_WIDTH=800;
int SCREEN_HEIGHT=600;

// frame capture function
void capture_frame(unsigned int framenum)
{
	//global pointer float *pRGB
	pRGB = new unsigned char [3 * (SCREEN_WIDTH+1) * (SCREEN_HEIGHT + 1) ];
	// set the framebuffer to read
	//default for double buffered
	glReadBuffer(GL_BACK);
	glPixelStoref(GL_PACK_ALIGNMENT,1);//for word allignment
	glReadPixels(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pRGB);
	char filename[200];
	sprintf(filename,"./frames/frame_%04d.ppm",framenum);
	std::ofstream out(filename, std::ios::out);
	out<<"P6"<<std::endl;
	out<<SCREEN_WIDTH<<" "<<SCREEN_HEIGHT<<" 255"<<std::endl;
	out.write(reinterpret_cast<char const *>(pRGB), (3 * (SCREEN_WIDTH+1) * (SCREEN_HEIGHT + 1)) * sizeof(int));
	out.close();
	delete pRGB;
}
/********************************************************************************/

// Window Resize Function
/********************************************************************************/
void resize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0) h = 1;
	ratio = 1.0f * w / h;
	SCREEN_HEIGHT = h;
	SCREEN_WIDTH = w;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez,lx,ly,lz, 0.0f, 1.0f, 0.0f);

}
/********************************************************************************/

// Plot and render Bezier Curve
/********************************************************************************/
void drawCurve() {
	vector<float> temp1, temp2, temp3;
	int s = curvePointX.size()-1;
	for (float i=0.0;i<=1.0;i+=0.01) {
		int count = s;
		temp1 = curvePointX;
		temp2 = curvePointY;
		temp3 = curvePointZ;		
		while (count!=0) {
			for (int j=0;j<count;j++) {
				float x1 = temp1[j];
				float x2 = temp1[j+1];
				float y1 = temp2[j];
				float y2 = temp2[j+1];
				float z1 = temp3[j];
				float z2 = temp3[j+1];
				float x = (x2-x1)*i + x1;
				float y = (y2-y1)*i + y1;
				float z = (z2-z1)*i + z1;
				temp1[j] = x;
				temp2[j] = y;
				temp3[j] = z;
			}
			count--;
		}
		curvePointX.push_back(temp1[0]);
		curvePointY.push_back(temp2[0]);
		curvePointZ.push_back(temp3[0]);
	}
	curvePointX.erase(curvePointX.begin(),curvePointX.begin()+s+1);
	curvePointY.erase(curvePointY.begin(),curvePointY.begin()+s+1);
	curvePointZ.erase(curvePointZ.begin(),curvePointZ.begin()+s+1);
}
/********************************************************************************/

// Function to read frames from text file and generate movie
/********************************************************************************/
void createMovie(int value) {
	if (movieStart) {
		movieIn>>eofReader;
		if (eofReader==-100) {
			movieStart = false;
			recording = false;
			cout<<"finished\n";
			glutPostRedisplay();
		}
		else {
			eyex = eofReader;
			movieIn>>eyey>>eyez;
			movieIn>>lampReader;
			if (lampReader=="ON") {
				l1 = true;
			}
			else {
				l1 = false;
			}
			movieIn>>lampReader;
			if (lampReader=="ON") {
				l2 = true;
			}
			else {
				l2 = false;
			}
			// reading frames from file and setting display parameters accrodingly
			float temp;
			movieIn>>temp; room->angle = temp;
			movieIn>>temp; musicBox->angle = temp;
			movieIn>>temp; almirah->angle = temp;
			manPos = -3.0 + (musicBox->angle)*0.068;
			movieIn>>temp; human->bodyNeck.angleX = temp;
			movieIn>>temp; human->bodyNeck.angleY = temp;
			movieIn>>temp; human->bodyNeck.angleZ = temp;
			movieIn>>temp; human->leftShoulder.angleX = temp;
			movieIn>>temp; human->leftShoulder.angleY = temp;
			movieIn>>temp; human->leftShoulder.angleZ = temp;
			movieIn>>temp; human->rightShoulder.angleX = temp;
			movieIn>>temp; human->rightShoulder.angleY = temp;
			movieIn>>temp; human->rightShoulder.angleZ = temp;
			movieIn>>temp; human->leftElbow.angleX = temp;
			movieIn>>temp; human->leftElbow.angleY = temp;
			movieIn>>temp; human->leftElbow.angleZ = temp;
			movieIn>>temp; human->rightElbow.angleX = temp;
			movieIn>>temp; human->rightElbow.angleY = temp;
			movieIn>>temp; human->rightElbow.angleZ = temp;
			movieIn>>temp; human->leftWrist.angleX = temp;
			movieIn>>temp; human->leftWrist.angleY = temp;
			movieIn>>temp; human->leftWrist.angleZ = temp;
			movieIn>>temp; human->rightWrist.angleX = temp;
			movieIn>>temp; human->rightWrist.angleY = temp;
			movieIn>>temp; human->rightWrist.angleZ = temp;
			movieIn>>temp; human->lowerBodyTorso.angleX = temp;
			movieIn>>temp; human->lowerBodyTorso.angleY = temp;
			movieIn>>temp; human->lowerBodyTorso.angleZ = temp;
			movieIn>>temp; human->upperBodyTorso.angleX = temp;
			movieIn>>temp; human->upperBodyTorso.angleY = temp;
			movieIn>>temp; human->upperBodyTorso.angleZ = temp;
			movieIn>>temp; human->leftHip.angleX = temp;
			movieIn>>temp; human->leftHip.angleY = temp;
			movieIn>>temp; human->leftHip.angleZ = temp;
			movieIn>>temp; human->rightHip.angleX = temp;
			movieIn>>temp; human->rightHip.angleY = temp;
			movieIn>>temp; human->rightHip.angleZ = temp;
			movieIn>>temp; human->leftKnee.angleX = temp;
			movieIn>>temp; human->leftKnee.angleY = temp;
			movieIn>>temp; human->leftKnee.angleZ = temp;
			movieIn>>temp; human->rightKnee.angleX = temp;
			movieIn>>temp; human->rightKnee.angleY = temp;
			movieIn>>temp; human->rightKnee.angleZ = temp;
			movieIn>>temp; human->leftAnkle.angleX = temp;
			movieIn>>temp; human->leftAnkle.angleY = temp;
			movieIn>>temp; human->leftAnkle.angleZ = temp;
			movieIn>>temp; human->rightAnkle.angleX = temp;
			movieIn>>temp; human->rightAnkle.angleY = temp;
			movieIn>>temp; human->rightAnkle.angleZ = temp;
			glutPostRedisplay();
		}
	}
	glutTimerFunc(10,createMovie,0);
}
/********************************************************************************/

// Initialize room scene
/********************************************************************************/
void initScene() {

	// open file for capturing frames
	fout.open("keyframes.txt",ios::out); 
	// fout<<"EYEX EYEY EYEZ LAMP1 LAMP2 DOOR MUSICBOX ALMIRAH NECK LEFTSHOULDERX LEFTSHOULDERY LEFTSHOULDERZ RIGHTSHOULDERX RIGHTSHOULDERY RIGHTSHOULDERZ LEFTELBOWX LEFTELBOWY LEFTELBOWZ RIGHTELBOWX RIGHTELBOWY RIGHTELBOWZ LEFTWRISTX LEFTWRISTY LEFTWRISTZ RIGHTWRISTX RIGHTWRISTY RIGHTWRISTZ TORSOX TORSOY TORSOZ LEFTHIPX LEFTHIPY LEFTHIPZ RIGHTHIPX RIGHTHIPY RIGHTHIPZ LEFTKNEEX LEFTKNEEY LEFTKNEEZ RIGHTKNEEX RIGHTKNEEY RIGHTKNEEZ LEFTANKLEX LEFTANKLEY LEFTANKLEZ RIGHTANKLEX RIGHTANKLEY RIGHTANKLEZ\n";

	glEnable(GL_DEPTH_TEST);

	// initialize all objects in room
	musicBox->createBox();
	human->createBody();
	room->createRoom();
	almirah->createAlmirah();
	table->createTable();
	stool->createStool();
	chair->createChair();
	manPos = -3.0;

	// Lamp 1
	// displaying lamp placed on table
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);

	// enabling lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	lamp1DL = glGenLists(1);
	GLUquadric *quadric = gluNewQuadric();
	glNewList(lamp1DL,GL_COMPILE);
		gluQuadricDrawStyle(quadric, GLU_FILL);
		gluQuadricOrientation(quadric, GLU_OUTSIDE);
		glPushMatrix();
			glTranslatef(0.0f,-4.0f,0.0f);
			glRotatef(90,1,0,0);
			solid_cylinder(quadric, 5.0, 5.0, 1.0,22,22);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0f,5.0f,0.0f);
			glRotatef(90,1,0,0);
			solid_cylinder(quadric, 0.5, 0.5, 10.0,22,22);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0f,8.0f,0.0f);
			glRotatef(90,1,0,0);
			solid_cylinder(quadric, 1, 3, 3.0,22,22);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0f,8.0f,0.0f);
			glRotatef(90,1,0,0);
			solid_cylinder(quadric, 1, 1, 0.1,22,22);
		glPopMatrix();
		gluDeleteQuadric(quadric);	
	glEndList();
}
/********************************************************************************/

// keyboard Functions
/********************************************************************************/
void processNormalKeys (unsigned char key, int x, int y) {
	switch (key) {
		case 27: // quit program
			fout<<"-100";
			fout.close(); // closing frame capture
			exit(1);
			break;
		case 'D': // start animation reading frames from given file
			cout<<"Give file name to read frames from : ";
			cin>>frameFileName;
			movieIn.open(frameFileName.c_str(),ios::in);
			movieStart = true;
			recording = true;
			break;
		case '5': // toggle between playback and frame_capture mode
			if (playMode=="frame") {
				playMode = "playback";
				fout<<"-100";
				fout.close(); // closing frame capture
			}
			else playMode = "frame";
			glutPostRedisplay();
			break;
		case 'r': // saving current frame
			if (playMode=="frame") {
				if (!fout) {
					cout<<"file couldn't be opened\n";
				}
				else {
					// writing header
					fout<<eyex<<" "<<eyey<<" "<<eyez<<" "; // storing eye co-ordinates
					// storing lamp status
					if (l1) {
						fout<<"ON ";
					}
					else {
						fout<<"OFF ";
					}
					if (l2) {
						fout<<"ON ";
					}
					else {
						fout<<"OFF ";
					}
					fout<<room->angle<<" "<<musicBox->angle<<" "; // storing door and music box lid status
					fout<<almirah->angle<<" "; // storing almirah open status
					// storing human figure status
					fout<<human->bodyNeck.angleX<<" "<<human->bodyNeck.angleY<<" "<<human->bodyNeck.angleZ<<" ";
					fout<<human->leftShoulder.angleX<<" "<<human->leftShoulder.angleY<<" "<<human->leftShoulder.angleZ<<" ";
					fout<<human->rightShoulder.angleX<<" "<<human->rightShoulder.angleY<<" "<<human->rightShoulder.angleZ<<" ";
					fout<<human->leftElbow.angleX<<" "<<human->leftElbow.angleY<<" "<<human->leftElbow.angleZ<<" ";
					fout<<human->rightElbow.angleX<<" "<<human->rightElbow.angleY<<" "<<human->rightElbow.angleZ<<" ";
					fout<<human->leftWrist.angleX<<" "<<human->leftWrist.angleY<<" "<<human->leftWrist.angleZ<<" ";
					fout<<human->rightWrist.angleX<<" "<<human->rightWrist.angleY<<" "<<human->rightWrist.angleZ<<" ";
					fout<<human->lowerBodyTorso.angleX<<" "<<human->lowerBodyTorso.angleY<<" "<<human->lowerBodyTorso.angleZ<<" ";
					fout<<human->upperBodyTorso.angleX<<" "<<human->upperBodyTorso.angleY<<" "<<human->upperBodyTorso.angleZ<<" ";
					fout<<human->leftHip.angleX<<" "<<human->leftHip.angleY<<" "<<human->leftHip.angleZ<<" ";
					fout<<human->rightHip.angleX<<" "<<human->rightHip.angleY<<" "<<human->rightHip.angleZ<<" ";
					fout<<human->leftKnee.angleX<<" "<<human->leftKnee.angleY<<" "<<human->leftKnee.angleZ<<" ";
					fout<<human->rightKnee.angleX<<" "<<human->rightKnee.angleY<<" "<<human->rightKnee.angleZ<<" ";
					fout<<human->leftAnkle.angleX<<" "<<human->leftAnkle.angleY<<" "<<human->leftAnkle.angleZ<<" ";
					fout<<human->rightAnkle.angleX<<" "<<human->rightAnkle.angleY<<" "<<human->rightAnkle.angleZ<<endl;
				}
				glutPostRedisplay();
			}
			else {
				// generating interpolated frames and writing them to a new file
				cout<<"Give filename to pick frames from : ";
				cin>>frameFileName;
				fin.open(frameFileName.c_str(),ios::in);
				ftemp.open("movie.txt",ios::out);
				fin>>param1[0];
				cout<<param1[0];
				if (param1[0]!=-100) {
					fin>>param1[1]>>param1[2];
					fin>>lamp1Status1>>lamp2Status1;
					for (int i=3;i<param1.size();i++) fin>>param1[i];
					while(1) {
						fin>>param2[0];
						if (param2[0]==-100) break;
						fin>>param2[1]>>param2[2];
						fin>>lamp1Status2>>lamp2Status2;
						for (int i=3;i<param2.size();i++) fin>>param2[i];
						maxChange = 0.0;
						for (int i=0;i<51;i++) {
							change[i] = param2[i] - param1[i];
							if (abs(change[i])>maxChange) maxChange = abs(change[i]);	
						}
						maxChange*=5;
						if (maxChange==0) maxChange = 1;
						cout<<"maxChange = "<<maxChange<<endl;
						for (int j=0;j<(maxChange/2);j++) {
							cout<<"generating interpolated frame\n";
							ftemp<<(param1[0] + (change[0]*j)/maxChange)<<" ";
							ftemp<<(param1[1] + (change[1]*j)/maxChange)<<" ";
							ftemp<<(param1[2] + (change[2]*j)/maxChange)<<" ";
							ftemp<<lamp1Status1<<" "<<lamp2Status1<<" ";
							for (int i=3;i<50;i++) ftemp<<(param1[i] + (change[i]*j)/maxChange)<<" ";
							ftemp<<(param1[50] + (change[50]*j)/maxChange)<<endl;
						}
						for (int j=(maxChange/2);j<maxChange;j++) {
							cout<<"generating interpolated frame\n";
							ftemp<<(param1[0] + (change[0]*j)/maxChange)<<" ";
							ftemp<<(param1[1] + (change[1]*j)/maxChange)<<" ";
							ftemp<<(param1[2] + (change[2]*j)/maxChange)<<" ";
							ftemp<<lamp1Status2<<" "<<lamp2Status2<<" ";
							for (int i=3;i<50;i++) ftemp<<(param1[i] + (change[i]*j)/maxChange)<<" ";
							ftemp<<(param1[50] + (change[50]*j)/maxChange)<<endl;
						}
						for (int i=0;i<51;i++) {
							param1[i] = param2[i];
						}
						lamp1Status1 = lamp1Status2;
						lamp2Status1 = lamp2Status2;
					}
					ftemp<<param1[0]<<" "<<param1[1]<<" "<<param1[2]<<" ";
					ftemp<<lamp1Status1<<" "<<lamp2Status1<<" ";
					for (int i=3;i<param1.size()-1;i++) ftemp<<param1[i]<<" ";
					ftemp<<param1[50]<<endl;
					ftemp<<-100;
				}	
				fin.close();
				ftemp.close();
				cout<<"finished creating frames\n";
				cout<<"frames written to movie.txt\n";
				glutPostRedisplay();
			}
			break;
		case GLUT_KEY_LEFT: // move eye left
			eyex--;
			glutPostRedisplay();
			break;
		case GLUT_KEY_UP: // move eye close
			eyez--;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN: // move eye back
			eyez++;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT: // move eye right
			eyex++;
			glutPostRedisplay();
			break;
		case '4': // lamp 1 toggle switch
			l1 = !l1;
			glutPostRedisplay();
			break;
		case '6': // lamp 2 toggle switch
			l2 = !l2;
			glutPostRedisplay();
			break;
		case '8': // move eye up
			eyey++;
			glutPostRedisplay();
			break;
		case '2': // move eye down
			eyey--;
			glutPostRedisplay();
			break;
		case 'u': // plot bezier curve
			drawCurve();
			glutPostRedisplay();
			break;
		case 'U': // erase bezier curve
			curvePointX.clear();
			curvePointY.clear();
			curvePointZ.clear();
			glutPostRedisplay();
			break;
		case 'C': // start camera animation
			m = true;
			break;
		case 'o': // open music Box
			if (musicBox->angle!=26) {
				musicBox->angle++;
				manPos+=0.068;
			}
			glutPostRedisplay();
			break;
		case 'O': // close music box
			if (musicBox->angle!=0) {
				musicBox->angle--;
				manPos-=0.068;
			}
			glutPostRedisplay();
			break;
			
		case 'q': // open door
			if (room->angle<=18) {
				room->angle++;
			}
			glutPostRedisplay();
			break;	
			
		case 'Q': // close room door
			if (room->angle>=1) {
				room->angle--;
				
			}
			glutPostRedisplay();
			break;	
		
		case 'v': // open almirah door
			if (almirah->angle<=18) {
				almirah->angle++;
			}
			glutPostRedisplay();
			break;	
			
		case 'V': // close almirah
			if (almirah->angle>=1) {
				almirah->angle--;
				
			}
			glutPostRedisplay();
			break;	
		
			
		case 'p': 
			az++;
			break;
		case 'P':
			az--;
			break;
		case 'c': // create scene 
			mode = "null";
			initScene();
			glutPostRedisplay();
			break;

		// body movement modes
		case 'n':
		case 'N':
			mode = "neck";
			break;
		case 's':
			mode = "leftshoulder";
			break;
		case 'S':
			mode = "rightshoulder";
			break;
		case 'l':
			mode = "leftelbow";
			break;
		case 'L':
			mode = "rightelbow";
			break;
		case 'w':
			mode = "leftwrist";
			break;
		case 'W':
			mode = "rightwrist";
			break;
		case 'h':
			mode = "lefthip";
			break;
		case 'H':
			mode = "righthip";
			break;	
		case 'k':
			mode = "leftknee";
			break;
		case 'K':
			mode = "rightknee";
			break;
		case 'a':
			mode = "leftankle";
			break;
		case 'A':
			mode = "rightankle";
			break;
		case 't':
			mode = "uppertorso";
			break;
		case 'T':
			mode = "lowertorso";
			break;	

		// movement along x-axis
		case 'x':
			if (mode=="neck") {
				if (human->bodyNeck.angleX!=4) human->bodyNeck.rotateJointFront();
			}
			else if (mode=="leftshoulder") {
				human->leftShoulder.rotateJointFront();
			}
			else if (mode=="rightshoulder") {
				human->rightShoulder.rotateJointFront();
			}
			else if (mode=="leftelbow") {
				if (human->leftElbow.angleX!=0) human->leftElbow.rotateJointFront();
			}
			else if (mode=="rightelbow") {
				if (human->rightElbow.angleX!=0) human->rightElbow.rotateJointFront();
			}
			else if (mode=="leftwrist") {
				if (human->leftWrist.angleX!=0) human->leftWrist.rotateJointFront();
			}
			else if (mode=="rightwrist") {
				if (human->rightWrist.angleX!=0) human->rightWrist.rotateJointFront();
			}
			else if (mode=="lefthip") {
				if (human->leftHip.angleX!=5) human->leftHip.rotateJointFront();
			}
			else if (mode=="righthip") {
				if (human->rightHip.angleX!=5) human->rightHip.rotateJointFront();
			}
			else if (mode=="leftknee") {
				if (human->leftKnee.angleX!=14) human->leftKnee.rotateJointFront();
			}
			else if (mode=="rightknee") {
				if (human->rightKnee.angleX!=14) human->rightKnee.rotateJointFront();
			}
			else if (mode=="leftankle") {
				if (human->leftAnkle.angleX!=2) human->leftAnkle.rotateJointFront();
			}
			else if (mode=="rightankle") {
				if (human->rightAnkle.angleX!=2) human->rightAnkle.rotateJointFront();
			}
			else if (mode=="uppertorso") {
				if (human->upperBodyTorso.angleX!=8) human->upperBodyTorso.rotateTorsoFront();
			}
			else if (mode=="lowertorso") {
				if (human->lowerBodyTorso.angleX!=8) human->lowerBodyTorso.rotateTorsoFront();
			}
			else {}
			glutPostRedisplay();
			break;
		case 'X':
			if (mode=="neck") {
				if (human->bodyNeck.angleX!=-3) human->bodyNeck.rotateJointBack();
			}
			else if (mode=="leftshoulder") {
				human->leftShoulder.rotateJointBack();
			}
			else if (mode=="rightshoulder") {
				human->rightShoulder.rotateJointBack();
			}
			else if (mode=="leftelbow") {
				if (human->leftElbow.angleX!=-14) human->leftElbow.rotateJointBack();
			}
			else if (mode=="rightelbow") {
				if (human->rightElbow.angleX!=-14) human->rightElbow.rotateJointBack();
			}
			else if (mode=="leftwrist") {
				if (human->leftWrist.angleX!=-2) human->leftWrist.rotateJointBack();
			}
			else if (mode=="rightwrist") {
				if (human->rightWrist.angleX!=-2) human->rightWrist.rotateJointBack();
			}
			else if (mode=="lefthip") {
				if (human->leftHip.angleX!=-12) human->leftHip.rotateJointBack();
			}
			else if (mode=="righthip") {
				if (human->rightHip.angleX!=-12) human->rightHip.rotateJointBack();
			}
			else if (mode=="leftknee") {
				if (human->leftKnee.angleX!=0) human->leftKnee.rotateJointBack();
			}
			else if (mode=="rightknee") {
				if (human->rightKnee.angleX!=0) human->rightKnee.rotateJointBack();
			}
			else if (mode=="leftankle") {
				if (human->leftAnkle.angleX!=-4) human->leftAnkle.rotateJointBack();
			}
			else if (mode=="rightankle") {
				if (human->rightAnkle.angleX!=-4) human->rightAnkle.rotateJointBack();
			}
			else if (mode=="uppertorso") {
				if (human->upperBodyTorso.angleX!=-4) human->upperBodyTorso.rotateTorsoBack();
			}
			else if (mode=="lowertorso") {
				if (human->lowerBodyTorso.angleX!=-8) human->lowerBodyTorso.rotateTorsoBack();
			}
			else {}
			glutPostRedisplay();
			break;

		// movement along y-axis
		case 'y':
			if (mode=="neck") {
				if (human->bodyNeck.angleY!=4) human->bodyNeck.rotateJointRight();
			}
			else if (mode=="leftshoulder") {
				human->leftShoulder.rotateJointRight();
			}
			else if (mode=="rightshoulder") {
				human->rightShoulder.rotateJointRight();
			}
			else if (mode=="leftelbow") {
				if (human->leftElbow.angleY!=0) human->leftElbow.rotateJointRight();
			}
			else if (mode=="rightelbow") {
				if (human->rightElbow.angleY!=0) human->rightElbow.rotateJointRight();
			}
			else if (mode=="leftwrist") {
				if (human->leftWrist.angleY!=4) human->leftWrist.rotateJointRight();
			}
			else if (mode=="rightwrist") {
				if (human->rightWrist.angleY!=4) human->rightWrist.rotateJointRight();
			}
			else if (mode=="lefthip") {
				if (human->leftHip.angleY!=4) human->leftHip.rotateJointRight();
			}
			else if (mode=="righthip") {
				if (human->rightHip.angleY!=4) human->rightHip.rotateJointRight();
			}
			else if (mode=="leftknee") {
				if (human->leftKnee.angleY!=0) human->leftKnee.rotateJointRight();
			}
			else if (mode=="rightknee") {
				if (human->rightKnee.angleY!=0) human->rightKnee.rotateJointRight();
			}
			else if (mode=="leftankle") {
				if (human->leftAnkle.angleY!=0) human->leftAnkle.rotateJointRight();
			}
			else if (mode=="rightankle") {
				if (human->rightAnkle.angleY!=0) human->rightAnkle.rotateJointRight();
			}
			else if (mode=="uppertorso") {
				if (human->upperBodyTorso.angleY!=4) human->upperBodyTorso.rotateTorsoRight();
			}
			else if (mode=="lowertorso") {
				if (human->lowerBodyTorso.angleY!=2) human->lowerBodyTorso.rotateTorsoRight();
			}
			else {}
			glutPostRedisplay();
			break;
		case 'Y':
			if (mode=="neck") {
				if (human->bodyNeck.angleY!=-4) human->bodyNeck.rotateJointLeft();
			}
			else if (mode=="leftshoulder") {
				human->leftShoulder.rotateJointLeft();
			}
			else if (mode=="rightshoulder") {
				human->rightShoulder.rotateJointLeft();
			}
			else if (mode=="leftelbow") {
				if (human->leftElbow.angleY!=0) human->leftElbow.rotateJointLeft();
			}
			else if (mode=="rightelbow") {
				if (human->rightElbow.angleY!=0) human->rightElbow.rotateJointLeft();
			}
			else if (mode=="leftwrist") {
				if (human->leftWrist.angleY!=-4) human->leftWrist.rotateJointLeft();
			}
			else if (mode=="rightwrist") {
				if (human->rightWrist.angleY!=-4) human->rightWrist.rotateJointLeft();
			}
			else if (mode=="lefthip") {
				if (human->leftHip.angleY!=-4) human->leftHip.rotateJointLeft();
			}
			else if (mode=="righthip") {
				if (human->rightHip.angleY!=-4) human->rightHip.rotateJointLeft();
			}
			else if (mode=="leftknee") {
				if (human->leftKnee.angleY!=0) human->leftKnee.rotateJointLeft();
			}
			else if (mode=="rightknee") {
				if (human->rightKnee.angleY!=0) human->rightKnee.rotateJointLeft();
			}
			else if (mode=="leftankle") {
				if (human->leftAnkle.angleY!=0) human->leftAnkle.rotateJointLeft();
			}
			else if (mode=="rightankle") {
				if (human->rightAnkle.angleY!=0) human->rightAnkle.rotateJointLeft();
			}
			else if (mode=="uppertorso") {
				if (human->upperBodyTorso.angleY!=-4) human->upperBodyTorso.rotateTorsoLeft();
			}
			else if (mode=="lowertorso") {
				if (human->lowerBodyTorso.angleY!=-2) human->lowerBodyTorso.rotateTorsoLeft();
			}
			else {}
			glutPostRedisplay();
			break;

		// movement along z-axis
		case 'z':
			if (mode=="neck") {
				if (human->bodyNeck.angleZ!=4) human->bodyNeck.rotateJointClockWise();
			}
			else if (mode=="leftshoulder") {
				if (human->leftShoulder.angleZ!=4) human->leftShoulder.rotateJointClockWise();
			}
			else if (mode=="rightshoulder") {
				if (human->rightShoulder.angleZ!=4) human->rightShoulder.rotateJointClockWise();
			}
			else if (mode=="leftelbow") {
				if (human->leftElbow.angleZ!=0) human->leftElbow.rotateJointClockWise();
			}
			else if (mode=="rightelbow") {
				if (human->rightElbow.angleZ!=0) human->rightElbow.rotateJointClockWise();
			}
			else if (mode=="leftwrist") {
				if (human->leftWrist.angleZ!=0) human->leftWrist.rotateJointClockWise();
			}
			else if (mode=="rightwrist") {
				if (human->rightWrist.angleZ!=0) human->rightWrist.rotateJointClockWise();
			}
			else if (mode=="lefthip") {
				if (human->leftHip.angleZ!=0) human->leftHip.rotateJointClockWise();
			}
			else if (mode=="righthip") {
				if (human->rightHip.angleZ!=0) human->rightHip.rotateJointClockWise();
			}
			else if (mode=="leftknee") {
				if (human->leftKnee.angleZ!=0) human->leftKnee.rotateJointClockWise();
			}
			else if (mode=="rightknee") {
				if (human->rightKnee.angleZ!=0) human->rightKnee.rotateJointClockWise();
			}
			else if (mode=="leftankle") {
				if (human->leftAnkle.angleZ!=0) human->leftAnkle.rotateJointClockWise();
			}
			else if (mode=="rightankle") {
				if (human->rightAnkle.angleZ!=0) human->rightAnkle.rotateJointClockWise();
			}
			else if (mode=="uppertorso") {
				if (human->upperBodyTorso.angleZ!=4) human->upperBodyTorso.rotateTorsoClockWise();
			}
			else if (mode=="lowertorso") {
				if (human->lowerBodyTorso.angleZ!=0) human->lowerBodyTorso.rotateTorsoClockWise();
			}
			else {}
			glutPostRedisplay();
			break;
		case 'Z':
			if (mode=="neck") {
				if (human->bodyNeck.angleZ!=-4) human->bodyNeck.rotateJointAntiClockWise();
			}
			else if (mode=="leftshoulder") {
				if (human->leftShoulder.angleZ!=-4) human->leftShoulder.rotateJointAntiClockWise();
			}
			else if (mode=="rightshoulder") {
				if (human->rightShoulder.angleZ!=-4) human->rightShoulder.rotateJointAntiClockWise();
			}
			else if (mode=="leftelbow") {
				if (human->leftElbow.angleZ!=0) human->leftElbow.rotateJointAntiClockWise();
			}
			else if (mode=="rightelbow") {
				if (human->rightElbow.angleZ!=0) human->rightElbow.rotateJointAntiClockWise();
			}
			else if (mode=="leftwrist") {
				if (human->leftWrist.angleZ!=0) human->leftWrist.rotateJointAntiClockWise();
			}
			else if (mode=="rightwrist") {
				if (human->rightWrist.angleZ!=0) human->rightWrist.rotateJointAntiClockWise();
			}
			else if (mode=="lefthip") {
				if (human->leftHip.angleZ!=0) human->leftHip.rotateJointAntiClockWise();
			}
			else if (mode=="righthip") {
				if (human->rightHip.angleZ!=0) human->rightHip.rotateJointAntiClockWise();
			}
			else if (mode=="leftknee") {
				if (human->leftKnee.angleZ!=0) human->leftKnee.rotateJointAntiClockWise();
			}
			else if (mode=="rightknee") {
				if (human->rightKnee.angleZ!=0) human->rightKnee.rotateJointAntiClockWise();
			}
			else if (mode=="leftankle") {
				if (human->leftAnkle.angleZ!=0) human->leftAnkle.rotateJointAntiClockWise();
			}
			else if (mode=="rightankle") {
				if (human->rightAnkle.angleZ!=0) human->rightAnkle.rotateJointAntiClockWise();
			}
			else if (mode=="uppertorso") {
				if (human->upperBodyTorso.angleZ!=-4) human->upperBodyTorso.rotateTorsoAntiClockWise();
			}
			else if (mode=="lowertorso") {
				if (human->lowerBodyTorso.angleZ!=0) human->lowerBodyTorso.rotateTorsoAntiClockWise();
			}
			else {}
			glutPostRedisplay();
			break;
		default:
			break;
	}
}
/********************************************************************************/

// Camera change 
/********************************************************************************/
void inputKey(int key, int x, int y) {
	switch (key) {  
		case GLUT_KEY_LEFT: 
			eyex--;
			glutPostRedisplay();
			break;
		case GLUT_KEY_UP: 
			eyez--;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN: 
			eyez++;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT: 
			eyex++;
			glutPostRedisplay();
			break;
  	}
}
/********************************************************************************/

// Mouse Callback
/********************************************************************************/
void mouse(int button, int state, int x, int y) {
	if (state==GLUT_DOWN) {
		if (button==GLUT_LEFT_BUTTON) {
			GLdouble modelMatrix[16];
			GLdouble projMatrix[16];
			GLint viewport[4];
			int sx = x;
			int sy = y;
			glGetIntegerv(GL_VIEWPORT, viewport);
			glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
			glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);
			GLdouble nx, ny, nz, fx, fy, fz;
			gluUnProject(sx, viewport[1] + viewport[3] - sy, 0, modelMatrix, projMatrix, viewport, &nx, &ny, &nz);
			gluUnProject(sx, viewport[1] + viewport[3] - sy, 1, modelMatrix, projMatrix, viewport, &fx, &fy, &fz);
			if (nz!=fz) {
				double r = (az-fz)/(nz-fz);
				ax = (nx-fx)*r + fx;
				ay = (ny-fy)*r + fy; 
				curvePointX.push_back(ax);
				curvePointY.push_back(ay);
				curvePointZ.push_back(az);
			}
		}
	}
	glutPostRedisplay();
}
/********************************************************************************/

// Display Function
/********************************************************************************/
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(eyex,eyey,eyez,lx,ly,lz,0,1,0);

	// toggle room lights
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, mat_dif);
	if (l2) {
		glEnable(GL_LIGHT1);
	}
	else {
		glDisable(GL_LIGHT1);
	}

	// Door
		room->openDoor();
		glTranslatef(0.0,5.0,0.0);
		glCallList(room->door);
	glPopMatrix();

	//Room
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(0.0,2.0,-2.0);
		glCallList(room->DL);
	glPopMatrix();
	
	//Almirah
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(4.0,-3.0,-19.0);
		glScalef(0.10,0.45,0.1);
		glCallList(almirah->DL);
	glPopMatrix();
	
		almirah->openDoor();
		glTranslatef(4.0,0.0,-25.0);
		glScalef(0.1,0.45,0.9);
		glCallList(almirah->door);
	glPopMatrix();
	
	//Stool
	glPushMatrix();
		glTranslatef(-5.2,-5.0,-20.0);
		glScalef(0.8,0.8,0.8);	
		glRotatef(-90.,1.0,0.0,0.0);
		glCallList(stool->DL);
		glTranslatef(-0.2,4.0,0.0);
		glPushMatrix();
			glTranslatef(-2.0,-4.0,-2.8);
			glCallList(stool->tleg);
		glPopMatrix();	
		
		glPushMatrix();
			glTranslatef(2.0,-4.0,-2.8);
			glCallList(stool->tleg);
		glPopMatrix();	
		
		glPushMatrix();
			glTranslatef(-2.0,-6.0,-2.8);
			glCallList(stool->tleg);
		glPopMatrix();	
		
		glPushMatrix();
			glTranslatef(2.0,-6.0,-2.8);
			glCallList(stool->tleg);
		glPopMatrix();	
	glPopMatrix();

	//Table
	glPushMatrix();
		glTranslatef(-2.2,-3.0,-12.0);
		glCallList(table->DL);
		glPushMatrix();
			glTranslatef(-2.0,-4.0,2.8);
			glRotatef(-90.,1.0,0.0,0.0);
			glCallList(table->tleg);
		glPopMatrix();	
		
		glPushMatrix();
			glTranslatef(-2.0,-4.0,-2.8);
			glRotatef(-90.,1.0,0.0,0.0);
			glCallList(table->tleg);
		glPopMatrix();	
		
		glPushMatrix();
			glTranslatef(2.0,-4.0,2.8);
			glRotatef(-90.,1.0,0.0,0.0);
			glCallList(table->tleg);
		glPopMatrix();	
		
		glPushMatrix();
			glTranslatef(2.0,-4.0,-2.8);
			glRotatef(-90.,1.0,0.0,0.0);
			glCallList(table->tleg);
		glPopMatrix();	
	glPopMatrix();
	
	
	//Chair1
	glPushMatrix();
		glTranslatef(6.2,-3.0,-12.0);
		glRotatef(-90,0,1,0);
		chair->showChair();

	//Chair2
	glPushMatrix();
		glTranslatef(-11.2,-3.0,-12.0);
		glRotatef(90,0,1,0);
		chair->showChair();

	// Lamp 1
	glPushMatrix();
		glTranslatef(0.0,-3.0,-12.0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_dif);
		if (l1) {
			glEnable(GL_LIGHT0);
		}
		else {
			glDisable(GL_LIGHT0);
		}
		glScalef(0.2,0.2,0.2);
		glCallList(lamp1DL); 
	glPopMatrix();	

	// camera animation points (bezier curve control points)
	if (!m) {
		glColor3f(1.0f,0.0f,0.0f);
	    glPointSize(8.0f);
	    glBegin(GL_POINTS);
		for (int i=0;i<curvePointX.size();i++) {
			glVertex3f(curvePointX[i],curvePointY[i],curvePointZ[i]);
		}
		glEnd();	
	}

	// Music Box
	glPushMatrix();
		glScalef(0.5,0.5,0.5);
		glTranslatef(-7.0,-7.1,-24.0);
		glCallList(musicBox->musicBoxBase);
		glPushMatrix();
			glTranslatef(0.0,(musicBox->angle/26.0),0);
			glCallList(musicBox->musicBoxPlatform);	
		glPopMatrix();
			musicBox->openBox();
			glCallList(musicBox->musicBoxTop);
		glPopMatrix();	
	glPopMatrix();

	// Man Dance
	glPushMatrix();
		glTranslatef(-4.2,manPos-1.0,-9.5);
		glScalef(0.20,0.20,0.20);
		human->showBody();
	glPopMatrix();	
	glPointSize(16.0);
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
		glVertex3f(9.0,11.0,-5);
	glEnd();

	// capture frame if recording mode is on
	if (recording) capture_frame(framenum++);

	glutSwapBuffers();
}
/********************************************************************************/

// Main Function
/********************************************************************************/
int main(int argc, char **argv) {

	glutInit(&argc, argv);
	// initializing scene objects
	musicBox = new Box();
	human = new Body();
	room = new Room();
	almirah = new Almirah();
	table = new Table();
	stool = new Stool();
	chair = new Chair();
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("The Devil Dance");
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(mouse);
	glutSpecialFunc(inputKey);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutTimerFunc(1,createMovie,0); // timer function from interpolated frame rendering
	glutReshapeFunc(resize);
	glutMainLoop();
	return 0;

}
/********************************************************************************/

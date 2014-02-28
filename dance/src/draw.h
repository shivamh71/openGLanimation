// File supporting drawing of basic openGL figures

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

GLuint loadBMP_custom(const char * imagepath);

// draws circle with given parameters
void drawCircle(float radius, float cx, float cy, float cz); 

// draws a solid cylinder with given parameters
void solid_cylinder(GLUquadric* QUAD, float BASE, float TOP, float HEIGHT, int SLICES, int STACKS);

// draws a sphere with given parameters
void drawsphere(float radius, GLuint texture);
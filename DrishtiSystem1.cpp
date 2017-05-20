// DrishtiSystem1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <GL/glut.h>
GLfloat a = 0.0, b = 0.0, decPlaneSlide1=35;
int SCENE_NUM = 0;


// Function to Print Text
void printData(int x, int y, float r, float g, float b, char *string)
{
	glColor3f(r, g, b);
	glPointSize(5);
	glRasterPos2f(x, y);
	int len, i;
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

//Function to print the initial pilot text
void PWQ_pilotText() {
	GLfloat title_fade =0;
	//How do I land when I can't see the runway because of the dense fog?
	printData(0, 8, 1, 0, 0, "How do I land when I can't see the runway because of the dense fog?");
	printf("Done 1\n");
}

//Function to update/ move the plane when SCENE_NUM=1
void PWQ_movePlane(int value) {
	a -= 5.0;
	b -= 5.0;
	glutPostRedisplay();
	if (value == 0)
	{
		PWQ_pilotText();

	}
	else
	{
		glutTimerFunc(100, PWQ_movePlane, decPlaneSlide1--);//delay
	}
}

//Function to display the plane
void PWQ_initialPlane() {
	//Aircraft
	glPushMatrix();
	glTranslated(a, b, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(300, 380);//aircraft body
	glVertex2f(450, 400);
	glVertex2f(455, 370);
	glVertex2f(305, 350);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(a, b, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(450, 400);//top part
	glVertex2f(445, 425);
	glVertex2f(435, 424);
	glVertex2f(425, 396);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(a, b, 0.0);
	glBegin(GL_POLYGON);//down wing
	glVertex2f(390, 380);
	glVertex2f(400, 335);
	glVertex2f(380, 333);
	glVertex2f(370, 378);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(a, b, 0.0);
	glBegin(GL_POLYGON);//upper wing
	glVertex2f(390, 391);
	glVertex2f(370, 389);
	glVertex2f(380, 415);
	glVertex2f(400, 417);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(a, b, 0.0);
	glColor3f(0.5, .0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(300, 380);//upper front
	glVertex2f(280, 376);
	glVertex2f(275, 361);
	glVertex2f(302.5, 365);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(a, b, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(302.5, 365);
	glVertex2f(275, 361);
	glVertex2f(285, 346.5);
	glVertex2f(305, 350);
	glEnd();
	glPopMatrix();
}

//Function to display the runway
void PWQ_runway() {
	//Runway track
	glColor3f(1, 1, 1);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(-500, -500);
	glVertex2f(-500, -300);
	glVertex2f(-500, -300);
	glVertex2f(500, -300);
	glEnd();

	//Runway black quad
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-500, -500);
	glVertex2f(-500, -300);
	glVertex2f(500, -300);
	glVertex2f(500, -500);
	glEnd();

	//Runway's partition quads1
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(-490, -420);
	glVertex2f(-490, -380);
	glVertex2f(-440, -380);
	glVertex2f(-440, -420);
	glEnd();

	//Runway's partition quads2
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(-390, -380);
	glVertex2f(-250, -380);
	glVertex2f(-250, -420);
	glVertex2f(-390, -420);
	glEnd();

	//Runway's partition quads3
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(-200, -380);
	glVertex2f(-25, -380);
	glVertex2f(-25, -420);
	glVertex2f(-200, -420);
	glEnd();

	//Runway's partition quads4
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(200, -380);
	glVertex2f(25, -380);
	glVertex2f(25, -420);
	glVertex2f(200, -420);
	glEnd();

	//Runway's partition quads5
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(390, -380);
	glVertex2f(250, -380);
	glVertex2f(250, -420);
	glVertex2f(390, -420);
	glEnd();

	//Runway's partition quads6
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(490, -420);
	glVertex2f(490, -380);
	glVertex2f(440, -380);
	glVertex2f(440, -420);
	glEnd();
}

//Function to display SCENE_NUM=0
void plane_with_question() {
	glClear(GL_COLOR_BUFFER_BIT);
	PWQ_runway();
	PWQ_initialPlane();
}


void displayScene() {
	switch (SCENE_NUM) {

	case 0 : //SCENE 1
		plane_with_question();
	}

	glFlush();
}

void init() {
	glClearColor(1, 1, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Drishti System ");
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(-500, -500);
	glutDisplayFunc(displayScene);
	init();

	//Plane in slide 1
	glutTimerFunc(100, PWQ_movePlane, decPlaneSlide1);
	
	glutMainLoop();
	return 0;
}
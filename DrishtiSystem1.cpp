// DrishtiSystem1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//Aircraft
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(300, 380);//aircraft body
	glVertex2f(450, 400);
	glVertex2f(455, 370);
	glVertex2f(305, 350);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(450, 400);//top part
	glVertex2f(445, 425);
	glVertex2f(435, 424);
	glVertex2f(425, 396);
	glEnd();
	glBegin(GL_POLYGON);//down wing
	glVertex2f(390, 380);
	glVertex2f(400, 335);
	glVertex2f(380, 333);
	glVertex2f(370, 378);
	glEnd();
	glBegin(GL_POLYGON);//upper wing
	glVertex2f(390, 391);
	glVertex2f(370, 389);
	glVertex2f(380, 415);
	glVertex2f(400, 417);
	glEnd();
	glColor3f(0.5, .0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(300, 380);//upper front
	glVertex2f(280, 376);
	glVertex2f(275, 361);
	glVertex2f(302.5, 365);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(302.5, 365);
	glVertex2f(275, 361);
	glVertex2f(285, 346.5);
	glVertex2f(305, 350);
	glEnd();

	glFlush();
}

void init() {
	glClearColor(1, 1, 0.7, 0);
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
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
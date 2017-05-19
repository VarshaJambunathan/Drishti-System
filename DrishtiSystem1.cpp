// DrishtiSystem1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <GL\glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//Control Room
	glColor3f(0, 0, 0);
	glLineWidth(5);
	
	//Outer frame
	glBegin(GL_LINE_LOOP);
	glVertex2f(100,-100);
	glVertex2f(400,-100);
	glVertex2f(400,-490);
	glVertex2f(100, -490);
	glEnd();

	//Computer
	glLineWidth(3);
	glBegin(GL_QUADS);
	glVertex2f(200, -200);
	glVertex2f(300, -200);
	glVertex2f(300, -350);
	glVertex2f(200, -350);
	glEnd();

	//Keyboard
	glBegin(GL_LINE_LOOP);
	glVertex2f(200,-400);
	glVertex2f(220,-450);
	glVertex2f(320,-450);
	glVertex2f(300,-400);
	glEnd();

	//Lines in keyboard
	glBegin(GL_LINES);
	
	//Horizontal
	glVertex2f(210, -400);
	glVertex2f(230, -450);

	glVertex2f(220, -400);
	glVertex2f(240, -450);
	
	glVertex2f(230, -400);
	glVertex2f(250, -450);
	
	glVertex2f(240, -400);
	glVertex2f(260, -450);
	
	glVertex2f(250, -400);
	glVertex2f(270, -450);

	glVertex2f(260, -400);
	glVertex2f(280, -450);

	glVertex2f(270, -400);
	glVertex2f(290, -450);

	glVertex2f(280, -400);
	glVertex2f(300, -450);

	glVertex2f(290, -400);
	glVertex2f(310, -450);

	glVertex2f(300, -400);
	glVertex2f(320, -450);

	//Vertical
	glVertex2f(217, -440);
	glVertex2f(317, -440);

	glVertex2f(213, -430);
	glVertex2f(313, -430);

	glVertex2f(209, -420);
	glVertex2f(309, -420);

	glVertex2f(205, -410);
	glVertex2f(305, -410);

	glEnd();

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
	glutInitWindowPosition(-500,-500);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}

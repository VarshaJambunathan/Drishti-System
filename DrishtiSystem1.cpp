// DrishtiSystem1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <GL\glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Runway track
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-490,-490);
	glVertex2f(490,-490);
	glVertex2f(-490,-300);
	glVertex2f(490,-300);
	glEnd();

	//Runway's partition quads1
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-490,-420);
	glVertex2f(-490,-380);
	glVertex2f(-440, -380);
	glVertex2f(-440, -420);
	glEnd();

	//Runway's partition quads2
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-390,-380);
	glVertex2f(-250,-380);
	glVertex2f(-250,-420);
	glVertex2f(-390,-420);
	glEnd();

	//Runway's partition quads3
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-200, -380);
	glVertex2f(-25, -380);
	glVertex2f(-25, -420);
	glVertex2f(-200, -420);
	glEnd();

	//Runway's partition quads4
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(200, -380);
	glVertex2f(25, -380);
	glVertex2f(25, -420);
	glVertex2f(200, -420);
	glEnd();

	//Runway's partition quads5
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(390, -380);
	glVertex2f(250, -380);
	glVertex2f(250, -420);
	glVertex2f(390, -420);
	glEnd();

	//Runway's partition quads6
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(490, -420);
	glVertex2f(490, -380);
	glVertex2f(440, -380);
	glVertex2f(440, -420);
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

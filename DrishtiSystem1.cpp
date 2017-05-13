// DrishtiSystem1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <GL\glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//Negative sensor
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-480, -400); //LU
	glVertex2f(-480,-440);  //LD
	glVertex2f(-400,-480);  //MD
	glVertex2f(-270,-420);  //RD
	glVertex2f(-270,-380);  //RU
	glVertex2f(-400, -445); //MU
	glVertex2f(-480, -400);  //LU
	glVertex2f(-430, -370);  //LUU
	glEnd();

	//Base middle line
	glBegin(GL_LINES);
	glVertex2f(-400, -480);  //MD
	glVertex2f(-400, -445); //MU
	glEnd();
	
	//Stool Legs
	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(-430, -390); //Left
	glVertex2f(-430, -340);
	glVertex2f(-310, -340);  //Right
	glVertex2f(-310, -390);
	glVertex2f(-380, -420); //Middle
	glVertex2f(-380, -380);
	glEnd();

	//Stool Base

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

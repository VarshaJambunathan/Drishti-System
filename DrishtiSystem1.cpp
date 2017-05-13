// DrishtiSystem1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <GL\glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//Positive sensor

	//Outer boundary
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2f(373,170);
	glVertex2f(410, 170);
	glVertex2f(450,50);
	glVertex2f(250,50);
	glVertex2f(290, 170);
	glVertex2f(316, 170);
	glEnd();

	//Inner boundary
	glBegin(GL_LINE_STRIP);
	glVertex2f(380,140);
	glVertex2f(400,140);
	glVertex2f(420, 80);
	glVertex2f(280, 80);
	glVertex2f(300, 140);
	glVertex2f(312,140);
	glEnd();

	//Left upward sensor
	glBegin(GL_LINES);
	glVertex2f(310, 120);
	glVertex2f(330, 300);
	glVertex2f(380, 120);
	glVertex2f(360,300);
	glEnd();

	//Uppper square
	glBegin(GL_POLYGON);
	glVertex2f(310, 300);
	glVertex2f(310, 350);
	glVertex2f(380, 350);
	glVertex2f(380, 300);
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

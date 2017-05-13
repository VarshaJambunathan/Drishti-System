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
	glVertex2f(-270, -380);  //RU
	glVertex2f(-310, -355);  //RLegs
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
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-410, -300);  //LM
	glVertex2f(-430, -340); //L
	glVertex2f(-380, -380); //M
	glVertex2f(-310, -340);  //R
	glVertex2f(-330, -300);  //RM
	glEnd();

	//Block on Stool
	glBegin(GL_LINE_LOOP);
	glVertex2f(-410, -230);
	glVertex2f(-410, -300);  //LM
	glVertex2f(-330, -300);  //RM
	glVertex2f(-330,-200);
	glVertex2f(-350, -210); //down FOR BOX
	glVertex2f(-410, -210);
	glVertex2f(-410, -230);

	glEnd();

	//Upper box
	glBegin(GL_LINE_LOOP);
	glVertex2f(-414, -210);//DL
	glVertex2f(-414, -35); //UL
	glVertex2f(-350, -35); //ML
	glVertex2f(-330, -25); //UR
	glVertex2f(-330, -200); //DR
	glVertex2f(-350, -210); //down FOR BOX
	glEnd();

	glBegin(GL_LINES);
	
	glVertex2f(-350, -210); //down FOR BOX
	glVertex2f(-350, -35);
	glVertex2f(-412, -35); //UL
	glVertex2f(-395, -25); //Back of box
	glVertex2f(-395, -25); //Back of box
	glVertex2f(-330, -25); //UR
	glEnd();

	//Knob
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2f(-402,-125);
	glEnd();

	//Sensor neck
	glBegin(GL_LINES);
	glVertex2f(-370, -25); //Back of box
	glVertex2f(-370, 175); //Back of box
	glVertex2f(-365, -25); //Back of box
	glVertex2f(-365, 175); //Back of box
	glVertex2f(-355, -25); //Back of box
	glVertex2f(-355, 175); //Back of box

	glEnd();
	//Sensor Head
	glBegin(GL_LINE_LOOP);
	glVertex2f(-370, 175); //Back of box
	glVertex2f(-365, 175); //Back of box
	glVertex2f(-355, 175); //Back of box
	glVertex2f(-340, 175); //Back of box
	glVertex2f(-340, 200); //Back of box
	glVertex2f(-355, 200); //Back of box
	glVertex2f(-365, 200); //Back of box
	glVertex2f(-370, 200); //Back of box
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

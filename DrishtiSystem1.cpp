// DrishtiSystem1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <GL/glut.h>
GLfloat a = 0.0, b = 0.0, decPlaneSlide1=35;
int SCENE_NUM = 0;
float m = 0.0, l = 0.0, i = 0.0;

void FP_tyres();

// Function to Print Text
void drawStrokeText(char*string, int x, int y, int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x, y + 8, z);
	// glScalef(0.09f,-0.08f,z);

	for (c = string; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}

void draw_pixel(GLint cx, GLint cy)
{
	glBegin(GL_POINTS);
	glVertex2i(cx, cy);
	glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d = 1 - r, x = 0, y = r;
	while (y>x)
	{
		plotpixels(h, k, x, y);
		if (d<0) d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}

//Function to print the initial pilot text
void PWQ_pilotText() {

	glColor3f(0, 1, 0);
	//How do I land when I can't see the runway because of the dense fog?
	drawStrokeText("How do I land when I can't see the runway because of the dense fog?",0,0,1);
	printf("Done 1\n");
}

//Function to update/ move the plane when SCENE_NUM=1
void update(int value) {
		//decPlaneSlide1--;
		a -= 5.0;
		b -= 5.0;
		//if (decPlaneSlide1 == 0)
		{
			PWQ_pilotText();
		}
		if (a == -50 && b == -50)
		{
			FP_tyres();
			printf("Printed tyres");
		}
		//else
		{
			glutTimerFunc(100, update, 0);//delay
		}
		
	glutPostRedisplay();
}

//Function to display the plane
void PWQ_initialPlane() {
	//Aircraft
	glColor3f(0.0, 0.0, 0.0);
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

void PWQ_clouds() {
	//cloud1

	glColor3f(0.753, 0.753, 0.753);//code for clouds
	for (l = 0; l <= 20; l++)
	{
		glColor3f(0, 1.0, 1.0);
		draw_circle(160 + m, 325, l);
	}
	for (l = 0; l <= 35; l++)
	{
		glColor3f(0, 1.0, 1.0);
		draw_circle(200 + m, 325, l);
		draw_circle(225 + m, 325, l);
	}
	for (l = 0; l <= 20; l++)
	{
		glColor3f(0, 1.0, 1.0);
		draw_circle(265 + m, 325, l);
	}

	//cloud2
	glColor3f(0.753, 0.753, 0.753);//code for clouds
	for (l = 0; l <= 20; l++)
	{
		glColor3f(1.0, 1.0, 1.0);
		draw_circle(370 + m, 615, l);
	}
	for (l = 0; l <= 35; l++)
	{
		glColor3f(1.0, 1.0, 1.0);
		draw_circle(410 + m, 615, l);
		draw_circle(435 + m, 615, l);
		draw_circle(470 + m, 615, l);
	}
	for (l = 0; l <= 20; l++)
	{
		glColor3f(1.0, 1.0, 1.0);
		draw_circle(500 + m, 615, l);
	}
}

//Function to display SCENE_NUM=0
void plane_with_question() {
	glClear(GL_COLOR_BUFFER_BIT);

	PWQ_runway();
	PWQ_clouds();

	glPushMatrix();
	glTranslated(a, b, 0.0);
	PWQ_initialPlane();
	glPopMatrix();

	FP_tyres();
}

void SO_positiveSensor() {
	//Positive sensor

	//Outer boundary
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2f(373, 170);
	glVertex2f(410, 170);
	glVertex2f(450, 50);
	glVertex2f(250, 50);
	glVertex2f(290, 170);
	glVertex2f(316, 170);
	glEnd();

	//Inner boundary
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(380, 140);
	glVertex2f(400, 140);
	glVertex2f(420, 80);
	glVertex2f(280, 80);
	glVertex2f(300, 140);
	glVertex2f(312, 140);
	glEnd();

	//Left upward sensor
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(310, 120);
	glVertex2f(330, 300);
	glVertex2f(360, 300);
	glVertex2f(380, 120);

	glEnd();

	//Uppper square
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(320, 300);
	glVertex2f(320, 350);
	glVertex2f(370, 350);
	glVertex2f(370, 300);
	glEnd();
}

void SO_lightEmit() {
	glColor3f(0, 0, 0);
	glLineWidth(1);

	glBegin(GL_LINES);
	//Upper line
	glVertex2f(320, 350);
	glVertex2f(0, 400);

	//Lower line
	glVertex2f(320, 300);
	glVertex2f(-10, 250);
	glEnd();

	//Square for emmitting light
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_QUADS);
	glVertex2f(250, 350);
	glVertex2f(200, 350);
	glVertex2f(200, 300);
	glVertex2f(250, 300);
	glEnd();
}

void SO_negativeSensor() {
	//Negative sensor
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-480, -400); //LU
	glVertex2f(-480, -440);  //LD
	glVertex2f(-400, -480);  //MD
	glVertex2f(-270, -420);  //RD
	glVertex2f(-270, -380);  //RU
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
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-410, -300);  //LM
	glVertex2f(-430, -340); //L
	glVertex2f(-380, -380); //M
	glVertex2f(-310, -340);  //R
	glVertex2f(-330, -300);  //RM
	glEnd();

	//Block on Stool
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-410, -230);
	glVertex2f(-410, -300);  //LM
	glVertex2f(-330, -300);  //RM
	glVertex2f(-330, -200);
	glVertex2f(-350, -210); //down FOR BOX
	glVertex2f(-410, -210);
	glVertex2f(-410, -230);

	glEnd();

	//Upper box
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-414, -210);//DL
	glVertex2f(-414, -35); //UL
	glVertex2f(-350, -35); //ML
	glVertex2f(-330, -25); //UR
	glVertex2f(-330, -200); //DR
	glVertex2f(-350, -210); //down FOR BOX
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
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
	glVertex2f(-402, -125);
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
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-370, 175); //Back of box
	glVertex2f(-365, 175); //Back of box
	glVertex2f(-355, 175); //Back of box
	glVertex2f(-340, 175); //Back of box
	glVertex2f(-340, 200); //Back of box
	glVertex2f(-355, 200); //Back of box
	glVertex2f(-365, 200); //Back of box
	glVertex2f(-370, 200); //Back of box
	glEnd();
}

void SO_lightResult() {
	//Square for resulting light data
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(-225, 250);
	glVertex2f(-190, 250);
	glVertex2f(-190, 310);
	glVertex2f(-225, 310);
	glEnd();

	//Data lines
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(-195, 262);
	glVertex2f(-220, 262);

	glVertex2f(-195, 272);
	glVertex2f(-220, 272);

	glVertex2f(-195, 282);
	glVertex2f(-220, 282);

	glVertex2f(-195, 292);
	glVertex2f(-220, 292);

	glVertex2f(-195, 302);
	glVertex2f(-220, 302);

	glEnd();
}

void sensors_only() {
	glClear(GL_COLOR_BUFFER_BIT);
	SO_positiveSensor();
	SO_negativeSensor();
	SO_lightEmit();
	SO_lightResult();
}

void SCR_positiveSensor() {
	//Positive sensor

	//Outer boundary
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2f(373, 170);
	glVertex2f(410, 170);
	glVertex2f(450, 50);
	glVertex2f(250, 50);
	glVertex2f(290, 170);
	glVertex2f(316, 170);
	glEnd();

	//Inner boundary
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(380, 140);
	glVertex2f(400, 140);
	glVertex2f(420, 80);
	glVertex2f(280, 80);
	glVertex2f(300, 140);
	glVertex2f(312, 140);
	glEnd();

	//Left upward sensor
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(310, 120);
	glVertex2f(330, 300);
	glVertex2f(360, 300);
	glVertex2f(380, 120);

	glEnd();

	//Uppper square
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(320, 300);
	glVertex2f(320, 350);
	glVertex2f(370, 350);
	glVertex2f(370, 300);
	glEnd();

}
void SCR_negativeSensor() {
	//Negative sensor
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-480, -400); //LU
	glVertex2f(-480, -440);  //LD
	glVertex2f(-400, -480);  //MD
	glVertex2f(-270, -420);  //RD
	glVertex2f(-270, -380);  //RU
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
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-410, -300);  //LM
	glVertex2f(-430, -340); //L
	glVertex2f(-380, -380); //M
	glVertex2f(-310, -340);  //R
	glVertex2f(-330, -300);  //RM
	glEnd();

	//Block on Stool
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-410, -230);
	glVertex2f(-410, -300);  //LM
	glVertex2f(-330, -300);  //RM
	glVertex2f(-330, -200);
	glVertex2f(-350, -210); //down FOR BOX
	glVertex2f(-410, -210);
	glVertex2f(-410, -230);

	glEnd();

	//Upper box
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-414, -210);//DL
	glVertex2f(-414, -35); //UL
	glVertex2f(-350, -35); //ML
	glVertex2f(-330, -25); //UR
	glVertex2f(-330, -200); //DR
	glVertex2f(-350, -210); //down FOR BOX
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
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
	glVertex2f(-402, -125);
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
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-370, 175); //Back of box
	glVertex2f(-365, 175); //Back of box
	glVertex2f(-355, 175); //Back of box
	glVertex2f(-340, 175); //Back of box
	glVertex2f(-340, 200); //Back of box
	glVertex2f(-355, 200); //Back of box
	glVertex2f(-365, 200); //Back of box
	glVertex2f(-370, 200); //Back of box
	glEnd();
}

void SCR_computer() {
	//Control Room
	glColor3f(0, 0, 0);
	glLineWidth(5);

	//Outer frame
	glBegin(GL_LINE_LOOP);
	glVertex2f(100, -100);
	glVertex2f(400, -100);
	glVertex2f(400, -490);
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
	glVertex2f(200, -400);
	glVertex2f(220, -450);
	glVertex2f(320, -450);
	glVertex2f(300, -400);
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
}

void SCR_mailbox() {
	//Mailbox
	glColor3f(0.0, 0.0, 1.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);  // Square
	glVertex2f(-250,-230);
	glVertex2f(-250, -170);
	glVertex2f(-210, -170);
	glVertex2f(-210, -230);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);    //Envelope edge
	glVertex2f(-250,-170);
	glVertex2f(-230,-200);
	glVertex2f(-210,-170);
	glEnd();
}

void FP_tyres() {
	//Tyres
	
	for (l = 0; l<10; l++)//first tyre
	{
		glColor3f(1.0, 0.0, 0.0);
		draw_circle(-150, -200, l);
	}
	for (l = 0; l<10; l++)//second tyre
	{
		glColor3f(1.0, 0.0, 0.0);
		draw_circle(-250, -200, l);
	}
}

void sensor_with_control_room() {
	glClear(GL_COLOR_BUFFER_BIT);
	//SCR_positiveSensor();
	SCR_negativeSensor();
	SCR_computer();
	PWQ_initialPlane();
	SCR_mailbox();
}

void INIT_printNames() {
	glColor3f(0, 1, 0);
	drawStrokeText("Drishti", 20, 20, 0);
}

void INIT_printKeys() {

}

void about_us() {
	glClear(GL_COLOR_BUFFER_BIT);
	INIT_printNames();
	INIT_printKeys();
}

void final_plane() {
	glClear(GL_COLOR_BUFFER_BIT);
	PWQ_initialPlane();
	FP_tyres();
	PWQ_runway();
}


void displayScene() {
	switch (SCENE_NUM) {

	case 0: //SCENE 0
		about_us();
		break;

	case 1 : //SCENE 1
		plane_with_question();
		break;
		
	case 2: //SCENE 3
		sensors_only();
		break;

	case 3: //SCENE 3
		sensor_with_control_room();
		break;

	case 4: //SCENE 4
		final_plane();
		break;

	}
	
	glFlush();
}

// Keyboard Action
void keyPress(unsigned char key, int x, int y) {
	switch (key) {
		// Go to Previous Scene
	case 'b':
	case 'B':
		if (SCENE_NUM == 0)
			break;
		SCENE_NUM--;
		break;
		// Go to Next Scene
	case 'n':
	case 'N':
		if (SCENE_NUM == 15)
			break;
		SCENE_NUM++;
		break;
		// Quit Story
	case 'q':
	case 'Q':
		exit(0);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}


void init() {
	glClearColor(0.9,0, 0.9, 0);
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
	glutKeyboardFunc(keyPress);
	init();
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;
}
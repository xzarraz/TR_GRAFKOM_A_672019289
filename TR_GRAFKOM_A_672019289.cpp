#include <iostream>

#include <GL/freeglut.h>

#include <time.h> 
#include <cmath>

#include "objectDrawer.h";
#include "colorOption.h";
#include "myConfiguration.h";

using namespace std;

myConfiguration config;
myColor color;
myObject obj;

void reshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, width / height, 5.0, 1000.0);
	glTranslatef(-25.0, -150.0, -500.0);
	glScalef(0.15, 0.15, 0.15);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, config.width, config.height);
}

void timer(int) {
	glutTimerFunc(1000 / 30, timer, 0);
	glutPostRedisplay();

}

void display() {
	if (config.nightMode) {
		glClearColor(0, 0, 0, 1.0);
	}
	else {
		glClearColor(0.93, 0.86, 0.64, 1.0);
	}

	if (config.manualLighting) {
		GLfloat position[] = { config.mouseX, config.mouseY, config.mouseZ, 1 };
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	obj.drawBuilding();

	obj.myTree(300.0, 340);
	obj.myTree(150.0, 340);
	obj.myTree(0.0, 340);
	obj.myTree(-150.0, 340);
	obj.myTree(-300.0, 340);
	obj.myTree(-450.0, 340);
	obj.myTree(-600.0, 340);
	obj.myTree(-750.0, 340);
	obj.myTree(-900.0, 340);
	obj.myTree(300.0, 580);
	obj.myTree(150.0, 580);
	obj.myTree(0.0, 580);
	obj.myTree(-150.0, 580);
	obj.myTree(-300.0, 580);
	obj.myTree(-450.0, 580);
	obj.myTree(-600.0, 580);
	obj.myTree(-750.0, 580);
	obj.myTree(300.0, -900);
	obj.myTree(150.0, -900);
	obj.myTree(0.0, -900);
	obj.myTree(-150.0, -900);
	obj.myTree(-300.0, -900);
	obj.myTree(-450.0, -900);
	obj.myTree(-600.0, -900);
	obj.myTree(-750.0, -900);
	obj.myTree(-900.0, -900);

	obj.street();

	obj.carObject(carPositionX[0], carPositionZ[0], carColor[0]);
	obj.carObject(carPositionX[1], carPositionZ[1], carColor[1]);
	obj.carObject(carPositionX[2], carPositionZ[2], carColor[2]);
	obj.carObject(carPositionX[3], carPositionZ[3], carColor[3]);
	obj.carObject(carPositionX[4], carPositionZ[4], carColor[4]);


	obj.drawBuildingBase();
	glDisable(GL_COLOR_MATERIAL);

	glPopMatrix();

	glutSwapBuffers();
}

// Action Controller

void keyFun(unsigned char key, int x, int y) {
	switch (key) {
		// Right - Left
	case 'a':
		glRotatef(-5.0, 0.0, 1.0, 0.0);
		break;
	case 'd':
		glRotatef(5.0, 0.0, 1.0, 0.0);
		break;

		// Up - Down
	case 'w':
		glRotatef(-5.0, 1.0, 0.0, 0.0);
		break;
	case 's':
		glRotatef(5.0, 1.0, 0.0, 0.0);
		break;

		// Rotate - Z
	case 'q':
		glRotatef(5.0, 0.0, 0.0, 1.0);
		break;
	case 'e':
		glRotatef(-5.0, 0.0, 0.0, 1.0);
		break;
		// moving z point
	case 't':
		config.mouseZ += 100.0f;
		break;
	case 'y':
		config.mouseZ -= 100.0f;
		break;
		// Zoom In - Out
	case '1':
		glScalef(1.025, 1.025, 1.025);
		break;
	case '2':
		glScalef(0.975, 0.975, 0.975);
		break;
	}
	glutPostRedisplay();
}

void keySpecialFun(int key, int x, int y) {
	switch (key) {
		// Left
	case 100:
		glTranslatef(-5.0, 0.0, 0.0);
		break;
		// Up
	case 101:
		glTranslatef(0.0, 5.0, 0.0);
		break;
		// Right
	case 102:
		glTranslatef(5.0, 0.0, 0.0);
		break;
		// Down
	case 103:
		glTranslatef(0.0, -5.0, 0.0);
		break;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		config.mouseDown = true;
		config.xdiff = (x + config.xrot);
		config.ydiff = (-y + config.yrot);
	}
	else {
		config.mouseDown = false;
	}
}

void mouseMotion(int x, int y) {
	if (config.mouseDown)
	{
		config.xrot = (y + config.ydiff) / 150;
		config.yrot = (x - config.xdiff) / 150;

		glutPostRedisplay();

		glRotatef(config.xrot, 1.0f, 0.0f, 0.0f);
		glRotatef(config.yrot, 0.0f, 1.0f, 0.0f);
	}


}

void mouseWheel(int button, int dir, int x, int y) {

	if (dir > 0) {
		glScalef(1.025, 1.025, 1.025);
	}
	else {
		glScalef(0.975, 0.975, 0.975);
	}
	glutPostRedisplay();

}

void mouseMotionActive(int x, int y) {
	config.mouseX = x;
	config.mouseY = y;

	glutPostRedisplay();
}

// Inisialisasi

void myinit() {
	glPointSize(10.0);
	glLineWidth(2.5);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_NORMALIZE);

	glLightfv(GL_LIGHT0, GL_AMBIENT, config.ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, config.diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, config.specularLight);
	glLightfv(GL_LIGHT0, GL_EMISSION, config.emission);
	glLightfv(GL_LIGHT0, GL_POSITION, config.position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(config.width, config.height);
	glutInitWindowPosition(config.windowPositionX, config.windowPositionY);
	glutCreateWindow("TR - Grafkom Asdos");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyFun);
	glutSpecialFunc(keySpecialFun);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutTimerFunc(0, timer, 0);
	glutMouseWheelFunc(mouseWheel);
	glutPassiveMotionFunc(mouseMotionActive);

	myinit();
	glutMainLoop();

	return 0;
}

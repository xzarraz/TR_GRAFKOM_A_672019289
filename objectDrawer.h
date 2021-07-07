#pragma once

#include "colorOption.h";
#include "myConfiguration.h";

#define deltat .001

GLuint _textureID;

bool sunlightAutoMovement = false;
float sunlightPosition = 0;

bool redOn = true;
bool yellowOn = false;
bool greenOn = false;

float redLight = 1000, yellowLight = 0, greenLight = 0;

float carSpeed[5] = { 3, 3, 3, 3, 3 };
float carPositionX[5] = { 0, 300, 600, 600, 1200 };
float carPositionZ[5] = { 400, 475, 400, 475, 400 };
float carColor[5] = { 1 , 1 , 3, 4, 4 };
float deltaCar[5] = { 0,0,0,0,0 };

class myObject {

public:
	myColor color;
	myConfiguration config;

	void drawBuildingBase() {
		glColor3ubv(color.groundAccent);
		//Depan
		glBegin(GL_POLYGON);
		glVertex3f(-900.0, 0.0, 600.0);
		glVertex3f(400.0, 0.0, 600.0);
		glVertex3f(400.0, 50.0, 600.0);
		glVertex3f(-900.0, 50.0, 600.0);
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-825.0, 0.0, -1000.0);
		glVertex3f(400.0, 0.0, -1000.0);
		glVertex3f(400.0, 50.0, -1000.0);
		glVertex3f(-825.0, 50.0, -1000.0);
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(400.0, 0.0, -1000.0);
		glVertex3f(400.0, 0.0, 600.0);
		glVertex3f(400.0, 50.0, 600.0);
		glVertex3f(400.0, 50.0, -1000.0);
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-900.0, 0.0, 600.0);
		glVertex3f(-1125.0, 0.0, -1000.0);
		glVertex3f(-1125.0, 50.0, -1000.0);
		glVertex3f(-900.0, 50.0, 600.0);
		glEnd();

		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(-900.0, 0.0, 600.0);
		glVertex3f(400.0, 0.0, 600.0);
		glVertex3f(400.0, 0.0, -1000.0);
		glVertex3f(-1125.0, 0.0, -1000.0);
		glEnd();

		//atas
		glBegin(GL_POLYGON);
		glColor3f(0.05, 0.63, 0);
		glVertex3f(-900.0, 50.0, 600.0);
		glVertex3f(400.0, 50.0, 600.0);
		glVertex3f(400.0, 50.0, -1000.0);
		glVertex3f(-1125.0, 50.0, -1000.0);
		glEnd();

	}



	void drawBuilding() {

		glColor3fv(color.lightGrey);

		//bawah
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -750.0);
		glVertex3f(-500.0, 55.0, -750.0);
		glVertex3f(-500.0, 55.0, -600.0);
		glVertex3f(-25.0, 55.0, -600.0);
		glEnd();

		//depan
		glBegin(GL_POLYGON);
		glVertex3f(-500.0, 55.0, 100.0);
		glVertex3f(-25.0, 55.0, 100.0);
		glVertex3f(-25.0, 350.0, 100.0);
		glVertex3f(-500.0, 350.0, 100.0);
		glEnd();

		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -750.0);
		glVertex3f(-500.0, 55.0, -750.0);
		glVertex3f(-500.0, 350.0, -750.0);
		glVertex3f(-25.0, 350.0, -750.0);
		glEnd();

		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 55.0, -750.0);
		glVertex3f(-25.0, 55.0, 100.0);
		glVertex3f(-25.0, 350.0, 100.0);
		glVertex3f(-25.0, 350.0, -750.0);
		glEnd();

		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-500.0, 55.0, -750.0);
		glVertex3f(-500.0, 55.0, 100.0);
		glVertex3f(-500.0, 350.0, 100.0);
		glVertex3f(-500.0, 350.0, -750.0);
		glEnd();

		glColor3f(0.9, 0.9, 0.9);
		//atas
		glBegin(GL_POLYGON);
		glVertex3f(-25.0, 350.0, -750.0);
		glVertex3f(-500.0, 350.0, -750.0);
		glVertex3f(-500.0, 350.0, 100.0);
		glVertex3f(-25.0, 350.0, 100.0);
		glEnd();

		//detail
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(-450.0, 100.0, -399.5);
		glVertex3f(-50.0, 100.0, -399.5);
		glVertex3f(-50.0, 300.0, -399.5);
		glVertex3f(-450.0, 300.0, -399.5);
		glEnd();

		glColor3fv(color.lightGrey);
		float spacing = -400.0;
		float spacingB = -350.0;
		for (int i = 0; i < 5; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(spacing, 75.0, 100.3);//jendela depan
			glVertex3f(spacingB, 75.0, 100.3);
			glVertex3f(spacingB, 350.0, 100.3);
			glVertex3f(spacing, 350.0, 100.3);
			glEnd();

			spacing += 65.0;
			spacingB += 65.0;
		}

		float spacingC = 300.0;
		float spacingD = 325.0;
		for (int i = 0; i < 3; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-500.0, spacingC, 100.1);
			glVertex3f(-500.0, spacingC, 100.1);
			glVertex3f(-500.0, spacingD, 100.1);
			glVertex3f(-500.0, spacingD, 100.1);
			glEnd();


			spacingC -= 75.0;
			spacingD -= 75.0;
		}

		glColor3fv(color.glass);
		float spacingE = 275.0;
		float spacingF = 300.0;
		for (int i = 0; i < 5; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-500.5, spacingE, 100.0);//jendela kanan
			glVertex3f(-500.5, spacingE, -750.0);
			glVertex3f(-500.5, spacingF, -750.0);
			glVertex3f(-500.5, spacingF, 100.0);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-500.0, spacingE, 100.1);//jendela depan
			glVertex3f(-25.0, spacingE, 100.1);
			glVertex3f(-25.0, spacingF, 100.1);
			glVertex3f(-500.0, spacingF, 100.1);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-24.5, spacingE, 100.0);
			glVertex3f(-24.5, spacingE, -750.0);//jendela kiri 
			glVertex3f(-24.5, spacingF, -750.0);
			glVertex3f(-24.5, spacingF, 100.0);
			glEnd();

			spacingE -= 50.0;
			spacingF -= 50.0;
		}

		glColor3fv(color.darkGrey);
		float spacingG = 310.0;
		float spacingH = 300.0;
		for (int i = 0; i < 5; i++) {
			glBegin(GL_POLYGON);
			glVertex3f(-375.0, spacingG, -750.5);
			glVertex3f(-425.0, spacingG, -750.5);
			glVertex3f(-425.0, spacingH, -750.5);
			glVertex3f(-375.0, spacingH, -750.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-275.0, spacingG, -750.5);
			glVertex3f(-325.0, spacingG, -750.5);
			glVertex3f(-325.0, spacingH, -750.5);
			glVertex3f(-275.0, spacingH, -750.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-175.0, spacingG, -750.5);
			glVertex3f(-225.0, spacingG, -750.5);
			glVertex3f(-225.0, spacingH, -750.5);
			glVertex3f(-175.0, spacingH, -750.5);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-75.0, spacingG, -750.5);
			glVertex3f(-125.0, spacingG, -750.5);
			glVertex3f(-125.0, spacingH, -750.5);
			glVertex3f(-75.0, spacingH, -750.5);
			glEnd();

			spacingG -= 50.0;
			spacingH -= 50.0;
		}

		//detail atas
		glColor3fv(color.grey);
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 350.5, 50.0);
		glVertex3f(-450.0, 350.5, 50.0);
		glVertex3f(-450.0, 350.5, -450.0);
		glVertex3f(-400.0, 350.5, -450.0);
		glEnd();
		glColor3fv(color.lightGrey);
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 350.5, -700.0);
		glVertex3f(-450.0, 350.5, -700.0);
		glVertex3f(-450.0, 360.5, -700.0);
		glVertex3f(-400.0, 360.5, -700.0);
		glEnd();
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(-450.0, 350.5, -450.0);
		glVertex3f(-400.0, 350.5, -450.0);
		glVertex3f(-400.0, 360.5, -450.0);
		glVertex3f(-450.0, 360.5, -450.0);
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-450.0, 350.5, -700.0);
		glVertex3f(-450.0, 350.5, -450.0);
		glVertex3f(-450.0, 360.5, -450.0);
		glVertex3f(-450.0, 360.5, -700.0);
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 350.5, -700.0);
		glVertex3f(-400.0, 350.5, -450.0);
		glVertex3f(-400.0, 360.5, -450.0);
		glVertex3f(-400.0, 360.5, -700.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-400.0, 360.5, -700.0);
		glVertex3f(-450.0, 360.5, -700.0);
		glVertex3f(-450.0, 360.5, -450.0);
		glVertex3f(-400.0, 360.5, -450.0);
		glEnd();

		glColor3fv(color.grey);
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 350.5, -550.0);
		glVertex3f(-350.0, 350.5, -550.0);
		glVertex3f(-350.0, 350.5, -450.0);
		glVertex3f(-300.0, 350.5, -450.0);
		glEnd();
		glColor3fv(color.lightGrey);
		//belakang
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 350.5, -550.0);
		glVertex3f(-350.0, 350.5, -550.0);
		glVertex3f(-350.0, 360.5, -550.0);
		glVertex3f(-300.0, 360.5, -550.0);
		glEnd();
		//depan
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 350.5, -450.0);
		glVertex3f(-300.0, 350.5, -450.0);
		glVertex3f(-300.0, 360.5, -450.0);
		glVertex3f(-350.0, 360.5, -450.0);
		glEnd();
		//kiri
		glBegin(GL_POLYGON);
		glVertex3f(-350.0, 350.5, -550.0);
		glVertex3f(-350.0, 350.5, -450.0);
		glVertex3f(-350.0, 360.5, -450.0);
		glVertex3f(-350.0, 360.5, -550.0);
		glEnd();
		//kanan
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 350.5, -550.0);
		glVertex3f(-300.0, 350.5, -450.0);
		glVertex3f(-300.0, 360.5, -450.0);
		glVertex3f(-300.0, 360.5, -550.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(-300.0, 360.5, -550.0);
		glVertex3f(-350.0, 360.5, -550.0);
		glVertex3f(-350.0, 360.5, -450.0);
		glVertex3f(-300.0, 360.5, -450.0);
		glEnd();

	}



	void myTree(float startPoint, float zPoint) {
		// Batang
		glColor3ub(139, 69, 19);
		glBegin(GL_QUADS);
		glVertex3f(startPoint, 55, zPoint);
		glVertex3f(startPoint - 10, 55, zPoint);
		glVertex3f(startPoint - 10, 120, zPoint);
		glVertex3f(startPoint, 120, zPoint);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(startPoint, 55, zPoint - 10);
		glVertex3f(startPoint - 10, 55, zPoint - 10);
		glVertex3f(startPoint - 10, 120, zPoint - 10);
		glVertex3f(startPoint, 120, zPoint - 10);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(startPoint - 10, 55, zPoint - 10);
		glVertex3f(startPoint - 10, 55, zPoint);
		glVertex3f(startPoint - 10, 120, zPoint);
		glVertex3f(startPoint - 10, 120, zPoint - 10);
		glEnd();
		glBegin(GL_QUADS);
		glVertex3f(startPoint, 55, zPoint - 10);
		glVertex3f(startPoint, 55, zPoint);
		glVertex3f(startPoint, 120, zPoint);
		glVertex3f(startPoint, 120, zPoint - 10);
		glEnd();

		// daun
		glColor3ub(19, 51, 17);
		glBegin(GL_QUADS);
		glVertex3f(startPoint - 20, 90, zPoint + 40);
		glVertex3f(startPoint + 20, 90, zPoint + 40);
		glVertex3f(startPoint + 20, 90, zPoint - 40);
		glVertex3f(startPoint - 20, 90, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(startPoint - 20 , 180, zPoint + 40);
		glVertex3f(startPoint + 20 , 180, zPoint + 40);
		glVertex3f(startPoint + 20 , 180, zPoint - 40);
		glVertex3f(startPoint - 20 , 180, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(27, 78, 24);
		glVertex3f(startPoint - 20, 90, zPoint + 40);
		glColor3ub(19, 51, 17);
		glVertex3f(startPoint - 20 , 180, zPoint + 40);
		glVertex3f(startPoint - 20 , 180, zPoint - 40);
		glVertex3f(startPoint - 20, 90, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(startPoint + 20, 90, zPoint + 40);
		glVertex3f(startPoint + 20 , 180, zPoint + 40);
		glVertex3f(startPoint + 20 , 180, zPoint - 40);
		glVertex3f(startPoint + 20, 90, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(startPoint - 20, 90, zPoint - 40);
		glVertex3f(startPoint + 20, 90, zPoint - 40);
		glVertex3f(startPoint + 20 , 180, zPoint - 40);
		glVertex3f(startPoint - 20 , 180, zPoint - 40);
		glEnd();

		glBegin(GL_QUADS);
		glColor3ub(27, 78, 24);
		glVertex3f(startPoint - 20, 90, zPoint + 40);
		glColor3ub(19, 51, 17);
		glVertex3f(startPoint + 20, 90, zPoint + 40);
		glVertex3f(startPoint + 20 , 180, zPoint + 40);
		glVertex3f(startPoint - 20 , 180, zPoint + 40);
		glEnd();
	}

	void street() {

		glBegin(GL_QUADS);
		glColor3ubv(color.street);
		glVertex3f(-930.0, 55.0, 360.0);
		glColor3ubv(color.street);
		glVertex3f(400.0, 55.0, 400.0);
		glColor3ubv(color.street);
		glVertex3f(400.0, 55.0, 520.0);
		glColor3ubv(color.street);
		glVertex3f(-920.0, 55.0, 480.0);
		glEnd();
	}



	void carObject(float xCoord, float zCoord, int colorOption) {

		//bawah
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 55.5, zCoord);
		glVertex3f(xCoord, 55.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 55.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 55.5, zCoord);
		glEnd();

		//depan-mobil
		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 55.5, zCoord);
		glVertex3f(xCoord, 55.5, zCoord + 25.0);
		glVertex3f(xCoord, 65.5, zCoord + 25.0);
		glVertex3f(xCoord, 65.5, zCoord);
		glEnd();

		//blkg-mobil
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 35.0, 55.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 55.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord + 25.0);
		glEnd();

		if (colorOption == 1)
			glColor3fv(color.orange);

		if (colorOption == 2)
			glColor3fv(color.white);

		if (colorOption == 3)
			glColor3fv(color.darkGrey);

		if (colorOption == 4)
			glColor3ubv(color.darkBlue);

		if (colorOption == 5)
			glColor3fv(color.grey);

		if (colorOption == 6)
			glColor3fv(color.glass);

		if (colorOption == 7)
			glColor3fv(color.yellow);

		if (colorOption == 8)
			glColor3fv(color.red);

		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 65.5, zCoord + 25.0);
		glVertex3f(xCoord, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord + 25.0);
		glEnd();

		//samping-mobil
		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 65.5, zCoord);
		glVertex3f(xCoord + 35.0, 55.5, zCoord);
		glVertex3f(xCoord, 55.5, zCoord);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(xCoord, 65.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 65.5, zCoord + 25.0);
		glVertex3f(xCoord + 35.0, 55.5, zCoord + 25.0);
		glVertex3f(xCoord, 55.5, zCoord + 25.0);
		glEnd();

		//kaca
		glColor3fv(color.white);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 7.5, 65.7, zCoord);
		glVertex3f(xCoord + 7.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 27.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 27.5, 65.7, zCoord);
		glEnd();
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 7.5, 65.7, zCoord);
		glVertex3f(xCoord + 7.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 10.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 10.0, 75.7, zCoord);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 27.5, 65.7, zCoord);
		glVertex3f(xCoord + 27.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord);
		glEnd();
		glColor3fv(color.white);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 10.0, 75.7, zCoord);
		glVertex3f(xCoord + 10.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord);
		glEnd();
		glColor3fv(color.glass);
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 7.5, 65.7, zCoord);
		glVertex3f(xCoord + 10.0, 75.7, zCoord);
		glVertex3f(xCoord + 25.0, 75.7, zCoord);
		glVertex3f(xCoord + 27.5, 65.7, zCoord);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(xCoord + 7.5, 65.7, zCoord + 25.0);
		glVertex3f(xCoord + 10.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 25.0, 75.7, zCoord + 25.0);
		glVertex3f(xCoord + 27.5, 65.7, zCoord + 25.0);
		glEnd();
	}
};
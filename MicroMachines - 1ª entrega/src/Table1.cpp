#include "Table1.h"
#include <GL/glut.h>

Table1::Table1() {
}

Table1::Table1(double x, double y, double z) {
	_position.set(x, y, z);
}

Table1::~Table1(void)
{
}

void Table1::draw() {

	glPushMatrix();
	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glScalef(3.0, 3.0, 3.0);
	glColor3f(0.6, 0.7, 1);
	glutSolidCube(1);		
	glPopMatrix();
}
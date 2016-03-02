#include "Orange.h"
#include <GL/glut.h>

Orange::Orange() {
}

Orange::Orange(double x, double y, double z) {
	_position.set(x, y, z);
}

Orange::~Orange(void)
{
}
void Orange::draw() {

	glColor3d(1.0, 0.5, 0);
	glPushMatrix();
	glTranslated(_position.getX(), _position.getY(), _position.getZ());
	glutSolidSphere(0.2, 40, 40);
	glPopMatrix();
}

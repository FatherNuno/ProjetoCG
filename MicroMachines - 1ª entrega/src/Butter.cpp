#include "Butter.h"
#include <GL/glut.h>

Butter::Butter() {
}

Butter::~Butter(void)
{
}

Butter::Butter(double x, double y, double z) {
	_position.set(x, y, z);
}

void Butter::draw() {

	glColor3d(1.0, 1.5, 0);

	glPushMatrix();
	glTranslated(_position.getX(), _position.getY(), _position.getZ());
	
	glScalef(0.25, 0.2, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}


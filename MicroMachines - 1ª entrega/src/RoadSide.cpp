#include "RoadSide.h"
#include <GL/glut.h>

RoadSide::RoadSide() {
}

RoadSide::RoadSide(double x, double y, double z) {
	_position.set(x, y, z);
}

RoadSide::~RoadSide(void)
{

}
void RoadSide::draw() {
	glPushMatrix();
	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glScalef(0.2, 0.2, 0);
	glColor3f(0.8, 0.5, 1);
	glutSolidTorus(0.05, 0.15, 5, 10);	
	glPopMatrix();
}


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

	//Material

	GLfloat table1_amb[] = {0.0f,0.65f,0.8f,1.0f};
	GLfloat table1_diff[] = {0.0f,0.0f,0.4f,1.0f};
	GLfloat table1_spec[] = {0.0f,0.0f,0.4f,1.0f};
	GLfloat table1_shine = 77;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, table1_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, table1_diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, table1_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, table1_shine);

	//Solido

	glPushMatrix();
	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glColor3f(0.6, 0.7, 1);
	glBegin(GL_POLYGON);
	for (double y = -1.5; y < 1.5; y+=(1.5/20)) {
		for (double x = -1.5; x < 1.5; x += (1.5 / 20)) {
				glNormal3f(0, 0, 1);
				glVertex3f(x,y,0.5);	//Bottom Left
				glVertex3f(x+(1.5 / 20),y,0.5);	 //Bottom Right
				glVertex3f(x+(1.5 / 20), y+(1.5 / 20), 0.5);	 //Top Right
				glVertex3f(x,y + (1.5 / 20),0.5);	//Top Left
		}
	}
	glEnd();
	glPopMatrix();
}

double Table1::getR(){
	return 0;
}

double Table1::getX(){
	return _position.getX();
}

double Table1::getY(){
	return _position.getY();
}

int Table1::getId(){
	return 0;
}

double Table1::getVel(){
	return 0;
}

double Table1::getAngle(){
	return 0;
}

void Table1::colision(int id, double v, double angle){
}

void Table1::move(double delta_t) {
}

void Table1::changeVelocity() {
}

void Table1::fall() {
}
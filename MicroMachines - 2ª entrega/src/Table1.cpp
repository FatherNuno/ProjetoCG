 #include "Table1.h"
#include <GL/glut.h>

Table1::Table1() {
}

Table1::Table1(double x, double y, double z) {
	_position.set(x, y, z);
}

Table1::~Table1(void){
}

void Table1::draw() {
	glPushMatrix();
	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glScalef(3.0, 3.0, 1.0);
	glColor3f(0.6, 0.7, 1);
	glutSolidCube(1);		
	glPopMatrix();
}

double Table1::getIdFall(){
	return 0;
}

void Table1::setIdFall(int idfall){
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

void Table1::changeVelocity(){
}

void Table1::fall(){
}
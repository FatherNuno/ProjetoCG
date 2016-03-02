#include "RoadSide.h"
#include <GL/glut.h>
#include <math.h>

#define PI 3.141592
#define RAIO 0.15
#define RAIOSCALE 0.2

RoadSide::RoadSide() {
}

RoadSide::RoadSide(double x, double y, double z) {
	_position.set(x, y, z);
	_r = RAIOSCALE * RAIO;
	_id = 1;
	_vel = 0.0;
	_angle = 0.0;
}

RoadSide::~RoadSide(void){
}

double RoadSide::getR(){
	return _r;
}

double RoadSide::getX(){
	return _position.getX();
}

double RoadSide::getY(){
	return _position.getY();
}

int RoadSide::getId(){
	return _id;
}

double RoadSide::getVel(){
	return _vel;
}

double RoadSide::getAngle(){
	return _angle;
}

void RoadSide::colision(int id, double v, double angle){
	if(id==4){
		_vel = v;
		double y1 = _position.getY();
		_position.setY(y1 + _vel*sin(angle*(PI/180)));
		double x1 = _position.getX();
		_position.setX(x1 + _vel*cos(angle*(PI/180)));
		_vel = 0.0;
	}
}

void RoadSide::draw() {

	//Material

	GLfloat roadside_amb[] = {0.6f,0.4f,0.0f,1.0f};
	GLfloat roadside_diff[] = {0.5f,0.35f,0.0f,1.0f};
	GLfloat roadside_spec[] = {0.0f,0.0f,0.0f,1.0f};
	GLfloat roadside_shine = 77;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, roadside_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, roadside_diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, roadside_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, roadside_shine);

	//Solido

	glPushMatrix();
	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glScalef(0.2, 0.2, 0);
	glColor3f(0.8, 0.5, 1);
	glutSolidTorus(0.05, 0.15, 5, 10);	
	glPopMatrix();
}

void RoadSide::move(double delta_t) {
}

void RoadSide::changeVelocity() {
}

void RoadSide::fall() {
}
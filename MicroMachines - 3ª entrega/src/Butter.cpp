#include "Butter.h"
#include <GL/glut.h>
#include <math.h>

#define PI 3.141592
#define LENGHT 1
#define WEIGHT 1
#define LENGHTSCALE 0.1
#define WEIGHTSCALE 0.1

Butter::Butter() {
}

Butter::~Butter(void)
{
}

Butter::Butter(double x, double y, double z) {
	_position.set(x, y, z);
	_r = (LENGHTSCALE*LENGHT)/2;  
	_id = 2;
	_vel = 0.0;
	_angle = 0.0;
}

void Butter::draw() {

	//Material

	GLfloat butter_amb[] = {0.5f,0.4f,0.0f,1.0f};
	GLfloat butter_diff[] = {0.5f,0.35f,0.0f,1.0f};
	GLfloat butter_spec[] = {0.0f,0.0f,0.0f,0.5f};
	GLfloat butter_shine = 80;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, butter_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, butter_diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, butter_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, butter_shine);

	//Solido

	glColor3d(1.0, 1.5, 0);

	glPushMatrix();
	glTranslated(_position.getX(), _position.getY(), _position.getZ());
	
	glScalef(LENGHTSCALE, WEIGHTSCALE, 0.1);
	//glutSolidCube(1);

	glBegin(GL_POLYGON); //face baixo
	glNormal3f(0, 0, -1);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glEnd();
	glBegin(GL_POLYGON); //face esquerda
	glNormal3f(-1, 0, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON); //face direita
	glNormal3f(1, 0, 0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON); //face tras
	glNormal3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON); //face frente
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON); //face cima
	glNormal3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();


	glPopMatrix();
}

double Butter::getR(){
	return _r;
}

double Butter::getX(){
	return _position.getX();
}

double Butter::getY(){
	return _position.getY();
}

int Butter::getId(){
	return _id;
}

double Butter::getVel(){
	return _vel;
}

double Butter::getAngle(){
	return _angle;
}

void Butter::colision(int id, double v, double angle){
	if(id==4){
		_vel = v;
		double y1 = _position.getY();
		_position.setY(y1 + _vel*sin(angle*(PI/180)));
		double x1 = _position.getX();
		_position.setX(x1 + _vel*cos(angle*(PI/180)));
		_vel = 0.0;
	}
}

void Butter::move(double delta_t) {
}
void Butter::fall() {
}
void Butter::changeVelocity() {
}
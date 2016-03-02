#include "Car.h"
#include <math.h>

#define PI 3.141592
#define MAXSPEED 0.05
#define MINSPEED -0.05

Car::Car() { 
}

Car::Car(double x, double y, double z, double angle, GLfloat red, GLfloat green, GLfloat blue) {
	_position.set(x, y, z);
	_red = red;
	_green = green;
	_blue = blue;
	_angle = angle;
	_aceleration = 0.00005;
	_vel = 0.0;
}

Car::~Car() {
}

void Car::drawell(double x, double y, double z){
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f); //Red, Green, Blue
	glTranslatef( x,  y,  z);
	glScalef(2.0f, 1.0f, 1.0f); //alterar a escala
	glRotated(90.0, 0.0, 1.0, 0.0);
	glutSolidTorus(0.005, 0.025, 10, 50);
	glPopMatrix();
}

void Car::draw() {

	glPushMatrix();

	glTranslatef(_position.getX(), _position.getY(), _position.getZ() - 0.50);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	glRotatef(-90, 0.0, 0.0, 1.0);
	glScalef(0.5f, 0.5f, 0.5f);

		/*  car body */
		glPushMatrix();
		glColor3f(0.0, _green, 0.0); //Red, Green, Blue
		glScalef(0.15f, 0.25f, 0.2f); //alterar a escala
		glutSolidCube(1);
		glPopMatrix();


		/* Roda frente esquerda*/

		drawell(- 0.085,  0.0625,  - 0.65);

		/*  Roda frente direita*/

		drawell(0.085,  0.0625,  - 0.65);

		/*  Roda tras direita */
		drawell(0.085,  - 0.0625,  - 0.65);

		/*  Roda tras esquerda */

		drawell(- 0.085,  - 0.0625,  - 0.65);
	
	glPopMatrix();	
}

/* metodos para o movimento do carro */

void Car::moveLeftPressed() { //feito
	_angle = _angle + 3 ;
}

void Car::moveRightPressed() { //feito
	_angle = _angle - 3;
}

void Car::moveUpPressed(double delta_t) {

	//_aceleration = 0.0;

	if(_vel>MINSPEED && _vel<MAXSPEED)
		//_aceleration = 0.005;
		
	_vel =_vel + _aceleration*delta_t;
	

	double y = _position.getY();
	_position.setY(y + _vel*delta_t*sin(_angle*(PI/180)));
	double x = _position.getX();
	_position.setX(x + _vel*delta_t*cos(_angle*(PI/180)));
}

void Car::moveDownPressed(double delta_t) {
	
	//_aceleration = 0.0;

	if(_vel>MINSPEED && _vel<MAXSPEED)
		//_aceleration = -0.01;
		
	_vel =_vel - _aceleration*delta_t;

	double y = _position.getY();
	_position.setY(y + _vel*delta_t*sin(_angle*(PI/180)));
	double x = _position.getX();
	_position.setX(x + _vel*delta_t*cos(_angle*(PI/180)));
}

void Car::moveUnpressed() {
	//_aceleration = 0.0;

	if(_vel!=0.0)
		//_aceleration = -0.0005;

	_vel =_vel * 0.98 ;

	double y = _position.getY();
	_position.setY(y + _vel*sin(_angle*(PI/180)));
	double x = _position.getX();
	_position.setX(x + _vel*cos(_angle*(PI/180)));
	
}

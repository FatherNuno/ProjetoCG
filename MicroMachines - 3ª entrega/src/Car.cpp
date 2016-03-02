#include "Car.h"
#include <math.h>

#define PI 3.141592
#define MAXSPEED 0.05
#define MINSPEED -0.01
#define LENGHT 0.15
#define WEIGHT 0.25
#define LENGHTSCALE 0.5
#define WEIGHTSCALE 0.5

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
	_r = sqrt(((WEIGHT*WEIGHTSCALE)/2)*((WEIGHT*WEIGHTSCALE)/2)+((LENGHT*LENGHTSCALE)/2)*((LENGHT*LENGHTSCALE)/2));
	_id = 4;
	_x = x;
	_y = y;
	_upUnlock = true;
	_downUnlock = true;
	_rightUnlock = true;
	_leftUnlock = true;
	_up = false;
	_right = false;
	_left = false;
	_down = false;
}

Car::~Car() {
}

double Car::getR(){
	return _r;
}

double Car::getX(){
	return _position.getX();
}

double Car::getY(){
	return _position.getY();
}

int Car::getId(){
	return _id;
}

double Car::getVel(){
	return _vel;
}

double Car::getAngle(){
	return _angle;
}

void Car::setVel(double vel){
	_vel=vel;
}

void Car::setUp(bool key){
	_up=key;
}

void Car::setDown(bool key){
	_down=key;
}

void Car::setLeft(bool key){
	_left=key;
}

void Car::setRight(bool key){
	_right=key;
}


void Car::colision(int id, double v, double angle){
	
	if(id == 3){ //bateu na laranja
		_upUnlock = true;
		_downUnlock = true;
		_rightUnlock = true;
		_leftUnlock = true;
		respawn();
	}
	if(id==1 || id==2){ //bateu em manteiga ou cheerio
		if(_left)
			_leftUnlock = false;
		if(_up)
			_upUnlock = false;
		if(_down)
			_downUnlock = false;
		if(_right)
			_rightUnlock = false;
		_position.setY(_y);
		_position.setX(_x);
		_vel = 0.0;
	}
}

void Car::drawell(double x, double y, double z){
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f); //Red, Green, Blue
	glTranslatef( x,  y,  z);
	glScalef(5.0f, 5.0f, 5.0f);
		glBegin(GL_TRIANGLE_FAN); //hexagono direita
		glNormal3f(1, 0, 0);
		glVertex3f(x + 0.005, y, z);
		glVertex3f(x + 0.005, y - 0.005, z + 0.011);
		glVertex3f(x + 0.005, y + 0.005, z + 0.011);
		glVertex3f(x + 0.005, y + 0.01, z);
		glVertex3f(x + 0.005, y + 0.005, z - 0.011);
		glVertex3f(x + 0.005, y - 0.005, z - 0.011);
		glVertex3f(x + 0.005, y - 0.01, z);
		glVertex3f(x + 0.005, y - 0.005, z + 0.011);
		glEnd();

		glBegin(GL_TRIANGLE_FAN); //hexagono esquerda
		glNormal3f(-1, 0, 0);
		glVertex3f(x - 0.005, y, z);
		glVertex3f(x - 0.005, y - 0.005, z + 0.011);
		glVertex3f(x - 0.005, y + 0.005, z + 0.011);
		glVertex3f(x - 0.005, y + 0.01, z);
		glVertex3f(x - 0.005, y + 0.005, z - 0.011);
		glVertex3f(x - 0.005, y - 0.005, z - 0.011);
		glVertex3f(x - 0.005, y - 0.01, z);
		glVertex3f(x - 0.005, y - 0.005, z + 0.011);
		glEnd();

	//juntar hexagonos

		glBegin(GL_POLYGON); //face cima
		glNormal3f(0, 0, 1);
		glVertex3f(x + 0.005, y - 0.005, z + 0.011);
		glVertex3f(x + 0.005, y + 0.005, z + 0.011);
		glVertex3f(x - 0.005, y + 0.005, z + 0.011);
		glVertex3f(x - 0.005, y - 0.005, z + 0.011);
		glEnd();

		glBegin(GL_POLYGON); //face baixo
		glNormal3f(0, 0, -1);
		glVertex3f(x + 0.005, y - 0.005, z - 0.011);
		glVertex3f(x + 0.005, y + 0.005, z - 0.011);
		glVertex3f(x - 0.005, y + 0.005, z - 0.011);
		glVertex3f(x - 0.005, y - 0.005, z - 0.011);
		glEnd();

		glBegin(GL_POLYGON); //face tras cima
		glNormal3f(0, -cos(PI/3), sin(PI/3));
		glVertex3f(x + 0.005, y - 0.005, z + 0.011);
		glVertex3f(x + 0.005, y - 0.01, z);
		glVertex3f(x - 0.005, y - 0.01, z);
		glVertex3f(x - 0.005, y - 0.005, z + 0.011);
		glEnd();

		glBegin(GL_POLYGON); //face tras baixo
		glNormal3f(0, -cos(PI / 3), -sin(PI / 3));
		glVertex3f(x + 0.005, y - 0.005, z - 0.011);
		glVertex3f(x + 0.005, y - 0.01, z);
		glVertex3f(x - 0.005, y - 0.01, z);
		glVertex3f(x - 0.005, y - 0.005, z - 0.011);
		glEnd();

		glBegin(GL_POLYGON); //face frente cima
		glNormal3f(0, cos(PI / 3), sin(PI / 3));
		glVertex3f(x + 0.005, y + 0.005, z + 0.011);
		glVertex3f(x + 0.005, y + 0.01, z);
		glVertex3f(x - 0.005, y + 0.01, z);
		glVertex3f(x - 0.005, y + 0.005, z + 0.011);
		glEnd();

		glBegin(GL_POLYGON); //face frente baixo
		glNormal3f(0, cos(PI / 3), -sin(PI / 3));
		glVertex3f(x + 0.005, y + 0.005, z - 0.011);
		glVertex3f(x + 0.005, y - 0.01, z);
		glVertex3f(x - 0.005, y + 0.01, z);
		glVertex3f(x - 0.005, y + 0.005, z - 0.011);
		glEnd();
	glPopMatrix();
}

void Car::draw() {

	//Material

	GLfloat car_amb[] = {0.37f,0.37f,0.37f,1.0f};
	GLfloat car_diff[] = {0.72f,0.72f,0.72f,1.0f};
	GLfloat car_spec[] = {1.0f,1.0f,1.0f,1.0f };
	GLfloat car_shine = 25;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, car_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, car_diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, car_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, car_shine);

	//Solido

	glPushMatrix();

	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	glRotatef(_angle, 0.0, 0.0, 1.0);
	glRotatef(-90, 0.0, 0.0, 1.0);
	glScalef(LENGHTSCALE, WEIGHTSCALE, 0.5f);

		/* Roda frente esquerda*/

		drawell(-0.015, 0.01, -0.02);

		/*  Roda frente direita*/

		drawell(0.015, 0.01, -0.02);

		/*  Roda tras direita */
		drawell(0.015, -0.01, -0.02);

		/*  Roda tras esquerda */

		drawell(-0.015, -0.01, -0.02);

		/*  car body */
		glPushMatrix();
		glColor3f(_red, _green, _blue); //Red, Green, Blue
		glScalef(LENGHT,WEIGHT, 0.2f); //alterar a escala
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
		glBegin(GL_POLYGON); //face frente
		glNormal3f(0, -1, 0);
		glVertex3f(-0.5, -0.5, -0.5);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
		glEnd();
		glBegin(GL_POLYGON); //face tras
		glNormal3f(0, 1, 0);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glEnd();
		glBegin(GL_POLYGON); //face cima
		glNormal3f(0, 0, 1);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glEnd();
	
		glPopMatrix();
	glPopMatrix();


}

/* metodos para o movimento do carro */

void Car::moveLeftPressed() { //feito
	if(_leftUnlock){
		_upUnlock = true;
		_downUnlock = true;
		_rightUnlock = true;
		_angle = _angle + 3 ;
	}
}

void Car::moveRightPressed() { //feito
	if(_rightUnlock){
		_upUnlock = true;
		_downUnlock = true;
		_leftUnlock = true;
		_angle = _angle - 3;
	}
}

void Car::moveUpPressed(double delta_t) {
	if(_upUnlock){

		_leftUnlock = true;
		_downUnlock = true;
		_rightUnlock = true;

		if(_vel>MINSPEED && _vel<MAXSPEED)

			_vel =_vel + _aceleration*delta_t;
	

		_y = _position.getY();
		_x = _position.getX();
		_position.setY(_y + _vel*sin(_angle*(PI/180)));
		_position.setX(_x + _vel*cos(_angle*(PI/180)));
	}
}

void Car::moveDownPressed(double delta_t) {
	if(_downUnlock){

		_upUnlock = true;
		_leftUnlock = true;
		_rightUnlock = true;
	
		if(_vel>MINSPEED && _vel<MAXSPEED)

			_vel =_vel - 1.75*_aceleration*delta_t;

		_y = _position.getY();
		_x = _position.getX();
		_position.setY(_y + _vel*sin(_angle*(PI/180)));
		_position.setX(_x + _vel*cos(_angle*(PI/180)));
	}
}

void Car::moveUnpressed() {

	if(_vel!=0.0)

	_vel =_vel * 0.98 ;

	_y = _position.getY();
	_x = _position.getX();
	_position.setY(_y + _vel*sin(_angle*(PI/180)));
	_position.setX(_x + _vel*cos(_angle*(PI/180)));
	
}

void Car::fall(){
	_y = _position.getY();
	_x = _position.getX();
	if(_y>1.5 || _y<-1.5 || _x>1.5 || _x<-1.5 ){
		respawn();
	}
}

void Car::respawn(){
	_vel = 0.0;
	_angle = 0.0;
	_position.setX(0.90f);
	_position.setY(-0.65f);
	_x=0.90;
	_y=-0.65;
}

void Car::move(double delta_t) {
}

void Car::changeVelocity() {
}



#include "Orange.h"
#include <GL/glut.h>
#include <math.h>
#include <ctime>

#define PI 3.141592
#define RAIO 0.05

Orange::Orange() {
}

Orange::Orange(double x, double y, double z,double vel, double angle) {
	srand(static_cast<unsigned int>(time(0)));  //seeds random function

	_position.set(x, y, z);
	_vel = vel;
	_velmax = vel;
	_angle = angle;
	_anglerot = angle;
	_drawable = true;
	_interval = randomDouble(0,10);
	_initime = 0;
	_r = RAIO;
	_id = 3;
}

Orange::~Orange(void){
}
void Orange::draw() {

	//Material

	GLfloat orange_amb[] = {1.0f,0.5f,0.0f,1.0f};
	GLfloat orange_diff[] = {1.0f,0.5f,0.0f,1.0f};
	GLfloat orange_spec[] = {1.0f,0.5f,0.0f,1.0f};
	GLfloat orange_shine = 110;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, orange_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, orange_diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, orange_spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, orange_shine);

	//Solido

	if(_drawable){
		glPushMatrix();
		glTranslated(_position.getX(), _position.getY(), _position.getZ());
		glRotatef(_anglerot, -sin(_angle*(PI/180)), cos(_angle*(PI / 180)), 0.0);

			glColor3d(1.0, 0.5, 0);
			glutSolidSphere(RAIO, 40, 40);

		glPopMatrix();
	}
}

double Orange::getR(){
	return _r;
}

double Orange::getX(){
	return _position.getX();
}

double Orange::getY(){
	return _position.getY();
}

int Orange::getId(){
	return _id;
}

double Orange::getVel(){
	return _vel;
}

double Orange::getAngle(){
	return _angle;
}

void Orange::colision(int id, double v, double angle){
}

void Orange::move(double delta_t) {	

	double y = _position.getY();
	_position.setY(y + _vel*delta_t*sin(_angle*(PI/180)));
	double x = _position.getX();
	_position.setX(x + _vel*delta_t*cos(_angle*(PI/180)));
	_anglerot = _anglerot + _vel*100000;
}

void Orange::changeVelocity(){
	_vel = _vel + 0.000000001*glutGet(GLUT_ELAPSED_TIME);
	_velmax = _velmax + 0.000000001*glutGet(GLUT_ELAPSED_TIME);
}

void Orange::fall(){
	if(_drawable){
		double y = _position.getY();
		double x = _position.getX();
		if(y>1.5 || y<-1.5 || x>1.5 || x<-1.5 ){
			_drawable = false;
			_initime = glutGet(GLUT_ELAPSED_TIME);
		}
	}
	else{
		if((glutGet(GLUT_ELAPSED_TIME)-_initime) >= _interval)
			respawn();
	}
}

void Orange::respawn(){
	
	_position.setY(randomDouble(-1.5,1.5));
	_position.setX(randomDouble(-1.5,1.5));

	_vel = randomDouble(_vel,_velmax);
	_angle = randomDouble(-180,180);
	_drawable = true;
}

double Orange::randomDouble(double a, double b) {
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}

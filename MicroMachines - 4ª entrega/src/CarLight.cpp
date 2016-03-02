#include "CarLight.h"



CarLight::CarLight(GLenum number) {
	_num = number;
}

CarLight::~CarLight() {
}


void CarLight::draw() {

	GLfloat amb[] = { getAmbient()->getX(), getAmbient()->getY(), getAmbient()->getZ(), getAmbient()->getW() };
	GLfloat diffuse[] = { getDiffuse()->getX(), getDiffuse()->getY(), getDiffuse()->getZ(),getDiffuse()->getW() };
	GLfloat specular[] = { getSpecular()->getX(), getSpecular()->getY(), getSpecular()->getZ(), getSpecular()->getW() };
	GLfloat pos[] = { getPosition()->getX(), getPosition()->getY(),  getPosition()->getZ(), 1.0 };
	GLfloat direction[] = { getDirection()->getX(), getDirection()->getY(),  getDirection()->getZ()};
	double exponent = getExponent();

	glLightfv(_num, GL_AMBIENT, amb);
	glLightfv(_num, GL_DIFFUSE, diffuse);
	glLightfv(_num, GL_SPECULAR, specular);
	glLightfv(_num, GL_POSITION, pos);

	glLightfv(_num, GL_SPOT_DIRECTION, direction);
	glLightf(_num, GL_SPOT_CUTOFF, 90); // 0~180
	glLightf(_num, GL_SPOT_EXPONENT, exponent); // 0~128 

	//atenuacao da luz
	glLightf(_num, GL_CONSTANT_ATTENUATION, 0);
	glLightf(_num, GL_LINEAR_ATTENUATION, 0);
	glLightf(_num, GL_QUADRATIC_ATTENUATION, 2);	
}

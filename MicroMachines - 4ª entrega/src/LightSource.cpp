/* componentes da iluminacao:
	ambiente - para tds os objectos indirectamente/luz constante
	difusa - iluminacao directa
	especular - depende do ponto de vista. muda o brilho consoante o ponto de vista enquanto a difusa nao muda

	tipos de luz:
		direccional - luz do sol. É constante
		pointlight - luz que ilumina area a volta dela (velas). controla se a area com a atenuacao pois velas nao iluminam o mapa todo
		spotlight - luz que ilumina uma area (candeeiro) para esta entrega nao se usa

*/
#include "LightSource.h"


LightSource::LightSource(GLenum number) {
	_num = number;
}

LightSource::LightSource() {}

LightSource::~LightSource() { 
}

bool LightSource::getState() {
	return _state;
}

void LightSource::setState(bool state) {
	_state = state;
	/*if (_state)
		glEnable(GL_LIGHT0 + _num);
	else
		glDisable(GL_LIGHT0 + _num);*/
}

GLenum LightSource::getNum() {
	return _num;
}

void LightSource::setPosition(Vector4 *position) {
	_position = position;
}

Vector4* LightSource::getPosition() {
	return _position;
}

void LightSource::setDirection(Vector3 *direction) {
	_direction = direction;
}

Vector3* LightSource::getDirection() {
	return _direction;
}

void LightSource::setCutOff(double cut_off) {
	_cut_off = cut_off;
}

void LightSource::setExponent(double exponent) {
	_exponent = exponent;
}

void LightSource::setAmbient(Vector4 *ambient) {
	_ambient = ambient;
}

Vector4* LightSource::getAmbient() {
	return _ambient;
}


void LightSource::setDiffuse(Vector4 *diffuse) {
	_diffuse = diffuse;
}

Vector4* LightSource::getDiffuse() {
	return _diffuse;
}

void LightSource::setSpecular(Vector4 *specular) {
	_specular = specular;
}

Vector4* LightSource::getSpecular() {
	return _specular;
}

double LightSource::getCutOff() {
	return _cut_off;
}

double LightSource::getExponent() {
	return _exponent;
}

void LightSource::draw() {
	GLfloat amb0[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat amb[] = { getAmbient()->getX(), getAmbient()->getY(), getAmbient()->getZ(), getAmbient()->getW() };
	GLfloat diffuse[] = { getDiffuse()->getX(), getDiffuse()->getY(), getDiffuse()->getZ(),getDiffuse()->getW() };
	GLfloat specular[] = { getSpecular()->getX(), getSpecular()->getY(), getSpecular()->getZ(), getSpecular()->getW() };
	GLfloat pos[] = { getPosition()->getX(), getPosition()->getY(), getPosition()->getZ(), 0.0f };


	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb0);
	glLightfv(_num, GL_AMBIENT, amb);
	glLightfv(_num, GL_DIFFUSE, diffuse);
	glLightfv(_num, GL_SPECULAR, specular);
	glLightfv(_num, GL_POSITION, pos);

	//***** TO DO *****
}
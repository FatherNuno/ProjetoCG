/*** Vector3 implementation file ***/

#include "Vector3.h"
#include <math.h>

#define PI 3.14

Vector3::Vector3() {

	_x = DEFAULT_X;
	_y = DEFAULT_Y;
	_z = DEFAULT_Z;
	_modul = DEFAULT_MODULE;
}

Vector3::Vector3(double x, double y, double z) {

	_x = x;
	_y = y;
	_z = z;
	_modul = sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2));
}

Vector3::~Vector3() {

	// nada para libertar
}

double Vector3::getX() const {

	return _x;
}

double Vector3::getY() const {

	return _y;
}

double Vector3::getZ() const {

	return _z;
}

double Vector3::getModul() const {

	return _modul;
}

void Vector3::setX(double x){

	_x = x;
	_modul = sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2));
}

void Vector3::setY(double y){

	_y = y;
	_modul = sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2));
}

void Vector3::setZ(double z){

	_z = z;
	_modul = sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2));
}

void Vector3::set(double x, double y, double z) {

	_x = x;
	_y = y;
	_z = z;
	_modul = sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2));
}

void Vector3::setAngle2D(double angle){
	_x = _modul*cos(angle*(PI/180));
	_y = _modul*sin(angle*(PI/180));
}

void Vector3::setModul2D(double modul){
	_x=_modul;
	_y=0;
	_z=0;
}

void Vector3::operator=(const Vector3 &vec) {

	_x = vec.getX();
	_y = vec.getY();
	_z = vec.getZ();
	_modul = vec.getModul();
}

Vector3 Vector3::operator*(double num) {

	Vector3 result;

	result.setX(this->getX() * num);
	result.setY(this->getY() * num);
	result.setZ(this->getZ() * num);

	return result;
}

Vector3 Vector3::operator+(const Vector3 &vec) {

	Vector3 result;

	result.setX(this->getX() + vec.getX());
	result.setY(this->getY() + vec.getY());
	result.setZ(this->getZ() + vec.getZ());

	return result;
}

Vector3 Vector3::operator-(const Vector3 &vec) {

	Vector3 result;

	result.setX(this->getX() - vec.getX());
	result.setY(this->getY() - vec.getY());
	result.setZ(this->getZ() - vec.getZ());

	return result;
}
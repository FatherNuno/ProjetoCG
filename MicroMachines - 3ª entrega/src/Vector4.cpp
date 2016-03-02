#include "Vector4.h"

#include <iostream>


Vector4::Vector4() {

	_x = DEFAULT_X;
	_y = DEFAULT_Y;
	_z = DEFAULT_Z;
	_w = DEFAULT_W;

}

Vector4::Vector4(double x, double y, double z, double w) {

	_x = x;
	_y = y;
	_z = z;
	_w = w;
}

Vector4::~Vector4() {

	// nada para libertar
}

double Vector4::getW() const {

	return _w;
}

void Vector4::set(double x, double y, double z, double w) {

	_x = x;
	_y = y;
	_z = z;
	_w = w;
}

void Vector4::operator=(const Vector4 &vec) {

	_x = vec.getX();
	_y = vec.getY();
	_z = vec.getZ();
	_w = vec.getW();
}

Vector4 Vector4::operator*(double num) {

	Vector4 result;

	result._x = this->getX() * num;
	result._y = this->getY() * num;
	result._z = this->getZ() * num;
	result._w = this->getW() * num;

	return result;
}

Vector4 Vector4::operator+(const Vector4 &vec) {

	Vector4 result;

	result._x = this->getX() + vec.getX();
	result._y = this->getY() + vec.getY();
	result._z = this->getZ() + vec.getZ();
	result._w = this->getW() + vec.getW();

	return result;
}

Vector4 Vector4::operator-(const Vector4 &vec) {

	Vector4 result;

	result._x = this->getX() - vec.getX();
	result._y = this->getY() - vec.getY();
	result._z = this->getZ() - vec.getZ();
	result._w = this->getW() - vec.getW();

	return result;
}
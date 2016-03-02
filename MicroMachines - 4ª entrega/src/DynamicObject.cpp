#include "DynamicObject.h"

DynamicObject::DynamicObject() { }

DynamicObject::~DynamicObject() {

}

Vector3 DynamicObject::getSpeed() {

	return _speed;
}

void DynamicObject::setSpeed(double x, double y, double z) {

	_speed.set(x, y, z);
}

void DynamicObject::setSpeed(const Vector3 &speed) {

	_speed = speed;		
}

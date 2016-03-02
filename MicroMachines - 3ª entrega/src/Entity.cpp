#include "Entity.h"

Entity::Entity() {

}

Entity::~Entity() {

}

Vector3 Entity::getPosition() {
	return _position;
}

void Entity::setPosition(double x, double y, double z) {
	_position.set(x, y, z);
}

void Entity::setPosition(const Vector3 &pos) {
	_position = pos;
}
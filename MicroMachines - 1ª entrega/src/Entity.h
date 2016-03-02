#pragma once
#include "Vector3.h"

class Entity 
{
protected:
	Vector3 _position;

public:
	Entity(void);
	~Entity(void);
	Vector3 getPosition();
	void setPosition(double x, double y, double z);
	void setPosition(const Vector3 &p);
};
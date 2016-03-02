#pragma once
#include "GameObject.h"

class DynamicObject : public GameObject{

protected:

	Vector3 _speed;
	
public:

	DynamicObject();

	~DynamicObject();

	Vector3 getSpeed();

	void setSpeed(double x, double y, double z);
	void setSpeed(const Vector3 &speed);

};
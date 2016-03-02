#pragma once
#include "DynamicObject.h"

class Car : public DynamicObject {

private:
	GLfloat _red, _green, _blue;
	double _angle;
	double _aceleration;
	double _vel;

public:

	Car();
	Car(double x, double y, double z, double angle, GLfloat red, GLfloat green, GLfloat blue);
	~Car();
	void draw();
	void moveDownPressed(double delta_t);
	void moveUpPressed(double delta_t);
	void moveLeftPressed();
	void moveRightPressed();
	void moveUnpressed();
	void drawell(double x, double y, double z);
};
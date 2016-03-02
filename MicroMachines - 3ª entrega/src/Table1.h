#pragma once
#include "StaticObject.h"

class Table1 : public StaticObject {

public:
	Table1(void);
	Table1(double x, double y, double z);
	~Table1(void);
	void draw();
	double getR();
	double getX();
	double getY();
	double getVel();
	double getAngle();
	void colision(int id, double v, double angle);
	int getId();
	void move(double delta_t);
	void fall();
	void changeVelocity();
};
#pragma once
#include "Obstacle.h"

class Butter : public Obstacle {

private:
	double _r;
	int _id;
	double _vel;
	double _angle;
public:
	Butter(void);
	~Butter(void);
	Butter(double x, double y, double z);
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
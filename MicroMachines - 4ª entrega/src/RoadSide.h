#pragma once
#include "StaticObject.h"

class RoadSide : public StaticObject {

private:
	double _r;
	int _id;
	double _vel;
	double _angle;
public:
	RoadSide(void);
	~RoadSide(void);
	RoadSide(double x, double y, double z);
	void draw();
	double getR();
	double getX();
	double getY();
	double getVel();
	double getAngle();
	int colision(int id, double v, double angle);
	int getId();
	void move(double delta_t);
	int fall();
	void changeVelocity(double delta_t);
	void setTexture(GLuint id);
};
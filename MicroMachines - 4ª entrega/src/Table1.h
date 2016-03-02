#pragma once
#include "StaticObject.h"


class Table1 : public StaticObject {

private:
	GLuint tex_2d;
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
	int colision(int id, double v, double angle);
	int getId();
	void move(double delta_t);
	int fall();
	void changeVelocity(double delta_t);
	void setTexture(GLuint id);
};
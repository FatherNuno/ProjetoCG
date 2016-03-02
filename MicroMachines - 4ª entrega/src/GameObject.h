#pragma once
#include "Entity.h"

class GameObject : public Entity {
public:
	virtual void draw() =0;
	virtual double getR() =0;
	virtual double getX() =0;
	virtual double getY() =0;
	virtual double getVel() =0;
	virtual double getAngle() =0;
	virtual int colision(int id, double v, double angle) =0;
	virtual int getId() =0;
	virtual void move(double delta_t) = 0;
	virtual int fall() = 0;
	virtual void changeVelocity(double delta_t) = 0;
	virtual void setTexture(GLuint id) = 0;
};
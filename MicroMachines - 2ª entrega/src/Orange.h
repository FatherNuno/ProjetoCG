#pragma once
#include "Obstacle.h"

class Orange : public Obstacle {

private:
	double _velmax;
	double _vel;
	double _angle;
	double _anglerot;
	bool _drawable;
	double _interval;  
	double _initime;
	double _r;
	int _id;
	int _idfall;

public:
	Orange(void);
	Orange(double x, double y, double z,double vel,double angle);
	~Orange(void);
	void draw();
	void changeVelocity();
	void move(double delta_t);
	void fall();
	void respawn();
	double randomDouble(double a, double b);
	double getR();
	double getX();
	double getY();
	double getVel();
	double getAngle();
	double getIdFall();
	void setIdFall(int idfall);
	void colision(int id, double v, double angle);
	int getId();
};
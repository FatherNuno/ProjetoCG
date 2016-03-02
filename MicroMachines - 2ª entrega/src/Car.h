#pragma once
#include "DynamicObject.h"

class Car : public DynamicObject {

private:
	GLfloat _red, _green, _blue;
	double _angle;
	double _aceleration;
	double _vel;
	double _r;
	int _id;
	double _x;
	double _y;
	bool _upUnlock;  //teclas bloqueadas
	bool _downUnlock;
	bool _rightUnlock;
	bool _leftUnlock;
	
	bool _up;  //teclas premidas
	bool _down;
	bool _right;
	bool _left;

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
	void drawbase(double x, double y, double z);
	void fall();
	void respawn();
	double getR();
	double getX();
	double getY();
	double getVel();
	double getIdFall();
	void setIdFall(int idfall);
	void setVel(double vel);
	double getAngle();
	void colision(int id, double v, double angle);
	int getId();
	void setUp(bool key);
	void setDown(bool key);
	void setLeft(bool key);
	void setRight(bool key);
	void move(double delta_t);
	void changeVelocity();
};
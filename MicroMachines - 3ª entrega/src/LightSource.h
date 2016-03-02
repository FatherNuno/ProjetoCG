#pragma once
/*** LightSource header file ***/

#include <stdlib.h>
#include <GL/glut.h>

#include "Vector4.h"


class LightSource
{

protected:

	Vector4 *_ambient;
	Vector4 *_diffuse;
	Vector4 *_specular;
	Vector4 *_position;

	Vector3 *_direction;

	double _cut_off;
	double _exponent;

	GLenum _num;

	bool _state;

public:

	LightSource(GLenum number);
	LightSource();
	~LightSource();

	bool getState();
	void setState(bool state);

	GLenum getNum();

	void setPosition(Vector4 *position);
	Vector4* getPosition();

	void setDirection(Vector3 *direction);
	Vector3* getDirection();

	void setCutOff(double cut_off);
	void setExponent(double exponent);

	void setAmbient(Vector4 *ambient);
	Vector4* getAmbient();

	void setDiffuse(Vector4 *diffuse);
	Vector4* getDiffuse();

	void setSpecular(Vector4 *specular);
	Vector4* getSpecular();

	double getExponent();
	double getCutOff();

	void draw();

};

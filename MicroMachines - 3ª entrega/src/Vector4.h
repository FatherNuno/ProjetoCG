#pragma once

#include <stdlib.h>
#include <GL/glut.h>

#include "Vector3.h"

#define DEFAULT_W 0.0

class Vector4 : public Vector3
{

protected:

	double _w;

public:

	Vector4();
	Vector4(double x, double y, double z, double w);

	~Vector4();

	double getW() const;

	void set(double x, double y, double z, double w);

	void operator=(const Vector4 &vec);		// atribuicao de vectores
	Vector4 operator*(double num);			// multiplicacao por constante
	Vector4 operator+(const Vector4 &vec);	// soma de vectores
	Vector4 operator-(const Vector4 &vec);	// subtraccao de vectores

};

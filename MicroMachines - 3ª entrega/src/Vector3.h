/*** Vector3 header file ***/
#pragma once
#include <stdlib.h>
#include <GL/glut.h>

#define DEFAULT_X 0.0
#define DEFAULT_Y 0.0
#define DEFAULT_Z 0.0
#define DEFAULT_MODULE 0.0


class Vector3
{

protected:

	double _x;
	double _y;
	double _z;
	double _modul;

public:

	Vector3();
	Vector3(double x, double y, double z);

	~Vector3();

	double getX() const;
	double getY() const;
	double getZ() const;
	double getModul() const;
	void setAngle2D(double angle);
	void setModul2D(double modul);
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	void set(double x, double y, double z);

	void operator=(const Vector3 &vec);	// atribuicao de vectores
	Vector3 operator*(double num);			// multiplicacao por constante
	Vector3 operator+(const Vector3 &vec);	// soma de vectores
	Vector3 operator-(const Vector3 &vec);	// subtraccao de vectores

	void set(Vector3 vec);

};

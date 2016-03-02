#pragma once
#include "Camera.h"

class PerspectiveCamera : public Camera {
private:

	Vector3 _up;
	Vector3 _at;
	Vector3 _eye;
	double _fovy;
	double _aspect;

public:

	PerspectiveCamera();
	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Vector3 eye, Vector3 at, Vector3 up);
	~PerspectiveCamera();

	void setEyeVector(Vector3 new_eye);
	void setAtVector(Vector3 new_at);

	void update(Vector3 reference);

	void computeProjectionMatrix();

	void computeVisualizationMatrix();
};
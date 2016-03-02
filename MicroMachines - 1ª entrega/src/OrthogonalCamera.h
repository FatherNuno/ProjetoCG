#pragma once
#include "Camera.h"

class OrthogonalCamera : public Camera {

private:

	double _left;
	double _right;
	double _bottom;
	double _top;

public:

	OrthogonalCamera(double left, double right, double bottom, double top, double near, double far);
	OrthogonalCamera();
	~OrthogonalCamera();
	void computeVisualizationMatrix();
	void computeProjectionMatrix(float aspect);
	void computeReshape(float aspect);

};
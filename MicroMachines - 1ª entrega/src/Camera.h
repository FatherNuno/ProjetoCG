#pragma once
#include "Entity.h"

class Camera : public Entity {

protected:

	double _near;
	double _far;

public:
	Camera();
	virtual void computeVisualizationMatrix();
};
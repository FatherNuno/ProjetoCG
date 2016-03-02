#pragma once
#include "StaticObject.h"

class RoadSide : public StaticObject {

public:
	RoadSide(void);
	~RoadSide(void);
	RoadSide(double x, double y, double z);
	void draw();
};
#pragma once
#include "Obstacle.h"

class Orange : public Obstacle {

public:
	Orange(void);
	Orange(double x, double y, double z);
	~Orange(void);
	void draw();
};
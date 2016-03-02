#pragma once
#include "Obstacle.h"

class Butter : public Obstacle {

public:
	Butter(void);
	~Butter(void);
	Butter(double x, double y, double z);
	void draw();
};
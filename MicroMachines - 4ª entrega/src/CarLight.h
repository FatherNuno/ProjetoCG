#pragma once
#pragma once
#include "LightSource.h"


class CarLight : public LightSource {

public:
	CarLight();
	CarLight(GLenum number);
	~CarLight();
	void draw();	
};
#pragma once
#pragma once
#include "LightSource.h"


class Candle : public LightSource {

public:
	Candle();
	Candle(GLenum number);
	~Candle();
	void draw();
	
};
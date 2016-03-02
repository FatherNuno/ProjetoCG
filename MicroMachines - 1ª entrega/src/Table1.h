#pragma once
#include "StaticObject.h"

class Table1 : public StaticObject {

public:
	Table1(void);
	Table1(double x, double y, double z);
	~Table1(void);
	void draw();
};
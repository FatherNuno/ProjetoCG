#pragma once
#include "Entity.h"

class GameObject : public Entity {
public:
	virtual void draw() =0;
};
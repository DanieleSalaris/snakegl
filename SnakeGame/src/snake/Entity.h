#pragma once
#include <string>
#include "Position.h"

class Entity
{
public:
	Position position;
	Entity();
	Entity(Position position);
	inline bool CheckCollision(Entity e);
};


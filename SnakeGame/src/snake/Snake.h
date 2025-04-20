#pragma once
#include <vector>
#include "Entity.h"

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
class Snake
{
private:
	Direction direction;
	std::vector<Entity> body;

	bool IsValidDirection(Direction direction);
	Position GetTranslation(Direction direction);
public:
	Snake();
	Snake(Direction direction, Position position, int size);
	void Move();
	void Grow();
	bool CheckCollision(Position position);
	bool CheckHeadCollision(Position position);
	bool CheckBoundaryCollision(Position topLeft, Position bottomRight);
	bool CheckBodyCollision();
	inline void SetDirection(Direction);
	inline Position GetPosition();
};


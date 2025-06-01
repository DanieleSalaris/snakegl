#pragma once
#include <vector>
#include "Entity.h"

class SnakePositionsSerializer;
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
class Snake
{
public:
	static const Direction DEFAULT_DIRECTION = Direction::RIGHT;
	static const int DEFAULT_SIZE = 1;
	static const Position DEFAULT_POSITION;
private:
	Direction direction;
	std::vector<Entity> body;

	bool IsValidDirection(Direction direction);
	Position GetTranslation(Direction direction);
public:
	Snake();
	Snake(const Snake& other);
	Snake(Direction direction, Position position, int size);	
	Snake(Direction direction, Position position);
	Snake(Direction direction);
	Snake(Position position);
	Snake(Snake&& other);
	Snake& operator=(const Snake&);
	void Move();
	void Grow();
	bool CheckCollision(Position position);
	bool CheckHeadCollision(Position position);
	bool CheckBoundaryCollision(Position topLeft, Position bottomRight);
	bool CheckBodyCollision();
	void SetDirection(Direction);
	Position GetPosition();
	int inline GetSize() { return body.size(); }
	Direction inline GetDirection() const { return direction; } 
	friend SnakePositionsSerializer;
};


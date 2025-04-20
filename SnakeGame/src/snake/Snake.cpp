#include "Snake.h"

bool Snake::IsValidDirection(Direction direction)
{
	switch(this->direction) 
	{
		case Direction::UP:
			return direction != Direction::DOWN;
		case Direction::DOWN:
			return direction != Direction::UP;
		case Direction::LEFT:
			return direction != Direction::RIGHT;
		case Direction::RIGHT:
			return direction != Direction::LEFT;
	}
}

Position Snake::GetTranslation(Direction direction)
{
	switch (direction) {
		case Direction::UP:
			return Position(0, 1);
		case Direction::DOWN:
			return Position(0, -1);
		case Direction::LEFT:
			return Position(-1, 0);
		case Direction::RIGHT:
			return Position(1, 0);
	}
}

Snake::Snake() : Snake(Direction::RIGHT, Position(0, 0), 2) { }

Snake::Snake(Direction direction, Position position, int size) : direction(direction)
{
	if (size < 1) size = 1;
	body.reserve(size);
	body.emplace_back(position);
	for (int i = 1; i < size; i++) {
		Grow();
	}
}

void Snake::Move()
{
	Position nextPosition = body[0].position += GetTranslation(direction);
	for (Entity entity : body) {
		Position currentPosition = entity.position;
		entity.position = nextPosition;
		nextPosition = currentPosition;
	}
}

void Snake::Grow()
{
	body.push_back(body[body.size() - 1]);
}

bool Snake::CheckCollision(Position position)
{
	for (Entity e : body)
	{
		if (e.position == position) return true;
	}
	return false;
}

bool Snake::CheckHeadCollision(Position position)
{
	return body[0].position == position;
}

bool Snake::CheckBoundaryCollision(Position topLeft, Position bottomRight)
{
	Position headPosition = body[0].position;
	return headPosition.x < topLeft.x || headPosition.y < topLeft.y || headPosition.x > bottomRight.x || headPosition.y > bottomRight.y;
}

bool Snake::CheckBodyCollision()
{
	Position headPosition = body[0].position;
	int size = body.size();
	for (int i = 1; i < size; i++)
	{
		if (headPosition == body[i].position)
			return true;
	}
	return false;
}

inline void Snake::SetDirection(Direction direction)
{
	if (IsValidDirection(direction)) this->direction = direction;
}

inline Position Snake::GetPosition()
{
	return body[0].position;
}

#include "Snake.h"

const Position Snake::DEFAULT_POSITION = Position(1, 1);
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
		default:
			return false;
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
		default:
			return Position(0, 0);
	}
}

Snake::Snake() : Snake(Snake::DEFAULT_DIRECTION,Snake::DEFAULT_POSITION, Snake::DEFAULT_SIZE) { }

Snake::Snake(const Snake& other) : direction(other.direction), body(other.body) {}

Snake::Snake(Direction direction, Position position, int size) : direction(direction)
{
	if (size < 1) size = 1;
	body.reserve(size);
	body.emplace_back(position);
	for (int i = 1; i < size; i++) {
		Grow();
	}
}

Snake::Snake(Direction direction, Position position) : Snake(direction, position, Snake::DEFAULT_SIZE) { }

Snake::Snake(Direction direction) : Snake(direction, Snake::DEFAULT_POSITION, DEFAULT_SIZE) { } 

Snake::Snake(Position position) : Snake(Snake::DEFAULT_DIRECTION, position, Snake::DEFAULT_SIZE) { }

Snake::Snake(Snake&& other) {
	direction = other.direction;
	body = std::move(body);
}

Snake& Snake::operator=(const Snake& other)
{
	direction = other.direction;
	body = other.body;
	return *this;
}

void Snake::Move()
{
	Position nextPosition = body[0].position;
	body[0].position += GetTranslation(direction);
	int size = body.size();
	for (int i = 1; i < size; i++) {
		Entity& entity = body[i];
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
	for (Entity& e : body)
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
	int i;
	for (i = 1; i < size; i++) {
		if (headPosition != body[i].position) {
			i++;
			break;
		}
	}
	for (i; i < size; i++)
	{
		if (headPosition == body[i].position)
			return true;
	}
	return false;
}

void Snake::SetDirection(Direction direction)
{
	if (IsValidDirection(direction)) this->direction = direction;
}

Position Snake::GetPosition()
{
	return body[0].position;
}

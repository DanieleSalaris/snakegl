#pragma once
#include "../SnakeGame/src/snake/SnakePositionsSerializer.h"
#include <memory>

class SnakePositionSerializerMock : public SnakePositionsSerializer {
public:
	static const int BUFFER_MAX_LENGTH = 32;
	Position positionBuffer[BUFFER_MAX_LENGTH];
	int bufferLength = 0;
	SnakePositionSerializerMock(Snake* snake);
	void ConsumePosition(Position& position) override;
	void Serialize() override;
};

class SnakePositionsSerializerTests: public testing::Test
{
public:
	Position startingPosition = Position(1, 1);
	Direction startingDirection = Direction::RIGHT;
	int startingSize = 1;
	Snake snake;
	std::unique_ptr<SnakePositionSerializerMock> snakePositionsSerializer;

	SnakePositionsSerializerTests() : snake(startingDirection, startingPosition, startingSize)
	{
		snakePositionsSerializer.reset(new SnakePositionSerializerMock(&snake));
	}

	void Move(Direction direction) {
		snake.SetDirection(direction);
		snake.Move();
	}

	void MoveAndGrow(Direction direction) {
		snake.SetDirection(direction);
		snake.Grow();
		snake.Move();
	}
};


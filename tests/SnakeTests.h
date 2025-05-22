#pragma once
#include "pch.h"
#include "../SnakeGame/src/snake/Snake.h"

class SnakeTests : public testing::Test
{
public:
	Snake snake;
	void SetUp() override {
		snake = Snake();
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


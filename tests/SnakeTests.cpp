#include "pch.h"
#include "SnakeTests.h"

TEST_F(SnakeTests, ParemeterConstructor) {
	EXPECT_TRUE(true);
	Direction direction = Direction::UP;
	Position position(3, 4);
	int size = 3;
	snake = Snake(direction, position, size);
	EXPECT_EQ(snake.GetDirection(), direction);
	EXPECT_EQ(snake.GetPosition(), position);
	EXPECT_EQ(snake.GetSize(), size);
}

TEST_F(SnakeTests, Grow_should_increase_size) {
	int initialSize = snake.GetSize();
	snake.Grow();
	EXPECT_EQ(snake.GetSize(), initialSize + 1);
}

TEST_F(SnakeTests, SetPosition_should_set_position_when_not_starting_from_opposite_direction) {
	snake = Snake(Direction::UP);
	snake.SetDirection(Direction::RIGHT);
	EXPECT_EQ(snake.GetDirection(), Direction::RIGHT);
}

TEST_F(SnakeTests, SetPosition_should_not_set_position_when_starting_from_opposite_direction) {
	snake = Snake(Direction::UP);
	snake.SetDirection(Direction::DOWN);
	EXPECT_EQ(snake.GetDirection(), Direction::UP);
}


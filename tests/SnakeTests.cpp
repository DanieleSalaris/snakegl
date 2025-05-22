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

TEST_F(SnakeTests, GrowShouldIncreaseSize) {
    int initialSize = snake.GetSize();
    snake.Grow();
    EXPECT_EQ(snake.GetSize(), initialSize + 1);
}

TEST_F(SnakeTests, GrowNTimesShouldIncreaseSizeNTimes) {
    int initialSize = snake.GetSize();
    int n = 17;
    for (int i = 0; i < n; i++) {
        snake.Grow();
    }
    EXPECT_EQ(snake.GetSize(), initialSize + n);
}

TEST_F(SnakeTests, SetPositionShouldWorkWhenStartingFromOppositeDirection) {
    snake = Snake(Direction::UP);
    snake.SetDirection(Direction::RIGHT);
    EXPECT_EQ(snake.GetDirection(), Direction::RIGHT);
}

TEST_F(SnakeTests, SetPositionShouldNotWorkWhenStartingFromOppositeDirection) {
    snake = Snake(Direction::UP);
    snake.SetDirection(Direction::DOWN);
    EXPECT_EQ(snake.GetDirection(), Direction::UP);
}

TEST_F(SnakeTests, MoveTest1) {
    Position startingPosition(3, 3);
    Position endingPosition(4, 5);
    snake = Snake(Direction::UP, startingPosition);
    // Path UP -> RIGHT -> UP;
    Move(Direction::UP);
    Move(Direction::RIGHT);
    Move(Direction::UP);
    EXPECT_EQ(snake.GetPosition(), endingPosition);
}

TEST_F(SnakeTests, MoveTest2) {
    Position startingPosition(3, 3);
    Position endingPosition(3, 5);
    snake = Snake(Direction::UP, startingPosition);
    // Path UP -> RIGHT -> UP -> LEFT;
    Move(Direction::UP);
    Move(Direction::RIGHT);
    Move(Direction::UP);
    Move(Direction::LEFT);
    EXPECT_EQ(snake.GetPosition(), endingPosition);
}

TEST_F(SnakeTests, MoveTest3) {
    Position startingPosition(3, 3);
    Position endingPosition(1, 7);
    snake = Snake(Direction::UP, startingPosition);
    // Path UP -> LEFT -> LEFT -> DOWN -> LEFT -> UP -> UP -> RIGHT -> UP -> UP;
    Move(Direction::UP);
    Move(Direction::LEFT);
    Move(Direction::LEFT);
    Move(Direction::DOWN);
    Move(Direction::LEFT);
    Move(Direction::UP);
    Move(Direction::UP);
    Move(Direction::RIGHT);
    Move(Direction::UP);
    Move(Direction::UP);
    EXPECT_EQ(snake.GetPosition(), endingPosition);
}

TEST_F(SnakeTests, BoundaryCollisionFalseWhenPositionInsideBox) {
    Position position(1, 1);
    Position topLeft = position + Position(-1, -1);
    Position bottomRight = position + Position(1, 1);
    snake = Snake(position);
    bool collision = snake.CheckBoundaryCollision(topLeft, bottomRight);
    EXPECT_FALSE(collision);
}

TEST_F(SnakeTests, BoundaryCollisionFalseWhenPositionExactlyOnBoundary) {
    Position position(1, 1);
    snake = Snake(position);
    bool collision = snake.CheckBoundaryCollision(position, position);
    EXPECT_FALSE(collision);
}

TEST_F(SnakeTests, BoundaryCollisonTrueWhenXOutsideBorders) {
    Position topLeft(0, 0), bottomRight(2, 2);
    snake = Snake(Position(-1, 1));
    EXPECT_TRUE(snake.CheckBoundaryCollision(topLeft, bottomRight));
    snake = Snake(Position(3, 1));
    EXPECT_TRUE(snake.CheckBoundaryCollision(topLeft, bottomRight));
}

TEST_F(SnakeTests, BoundaryCollisionTrueWhenYOutsideBorders) {
    Position topLeft(0, 0), bottomRight(2, 2);
    snake = Snake(Position(1, -1));
    EXPECT_TRUE(snake.CheckBoundaryCollision(topLeft, bottomRight));
    snake = Snake(Position(1, 3));
    EXPECT_TRUE(snake.CheckBoundaryCollision(topLeft, bottomRight));
}

TEST_F(SnakeTests, BodyCollisionFalse) {
    snake = Snake(Direction::RIGHT, Position(1, 1));
    MoveAndGrow(Direction::RIGHT);
    MoveAndGrow(Direction::RIGHT);
    MoveAndGrow(Direction::DOWN);
    MoveAndGrow(Direction::LEFT);
    MoveAndGrow(Direction::LEFT);
    EXPECT_FALSE(snake.CheckBodyCollision());
}

TEST_F(SnakeTests, BodyCollisionTrue) {
    snake = Snake(Direction::RIGHT, Position(1, 1));
    MoveAndGrow(Direction::RIGHT);
    MoveAndGrow(Direction::RIGHT);
    MoveAndGrow(Direction::RIGHT);
    MoveAndGrow(Direction::DOWN);
    MoveAndGrow(Direction::DOWN);
    MoveAndGrow(Direction::LEFT);
    MoveAndGrow(Direction::LEFT);
    MoveAndGrow(Direction::UP);
    MoveAndGrow(Direction::UP);
    EXPECT_TRUE(snake.CheckBodyCollision());
}

TEST_F(SnakeTests, CheckHeadCollisionTrue) {
    Position position(1, 1);
    snake = Snake(position);
    EXPECT_TRUE(snake.CheckHeadCollision(position));
}

TEST_F(SnakeTests, CheckHeadCollisionFalse) {
    Position position(1, 1);
    snake.Move();
    EXPECT_FALSE(snake.CheckHeadCollision(position));
}

TEST_F(SnakeTests, CheckCollisionTrueForAnyPositionOccupiedByBody) {
    snake = Snake(Direction::RIGHT, Position(1, 1));
    MoveAndGrow(Direction::RIGHT);
    MoveAndGrow(Direction::RIGHT);
    MoveAndGrow(Direction::UP);
    EXPECT_TRUE(snake.CheckCollision(Position(1, 1)));
    EXPECT_TRUE(snake.CheckCollision(Position(2, 1))); 
    EXPECT_TRUE(snake.CheckCollision(Position(3, 1)));
    EXPECT_TRUE(snake.CheckCollision(Position(3, 2)));
}

TEST_F(SnakeTests, CheckCollisionFalseForPositionsOutsideBody) {
    snake = Snake(Direction::RIGHT, Position(1, 1));
    MoveAndGrow(Direction::RIGHT);
    MoveAndGrow(Direction::RIGHT);
    MoveAndGrow(Direction::UP);
    EXPECT_FALSE(snake.CheckCollision(Position(3, 4)));
    EXPECT_FALSE(snake.CheckCollision(Position(1, 0))); 
    EXPECT_FALSE(snake.CheckCollision(Position(2, 8)));
    EXPECT_FALSE(snake.CheckCollision(Position(9, -1)));
}


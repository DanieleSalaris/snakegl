#include "Board.h"

bool Board::CheckCollisions()
{
    return CheckBoundaryCollision() || CheckSnakeCollision();
}

bool Board::CheckBoundaryCollision()
{
    return snake.CheckBoundaryCollision(Position(0, 0), Position(rows-1, columns-1));
}

bool Board::CheckSnakeCollision()
{
    return snake.CheckBodyCollision();
}

bool Board::CheckFoodCollision()
{
    return snake.CheckHeadCollision(food.position);
}

void Board::GenerateFood()
{
    Position position(random.Next() % rows, random.Next() % columns);
    if (snake.CheckCollision(position))
        position = FindFirstFreePosition(position);
    food.position = position;
}

Position Board::FindFirstFreePosition(Position startingPosition)
{
    Position result;
    for (int i = startingPosition.x; i < rows; i++)
    {
        for (int j = startingPosition.y; j < columns; j++)
        {
            result.x = i;
            result.y = j;
            if (!snake.CheckCollision(result))
            {
                return result;
            }
        }
    }
    for (int i = 0; i < startingPosition.x; i++)
    {
        for (int j = 0;  j < startingPosition.y; j++)
        {
            result.x = i;
            result.y = j;
            if (!snake.CheckCollision(result))
            {
                return result;
            }
        }
    }
    return result;
}

Board::Board() : Board(10, 10) { }

Board::Board(int rows, int columns) {
    if (rows < 2) rows = 2;
    if (columns < 2) columns = 2;
    this->rows = rows;
    this->columns = columns;
    Init();
}

void Board::Init()
{
    snake = Snake(Direction::RIGHT, Position(1, 1), 2);
    GenerateFood();
    gameRunning = true;
}

void Board::NextStep()
{
    if (!gameRunning)
    {
        return;
    }

    if (CheckCollisions())
    {
        gameRunning = false;
        return;
    }

    snake.Move();
    if (CheckFoodCollision())
    {
        snake.Grow();
        GenerateFood();
    }
}

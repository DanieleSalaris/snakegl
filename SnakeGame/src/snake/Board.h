#pragma once
#include "Snake.h"
#include "Entity.h"
#include "Random.h"

class Board
{
private:
	int rows;
	int columns;
	bool gameRunning;
	Entity food;
	Snake snake;
	Random random;

	bool CheckCollisions();
	bool CheckBoundaryCollision();
	bool CheckSnakeCollision();
	bool CheckFoodCollision();
	void GenerateFood();

	Position FindFirstFreePosition(Position startingPosition);
	

public:
	Board();
	Board(int rows, int cols);

	void Init();
	void NextStep();
};


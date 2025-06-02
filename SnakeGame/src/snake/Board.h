#pragma once
#include "Snake.h"
#include "Entity.h"
#include "Random.h"
#include "SnakeFactory.h"
#include <memory>

class Board
{
private:
	int rows;
	int columns;
	bool gameRunning;
	Entity food;
	std::unique_ptr<Snake> snake;
	std::unique_ptr<Random> random;
	std::unique_ptr<SnakeFactory> snakeFactory;

	bool CheckCollisions();
	bool CheckBoundaryCollision();
	bool CheckSnakeCollision();
	bool CheckFoodCollision();
	void GenerateFood();

	Position FindFirstFreePosition(Position startingPosition);
	

public:
	Board(Random* random, SnakeFactory* snakeFactory);
	Board(Random* random, SnakeFactory* snakeFactory, int rows, int cols);

	void Init();
	void NextStep();
	void SetSnakeDirection(Direction direction);
	const inline Snake& GetSnake() { return *snake; }
	inline const Position GetFoodPosition() const { return food.position; }
	inline int GetRows() const { return rows; }
	inline int GetColumns() const { return columns; }
	inline bool isGameRunning() const { return gameRunning; }
};


#pragma once
#include "Snake.h"
class SnakePositionsSerializer
{
private:
	const Snake* snake;
	
public:
	SnakePositionsSerializer(const Snake* snake);
	void setSnake(const Snake* snake) { this->snake = snake; }
	const Snake* getSnake() { return snake; }
protected:
	virtual void ConsumePosition(Position& position) = 0;
	virtual void Serialize();
};


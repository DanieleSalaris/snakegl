#pragma once
#include "Snake.h"
class SnakePositionsSerializer
{
private:
	Snake* snake;
	
public:
	SnakePositionsSerializer(Snake* snake);
protected:
	virtual void ConsumePosition(Position& position) = 0;
	virtual void Serialize();
};


#pragma once
#include "Snake.h"

class SnakeFactory
{
public:
	virtual Snake* Create(Direction direction, Position position, int size) = 0;
};

class SnakeFactoryImpl : public SnakeFactory
{
public:
	Snake* Create(Direction direction, Position position, int size) override;
};

 
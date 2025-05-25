#include "SnakeFactory.h"

Snake* SnakeFactoryImpl::Create(Direction direction, Position position, int size)
{
	return new Snake(direction, position, size);
}

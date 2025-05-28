#include "SnakePositionsSerializer.h"

SnakePositionsSerializer::SnakePositionsSerializer(Snake* snake): snake(snake) {}

void SnakePositionsSerializer::Serialize()
{
	auto body = snake->body;
	for (auto e : body) {
		ConsumePosition(e.position);
	}
}

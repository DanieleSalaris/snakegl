#include "SnakeGridVertexSerializer.h"

SnakePositionToGridVertexSerializer::SnakePositionToGridVertexSerializer(const GridVertexMapper* gridVertexMapper, const Snake* snake):
	SnakePositionsSerializer(snake), gridVertexMapper(gridVertexMapper) {}

void SnakePositionToGridVertexSerializer::ConsumePosition(Position& position)
{
	positions = positions + gridVertexMapper->getCellPosition(position.y, position.x);
}

void SnakePositionToGridVertexSerializer::Serialize()
{
	positions = Positions();
	SnakePositionsSerializer::Serialize();
}

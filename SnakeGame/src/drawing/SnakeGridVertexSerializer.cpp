#include "SnakeGridVertexSerializer.h"

SnakePositionToGridVertexSerializer::SnakePositionToGridVertexSerializer(GridVertexMapper* gridVertexMapper, Snake* snake):
	SnakePositionsSerializer(snake), gridVertexMapper(gridVertexMapper) {}

void SnakePositionToGridVertexSerializer::ConsumePosition(Position& position)
{
	positions = positions + gridVertexMapper->getCellPosition(position.x, position.y);
}

void SnakePositionToGridVertexSerializer::Serialize()
{
	positions = Positions();
	SnakePositionsSerializer::Serialize();
}

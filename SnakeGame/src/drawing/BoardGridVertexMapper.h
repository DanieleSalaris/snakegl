#pragma once
#include "./GridVertexMapper.h"
#include "./SnakeGridVertexSerializer.h"
#include "../snake/Board.h"
class BoardGridVertexMapper
{
private:
	Board* board;
	SnakePositionToGridVertexSerializer* snakeSerializer;
	GridVertexMapper* gridVertexMapper;

public:
	BoardGridVertexMapper(Board* board, SnakePositionToGridVertexSerializer* snakeSerializer);
	Positions Serialize();
};


#pragma once
#include "../snake/SnakePositionsSerializer.h"
#include "GridVertexMapper.h"

class SnakePositionToGridVertexSerializer: public SnakePositionsSerializer 
{
private:
	GridVertexMapper* gridVertexMapper;
	Positions positions;
public:
	SnakePositionToGridVertexSerializer(GridVertexMapper* gridVertexMapper, Snake* snake);
	void ConsumePosition(Position& position) override;
	void Serialize() override;

};


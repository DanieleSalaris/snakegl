#pragma once
#include "../snake/SnakePositionsSerializer.h"
#include "GridVertexMapper.h"

class SnakePositionToGridVertexSerializer: public SnakePositionsSerializer 
{
private:
	const GridVertexMapper* gridVertexMapper;
	Positions positions;
public:
	SnakePositionToGridVertexSerializer(const GridVertexMapper* gridVertexMapper, const Snake* snake);
	void ConsumePosition(Position& position) override;
	void Serialize() override;
    inline const Positions& getPositions() const { return positions; }
};


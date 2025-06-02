#pragma once
#include <thread>
#include <mutex>
#include "snake/Board.h"
#include "drawing/SnakeGridVertexSerializer.h"
#include "drawing/BoardGridVertexMapper.h"

class GameLoop
{
private:
	std::thread gameThread;
	std::mutex positionsMutex;
	std::mutex closeThreadMutex;
	Positions positions;
	Positions threadSafePositions;
	BoardGridVertexMapper* boardGridVertexMapper;
	Board* board;
	GridVertexMapper* gridVertexMapper;
	SnakePositionToGridVertexSerializer* snakeSerializer;
	bool positionChanged = false;
	bool closeThread = false;
	void PollPositions();
	void Run();
public:
	GameLoop();
	~GameLoop();
	Positions& GetPositions();
};

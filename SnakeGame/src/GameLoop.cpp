#include "GameLoop.h"
#include "drawing/BoardGridVertexMapper.h"
#include <chrono>

void GameLoop::PollPositions()
{
	positionsMutex.lock();
	if (positionChanged)
	{
		threadSafePositions = positions;
		positionChanged = false;
	}
	positionsMutex.unlock();
}

void GameLoop::Run()
{
	while (true) {
		closeThreadMutex.lock();
		if (closeThread) {
			closeThreadMutex.unlock();
			break;
		}
		closeThreadMutex.unlock();
		if (!board->isGameRunning())
		{
			std::this_thread::sleep_for(std::chrono::seconds(3));
			board->Init();
		}
		board->NextStep();
		positionsMutex.lock();
		positions = boardGridVertexMapper->Serialize();
		positionChanged = true;
		positionsMutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

Positions& GameLoop::GetPositions()
{
	PollPositions();
	return threadSafePositions;
}

GameLoop::GameLoop() { 

		board = new Board(new RandomImpl(), new SnakeFactoryImpl());
		gridVertexMapper = new GridVertexMapper(board->GetRows(), board->GetColumns());
		snakeSerializer = new SnakePositionToGridVertexSerializer(gridVertexMapper, &board->GetSnake());
		boardGridVertexMapper = new BoardGridVertexMapper(board, snakeSerializer);

		gameThread = std::thread(&GameLoop::Run, this);
}

GameLoop::~GameLoop()
{
	closeThreadMutex.lock();
	closeThread = true;
	closeThreadMutex.unlock();
	gameThread.join();
	delete boardGridVertexMapper;
	delete snakeSerializer;
	delete board;
}

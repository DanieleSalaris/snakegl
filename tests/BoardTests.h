#pragma once
#include <queue>
#include "pch.h"
#include "../SnakeGame/src/snake/Board.h"

class MockRandom : public Random {
public:
	std::queue<int> values;
	int Next() override {
		if (values.empty()) {
			return 0;
		}
		int result = values.front();
		values.pop();
		return result;
	}

	void inline push(int value) {
		values.push(value);
	}
};

class MockSnakeFactory : public SnakeFactory {
private:
	SnakeFactoryImpl snakeFactory;
	int createCall = 0;
public:
	int inline getCreateCall() const {
		return createCall;
	}
	Snake* Create(Direction direction, Position position, int size) {
		createCall++;
		return snakeFactory.Create(direction, position, size);
	}
};

class BoardTests: public testing::Test
{
public:
	MockRandom* random;
	MockSnakeFactory* snakeFactory;
	Board* board;

	BoardTests() {
		random = new MockRandom();
		snakeFactory = new MockSnakeFactory();
		board = new Board(random, snakeFactory);

	}
	
	~BoardTests() {
		// board also delete random and snakeFactory
		delete board;
	}
};


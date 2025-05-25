#include "pch.h"
#include "BoardTests.h"
#include "../SnakeGame/src/snake/Random.h"

TEST_F(BoardTests, BoardInitShouldCreateSnake) {
	int initialCall = snakeFactory->getCreateCall();
	board->Init();
	int createCall = snakeFactory->getCreateCall();
	EXPECT_EQ(createCall - initialCall, 1);
}

TEST_F(BoardTests, BoardInitNTimesShouldCreateSankeNTimes) {
	int initialCall = snakeFactory->getCreateCall();
	int n = 17;
	for (int i = 0; i < n; i++) {
		board->Init();
	}
	int createCall = snakeFactory->getCreateCall();
	EXPECT_EQ(createCall - initialCall, n);
}

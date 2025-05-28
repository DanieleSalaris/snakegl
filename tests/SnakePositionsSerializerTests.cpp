#include "pch.h"
#include "SnakePositionsSerializerTests.h"

SnakePositionSerializerMock::SnakePositionSerializerMock(Snake* snake): SnakePositionsSerializer(snake) {}

void SnakePositionSerializerMock::ConsumePosition(Position& position)
{
	if (bufferLength >= SnakePositionSerializerMock::BUFFER_MAX_LENGTH) return;
	positionBuffer[bufferLength++] = position;
}

void SnakePositionSerializerMock::Serialize()
{
	bufferLength = 0;
	SnakePositionsSerializer::Serialize();
}

TEST_F(SnakePositionsSerializerTests, SerializeNewSnakeShouldConsumeFirstPosition)
{
	snakePositionsSerializer->Serialize();
	EXPECT_EQ(snakePositionsSerializer->bufferLength, startingSize);
	EXPECT_EQ(snakePositionsSerializer->positionBuffer[0], startingPosition);
}

TEST_F(SnakePositionsSerializerTests, TestSerializeAfterMoves)
{
	Position expectedPositions[4] = {Position(2, 3), Position(2, 2), Position(2, 1), Position(1, 1)};
	MoveAndGrow(Direction::RIGHT);
	MoveAndGrow(Direction::UP);
	MoveAndGrow(Direction::UP);

	snakePositionsSerializer->Serialize();

	for (int i = 0; i < 4; i++) {
		EXPECT_EQ(snakePositionsSerializer->positionBuffer[i], expectedPositions[i]);
	}
}


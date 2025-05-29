#include "BoardGridVertexMapper.h"

BoardGridVertexMapper::BoardGridVertexMapper(Board* board, SnakePositionToGridVertexSerializer* snakeSerializer) :
    board(board), snakeSerializer(snakeSerializer)
{
    gridVertexMapper = new GridVertexMapper(board->GetFoodPosition().x, board->GetFoodPosition().y);
}

Positions BoardGridVertexMapper::Serialize()
{
    snakeSerializer->setSnake(&board->GetSnake());
    Position food = board->GetFoodPosition();
    snakeSerializer->Serialize();

    const Positions& snakePositions = snakeSerializer->getPositions();
    Positions foodPositions = gridVertexMapper->getCellPosition(food.x, food.y);
    return foodPositions + snakePositions;
}

#pragma once
#include "VertexArrayBuffer.h"
#include "VertexBuffer.h"
#include "../utility/Array.h"
#include "Drawing.h"

class GridVertexMapper
{
private:
	int rows;
	int columns;
	
public:
	GridVertexMapper();
	GridVertexMapper(int rows, int columns);
	Positions getCellPosition(int row, int column);
};
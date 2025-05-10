#include "GridVertexMapper.h"

GridVertexMapper::GridVertexMapper() : GridVertexMapper(1, 1) {}

GridVertexMapper::GridVertexMapper(int rows, int columns): rows(rows), columns(columns) { }

Positions GridVertexMapper::getCellPosition(int row, int column) {
	float rowUnit = 2.0f / rows;
	float columnUnit = 2.0f / columns;
	float rowStart = (rowUnit * row) - 1;
	float rowEnd = (rowUnit * (row + 1)) - 1;
	float columnStart = (columnUnit * column) - 1;
	float columnEnd = (columnUnit * (column + 1)) - 1;
	Positions positions = {
		{ columnStart, rowStart, 1.0f, columnStart, rowEnd, 1.0f, columnEnd, rowStart, 1.0f, columnEnd, rowEnd, 1.0f },
		{ 0, 1, 2, 1, 2, 3 }
	};
	return positions;
}

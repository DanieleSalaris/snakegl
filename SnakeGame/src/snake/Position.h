#pragma once
class Position
{
public:
	int x;
	int y;

	Position();
	Position(int x, int y);
	
	Position operator+ (Position& o);
	Position& operator+= (const Position& o);
	bool operator==(const Position& o) const;
	bool operator!=(const Position& o) const;
};


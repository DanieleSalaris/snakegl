#include "Position.h"

Position::Position() : Position(0, 0) {}

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Position Position::operator+(Position& o)
{
    return Position(x + o.x, y + o.y);
}

Position& Position::operator+=(const Position& o) {
    x += o.x;
    y += o.y;
    return *this;
}

bool Position::operator==(const Position& o) const {
    return x == o.x && y == o.y;
}

bool Position::operator!=(const Position& o) const
{
    return x != o.x || y != o.y;
}

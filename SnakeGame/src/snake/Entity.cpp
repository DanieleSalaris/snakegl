#include "Entity.h"

Entity::Entity() : Entity(Position(0, 0)) { }

Entity::Entity(Position position) : position(position) { }

bool Entity::CheckCollision(Entity e)
{
    return position == e.position;
}


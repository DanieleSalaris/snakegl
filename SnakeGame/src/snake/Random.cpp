#include "Random.h"
#include <ctime>
#include <cstdlib>

Random::Random() : Random(std::time({})) {}

Random::Random(int seed)
{
    std::srand(seed);
}

int Random::Next()
{
    return std::rand();
}

#include "Random.h"
#include <ctime>
#include <cstdlib>

RandomImpl::RandomImpl() : RandomImpl(std::time({})) {}

RandomImpl::RandomImpl(int seed)
{
    std::srand(seed);
}

int RandomImpl::Next()
{
    return std::rand();
}

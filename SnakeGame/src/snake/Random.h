#pragma once
class Random
{
public:
	virtual int Next() = 0;
};

class RandomImpl : public Random {
public:
	RandomImpl();
	RandomImpl(int seed);
	int Next() override;
};


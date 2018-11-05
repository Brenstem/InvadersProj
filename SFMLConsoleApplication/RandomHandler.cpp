#include "RandomHandler.h"

mt19937 RandomHandler::mGenerator;

RandomHandler::RandomHandler()
{
}

RandomHandler::~RandomHandler()
{
}

float RandomHandler::getRandomNumber(float min, float max)
{
	uniform_int_distribution<uint32_t> randomRange(min, max);
	return randomRange(mGenerator);
}

bool RandomHandler::getRandomBool()
{
	float value = getRandomNumber(0.0f, 1.0f);
	if (value > 0.5f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

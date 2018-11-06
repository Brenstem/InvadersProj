#include "RandomHandler.h"

// Declaring static variables
mt19937 RandomHandler::mGenerator;

// Constructor/Destructor
RandomHandler::RandomHandler()
{
}

RandomHandler::~RandomHandler()
{
}

// Public functions
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

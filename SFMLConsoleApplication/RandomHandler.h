#ifndef INCLUDE_RANDOMHANDLER_H
#define INCLUDE_RANDOMHANDLER_H
#include <random>

using namespace std;

class RandomHandler
{
public:
	// Constructor/Destructor
	RandomHandler();
	~RandomHandler();

	// Public functions
	float getRandomNumber(float min, float max);
	bool getRandomBool();

private:
	// Member variables
	static mt19937 mGenerator;

};

#endif // !INCLUDE_RANDOMHANDLER_H

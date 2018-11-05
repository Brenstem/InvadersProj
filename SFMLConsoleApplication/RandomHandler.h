#ifndef INCLUDE_RANDOMHANDLER_H
#define INCLUDE_RANDOMHANDLER_H
#include <random>

using namespace std;

class RandomHandler
{
public:
	RandomHandler();
	~RandomHandler();
	float getRandomNumber(float min, float max);
	bool getRandomBool();

private:
	static mt19937 mGenerator;

};

#endif // !INCLUDE_RANDOMHANDLER_H

#ifndef INCLUDED_INVADERSHANDLER_H
#define INCLUDED_INVADERSHANDLER_H
#include "RandomHandler.h"
#include "InvaderObject.h"

typedef vector<Object*> ObjectVector;

class InvadersHandler
{
public:
	// Constructor/Destructor
	InvadersHandler(Game *game);
	~InvadersHandler();

	// Public functions
	void spawnInvaders(float deltaTime);

private:
	// Member variables
	RandomHandler mRandomHandler;
	ObjectVector &mObjects;
	Game *mGame;
	float mSpawnCountModifier;
	float mSpawnCounter;
	int mDifficulty;

	// Private functions
	void spawnInvader();
	float getSpawnDirection();
};

#endif // !INCLUDED_INVADERSHANDLER_H

#include "InvadersHandler.h"

// Settings namespace
namespace {
	const float SPAWN_BASE = 2.0f;
	const float SPAWN_INCREMENT = 0.9f;
}

// Constructor/Destructor
InvadersHandler::InvadersHandler(Game * game) :
	mGame(game)
	, mObjects(game->getObjectVector())
	, mRandomHandler()
	, mSpawnCountModifier(SPAWN_BASE)
	, mSpawnCounter(0)
	, mDifficulty(1)
{
}

InvadersHandler::~InvadersHandler()
{
}

// Public functions
void InvadersHandler::spawnInvaders(float deltaTime)
{
	mSpawnCounter += deltaTime;
	if (mSpawnCounter > mSpawnCountModifier)
	{
		spawnInvader();

		mSpawnCountModifier *= SPAWN_INCREMENT;


		mSpawnCounter = 0;
	}
}

// Private functions
void InvadersHandler::spawnInvader()
{
	Vector2f position = Vector2f(mRandomHandler.getRandomNumber(50, mGame->getRenderWindow().getSize().x), -50);
	Vector2f direction = Vector2f(getSpawnDirection(), 1);
	InvaderObject *invader = new InvaderObject(mGame, position, direction);
	invader->setFireRate(mDifficulty);
	if (mSpawnCountModifier < 0.5f)
	{
		mDifficulty++;
		mSpawnCountModifier = SPAWN_BASE;
	}
	mObjects.push_back(invader);
}

float InvadersHandler::getSpawnDirection()
{
	bool value = mRandomHandler.getRandomBool();

	if (value)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

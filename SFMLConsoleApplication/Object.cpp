#include "Object.h"

// Constructor/Destructor
Object::Object(Game *game) :
	mGame(game)
	, isDead(false)
{
}

Object::~Object()
{
}

// Public functions
bool Object::checkDeath()
{
	return isDead;
}

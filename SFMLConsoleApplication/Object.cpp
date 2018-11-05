#include "Object.h"

Object::Object(Game *game) :
	mGame(game)
	, isDead(false)
{
}

Object::~Object()
{
}

bool Object::checkDeath()
{
	return isDead;
}

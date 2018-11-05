#include "PlayerObject.h"
#include "Game.h"
#include <iostream>

namespace {
	const std::string textureFilename = "Ship.psd";
	const float RADIUS = 32.0f;
	const float FIRE_RATE = 2.0f;
	const float VELOCITY = 200.0f;
}


PlayerObject::PlayerObject(Game *game) :
	Object(game)
	, mSprite(game->createSprite(textureFilename, Vector2f(354, 850)))
{
}

PlayerObject::~PlayerObject() 
{
}

void PlayerObject::collide(Object * objectCollidedWith)
{
}

void PlayerObject::update()
{
}

void PlayerObject::draw()
{
	mGame->draw(mSprite);
}

EntityFaction PlayerObject::getFaction()
{
	return EntityFaction::FRIEND;
}

EntityType PlayerObject::getType()
{
	return EntityType::SHIP;
}

sf::Vector2f PlayerObject::getPosition()
{
	return mSprite.getPosition();
}

float PlayerObject::getRadius()
{
	return mRadius;
}

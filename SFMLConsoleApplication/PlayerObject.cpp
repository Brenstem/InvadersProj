#include "PlayerObject.h"
#include <string>

namespace {
	const std::string textureFilename = "Ship.psd";
	const float RADIUS = 32.0f;
	const float FIRE_RATE = 2.0f;
	const float VELOCITY = 200.0f;
}

PlayerObject::PlayerObject(Game * game) : 
	Object(game) 
{
	
}

PlayerObject::~PlayerObject()
{
}

sf::Vector2f PlayerObject::getPos()
{
	return mSprite.getPosition();
}

ObjectType PlayerObject::getType()
{
	return ObjectType::PlayerObject;
}

ObjectFaction PlayerObject::getFaction()
{
	return ObjectFaction::FRIEND();
}

void PlayerObject::update(float deltaTime)
{
}

void PlayerObject::collide(Object * objectCollidedWith)
{
}

void PlayerObject::draw()
{
	mGame->run();
}

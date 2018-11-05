#include "ExplosionObject.h"

namespace {
	const std::string textureFilename = "Explosion.psd";
	const float RADIUS = 32.0f;
	const float LIFETIMER = 0.1f;
}

ExplosionObject::ExplosionObject(Game * game, Vector2f position) : 
	Object(game)
	, mSprite(mGame->createSprite(textureFilename, position))
	, mLifeTimer(0)
	, mLifeLength(LIFETIMER)
	, mRadius(RADIUS)
{
}

ExplosionObject::~ExplosionObject()
{
}

void ExplosionObject::collide(Object * objectCollidedWith)
{
	isDead = false;
}

void ExplosionObject::update(float deltaTime)
{
	mLifeTimer += deltaTime;
	if (mLifeTimer > mLifeLength)
	{
		isDead = true;
		mLifeTimer = 0;
	}
}

void ExplosionObject::draw()
{
	mGame->draw(mSprite);
}

ObjectFaction ExplosionObject::getFaction()
{
	return ObjectFaction::NEUTRAL;
}

ObjectType ExplosionObject::getType()
{
	return ObjectType::EFFECT;
}

sf::Vector2f ExplosionObject::getPosition()
{
	return mSprite.getPosition();
}

float ExplosionObject::getRadius()
{
	return mRadius;
}

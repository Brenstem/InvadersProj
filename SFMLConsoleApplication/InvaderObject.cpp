#include "InvaderObject.h"
#include <cmath>

// Settings namespace
namespace {
	const std::string textureFilename = "Invader.psd";
	const float RADIUS = 32.0f;
	const float FIRE_RATE = 1.0f;
	const float FIRERATE_MODIFIER = 0.9f;
	const float VELOCITY = 200.0f;
	const Vector2f STARTPOSITION = Vector2f(0, 0);
}

// Constructor/Destructor
InvaderObject::InvaderObject(Game * game, Vector2f position, Vector2f direction) :
	Object(game)
	, mSprite(mGame->createSprite(textureFilename, STARTPOSITION))
	, mPosition(position)
	, mDirection(direction)
	, mVelocity(VELOCITY)
	, mRadius(RADIUS)
	, mFireRate(1/FIRE_RATE)
	, mFireTimer(0)
{
	mSprite.setPosition(mPosition);

}

InvaderObject::~InvaderObject()
{
}

// Public functions
void InvaderObject::draw()
{
	mGame->draw(mSprite);
}

void InvaderObject::update(float deltaTime)
{
	handleMovement(deltaTime);
	handleFiring(deltaTime);
}

void InvaderObject::collide(Object * objectCollidedWith)
{
	if (objectCollidedWith->getFaction() == ObjectFaction::FRIEND)
	{
		mGame->add(new ExplosionObject(mGame, getPosition()));
		isDead = true;
	}
}

// Getters/Setters
ObjectFaction InvaderObject::getFaction()
{
	return ObjectFaction::ENEMY;
}

ObjectType InvaderObject::getType()
{
	return ObjectType::SHIP;
}

sf::Vector2f InvaderObject::getPosition()
{
	return mSprite.getPosition();
}

float InvaderObject::getRadius()
{
	return mRadius;
}

void InvaderObject::setFireRate(int modifier)
{
	mFireRate *= pow(FIRERATE_MODIFIER, modifier);
}

// Private functions
void InvaderObject::handleMovement(float deltaTime)
{
	float minX = mRadius;
	float maxX = mGame->getRenderWindow().getSize().x - mRadius;
	Vector2f position = mSprite.getPosition();
	if (position.x < minX)
	{
		position.x = minX;
		mDirection.x = -mDirection.x;
	}
	else if (maxX < position.x)
	{
		position.x = maxX;
		mDirection.x = -mDirection.x;
	}
	mSprite.move(deltaTime * mVelocity * mDirection);
}

void InvaderObject::handleFiring(float deltaTime)
{
	mFireTimer += deltaTime;
	if (mFireRate < mFireTimer)
	{
		mGame->add(new BulletObject(mGame, getFaction(), getPosition(), Vector2f(0, 1)));
		mFireTimer = 0;
	}
}






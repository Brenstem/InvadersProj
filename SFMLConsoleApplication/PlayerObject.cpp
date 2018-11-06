#include "PlayerObject.h"
#include <iostream>

// Settings namespace
namespace {
	const std::string textureFilename = "Ship.psd";
	const float RADIUS = 32.0f;
	const float FIRE_RATE = 2.0f;
	const float VELOCITY = 400.0f;
	const Vector2f STARTPOSITION = Vector2f(350, 850);
}

// Constructor/Destructor
PlayerObject::PlayerObject(Game *game) :
	Object(game)
	, mSprite(mGame->createSprite(textureFilename, STARTPOSITION))
	, mRadius(RADIUS)
	, mVelocity(VELOCITY)
	, mFireRate(1 / FIRE_RATE)
	, mFireTimer(0)
{
}

PlayerObject::~PlayerObject() 
{
}

// Public functions
void PlayerObject::update(float deltaTime)
{
	updatePosition(deltaTime);
	constrainPosition();
	handleFiring(deltaTime);
}

void PlayerObject::draw()
{
	mGame->draw(mSprite);
}

void PlayerObject::collide(Object * objectCollidedWith)
{
	if (objectCollidedWith->getFaction() == ObjectFaction::ENEMY)
	{
		isDead = true;
		mGame->killGame();
	}
}

// Getters/Setters
ObjectFaction PlayerObject::getFaction()
{
	return ObjectFaction::FRIEND;
}

ObjectType PlayerObject::getType()
{
	return ObjectType::SHIP;
}

sf::Vector2f PlayerObject::getPosition()
{
	return mSprite.getPosition();
}

float PlayerObject::getRadius()
{
	return mRadius;
}

// Private functions
void PlayerObject::updatePosition(float deltaTime)
{
	float directionX = 0.0f;
	float directionY = 0.0f;
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		directionX -= 1.0f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		directionX += 1.0f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		directionY -= 1.0f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		directionY += 1.0f;
	}
	Vector2f direction(directionX, directionY);
	mSprite.move(deltaTime * mVelocity * direction);
}

void PlayerObject::constrainPosition()
{
	Vector2f windowSize = Vector2f((float(mGame->getRenderWindow().getSize().x)), (float(mGame->getRenderWindow().getSize().y)));
	float minXY = mRadius;
	float maxX = windowSize.x - minXY;
	float maxY = windowSize.y - minXY;
	float xPos = mSprite.getPosition().x;
	float yPos = mSprite.getPosition().y;

	if (xPos < minXY)
	{
		xPos = minXY;
	}
	else if (xPos > maxX)
	{
		xPos = maxX;
	}
	if (yPos < minXY)
	{
		yPos = minXY;
	}
	else if (yPos > maxY)
	{
		yPos = maxY;
	}
	Vector2f shipPos(xPos, yPos);
	mSprite.setPosition(shipPos);
}

void PlayerObject::handleFiring(float deltaTime)
{
	mFireTimer += deltaTime;
	if (mFireRate < mFireTimer && Keyboard::isKeyPressed(Keyboard::Space))
	{
		mGame->add(new BulletObject(mGame, getFaction(), getPosition(), Vector2f(0.25f, -1)));
		mGame->add(new BulletObject(mGame, getFaction(), getPosition(), Vector2f(0, -1)));
		mGame->add(new BulletObject(mGame, getFaction(), getPosition(), Vector2f(-0.25f, -1)));

		mFireTimer = 0;
	}
}




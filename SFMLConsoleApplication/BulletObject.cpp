#include "BulletObject.h"

using namespace sf;

namespace {
	const std::string textureFilename = "Bullet.psd";
	const float RADIUS = 32.0f;
	const float VELOCITY = 600.0f;
}

BulletObject::BulletObject(Game *game, ObjectFaction category, Vector2f position, Vector2f direction) :
	Object(game)
	, mSprite(mGame->createSprite(textureFilename, position))
	, mRadius(RADIUS)
	, mVelocity(VELOCITY)
	, mCategory(category)
	, mDirection(direction)
{
}

BulletObject::~BulletObject()
{
}

void BulletObject::collide(Object * objectCollidedWith)
{
	if (objectCollidedWith->getType() != ObjectType::PROJECTILE && objectCollidedWith->getFaction() != getFaction())
	{
		isDead = true;
	}
}

void BulletObject::update(float deltaTime)
{
	handleMovement(deltaTime);
}

void BulletObject::draw()
{
	mGame->draw(mSprite);
}

ObjectFaction BulletObject::getFaction()
{
	return mCategory;
}

ObjectType BulletObject::getType()
{
	return ObjectType::PROJECTILE;
}

Vector2f BulletObject::getPosition()
{
	return mSprite.getPosition();
}

float BulletObject::getRadius()
{
	return mRadius;
}

void BulletObject::handleMovement(float deltaTime)
{
	mSprite.move(deltaTime * mVelocity * mDirection);
}


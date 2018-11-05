#include "BulletObject.h"

using namespace sf;

namespace {
	const std::string textureFilename = "Bullet.psd";
	const float RADIUS = 32.0f;
	const float VELOCITY = 800.0f;
}

BulletObject::BulletObject(Game *game, EntityFaction category, Vector2f position, Vector2f direction) :
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
}

void BulletObject::update(float deltaTime)
{
	handleMovement(deltaTime);
}

void BulletObject::draw()
{
	mGame->draw(mSprite);
}

EntityFaction BulletObject::getFaction()
{
	return mCategory;
}

EntityType BulletObject::getType()
{
	return EntityType::PROJECTILE;
}

Vector2f BulletObject::getPosition()
{
	return mPosition;
}

float BulletObject::getRadius()
{
	return mRadius;
}

void BulletObject::handleMovement(float deltaTime)
{
	mSprite.move(deltaTime * mVelocity * mDirection);
}


#ifndef INCLUDED_PLAYEROBJECT_H
#define INCLUDED_PLAYEROBJECT_H
#include "Object.h"
#include "Game.h"
#include "BulletObject.h"


using namespace sf;

class PlayerObject : public Object
{
public:
	PlayerObject(Game *game);
	~PlayerObject();

	virtual void collide(Object *objectCollidedWith) override;
	virtual void update(float deltaTime) override;
	virtual void draw() override;

	virtual EntityFaction getFaction() override;
	virtual EntityType getType() override;
	virtual Vector2f getPosition() override;
	virtual float getRadius() override;

private:
	Sprite mSprite;
	float mRadius;
	Vector2f mPosition;
	float mVelocity;

	float mFireTimer;
	float mFireRate;

	void updatePosition(float deltaTime);
	void constrainPosition();

	void handleFiring(float deltaTime);
};

#endif // !INCLUDED_PLAYEROBJECT_H

#ifndef INCLUDE_BULLETOBJECT_H
#define INCLUDE_BULLETOBJECT_H
#include "Object.h"
#include "Game.h"

using namespace sf;

class BulletObject : public Object
{
public:
	BulletObject(Game *game, EntityFaction category, Vector2f position, Vector2f direction);
	~BulletObject();

	virtual void collide(Object *objectCollidedWith) override;
	virtual void update(float deltaTime) override;
	virtual void draw() override;

	virtual EntityFaction getFaction() override;
	virtual EntityType getType() override;
	virtual Vector2f getPosition() override;
	virtual float getRadius() override;

private:
	EntityFaction mCategory;
	Vector2f mPosition;
	Vector2f mDirection;
	Sprite mSprite;

	float mVelocity;
	float mRadius;

	void handleMovement(float deltaTime);
};

#endif // !INCLUDE_BULLETOBJECT_H

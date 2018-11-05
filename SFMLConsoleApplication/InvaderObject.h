#ifndef INCLUDE_INVADEROBJECT_H
#define INCLUDE_INVADEROBJECT_H
#include "Object.h"
#include "Game.h"
#include "BulletObject.h"

using namespace sf;

class InvaderObject : public Object
{
public:
	InvaderObject(Game *game, Vector2f position, Vector2f direction);
	~InvaderObject();

	virtual void draw() override;
	virtual void update(float deltaTime) override;
	virtual void collide(Object *objectCollidedWith) override;

	virtual EntityFaction getFaction() override;
	virtual EntityType getType() override;
	virtual sf::Vector2f getPosition() override;
	virtual float getRadius() override;

private:
	Sprite mSprite;
	Vector2f mDirection;
	Vector2f mPosition;

	float mVelocity;
	float mRadius;
	float mFireRate;
	float mFireTimer;



	void handleMovement(float deltaTime);
	void handleFiring(float deltaTime);
};


#endif // !INCLUDE_INVADEROBJECT_H

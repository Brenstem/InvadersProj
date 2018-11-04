#ifndef INCLUDE_PLAYEROBJECT_H
#define INCLUDE_PLAYEROBJECT_H

#include "Object.h"

class PlayerObject : public Object
{
public:
	PlayerObject(Game *game);
	~PlayerObject();
	virtual sf::Vector2f getPos() override;
	virtual ObjectType getType() override;
	virtual ObjectFaction getFaction() override;
	virtual void update(float deltaTime) override;
	virtual void collide(Object *objectCollidedWith) override;
	virtual void draw() override;

private:
	sf::Sprite mSprite;
	float mRadius;
	float mFireRate;
	float mVelocity;

	void handleMovement();
	void handleFiring();
};


#endif // !INCLUDE_PLAYEROBJECT_H

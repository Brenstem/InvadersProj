#ifndef INCLUDED_PLAYEROBJECT_H
#define INCLUDED_PLAYEROBJECT_H
#include "Object.h"

using namespace sf;

class PlayerObject : public Object
{
public:
	PlayerObject(Game *game);
	~PlayerObject();

	virtual void collide(Object *objectCollidedWith) override;
	virtual void update() override;
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
};

#endif // !INCLUDED_PLAYEROBJECT_H

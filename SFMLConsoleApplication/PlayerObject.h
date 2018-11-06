#ifndef INCLUDED_PLAYEROBJECT_H
#define INCLUDED_PLAYEROBJECT_H
#include "Object.h"
#include "BulletObject.h"

class PlayerObject : public Object
{
public:
	// Constructor/Destructor
	PlayerObject(Game *game);
	~PlayerObject();

	// Public functions
	virtual void collide(Object *objectCollidedWith) override;
	virtual void update(float deltaTime) override;
	virtual void draw() override;

	// Getters/Setters
	virtual ObjectFaction getFaction() override;
	virtual ObjectType getType() override;
	virtual Vector2f getPosition() override;
	virtual float getRadius() override;

private:
	// Member variables
	Sprite mSprite;
	Vector2f mPosition;
	float mRadius;
	float mVelocity;
	float mFireTimer;
	float mFireRate;

	// Private functions
	void updatePosition(float deltaTime);
	void constrainPosition();
	void handleFiring(float deltaTime);
};

#endif // !INCLUDED_PLAYEROBJECT_H

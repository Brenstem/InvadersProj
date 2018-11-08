#ifndef INCLUDE_BULLETOBJECT_H
#define INCLUDE_BULLETOBJECT_H
#include "Object.h"
#include "Game.h"


class BulletObject : public Object
{
public:
	// Constructor/Destructor
	BulletObject(Game *game, ObjectFaction category, Vector2f position, Vector2f direction);
	~BulletObject();

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
	ObjectFaction mCategory;
	Vector2f mPosition;
	Vector2f mDirection;
	Sprite mSprite;
	float mVelocity;
	float mRadius;

	// Private functions
	void handleMovement(float deltaTime);

};

#endif // !INCLUDE_BULLETOBJECT_H

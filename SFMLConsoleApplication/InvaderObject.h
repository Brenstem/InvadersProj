#ifndef INCLUDE_INVADEROBJECT_H
#define INCLUDE_INVADEROBJECT_H
#include "Object.h"
#include "BulletObject.h"
#include "ExplosionObject.h"

class InvaderObject : public Object
{
public:
	// Constructor/Destructor
	InvaderObject(Game *game, Vector2f position, Vector2f direction);
	~InvaderObject();

	// Public functions
	virtual void draw() override;
	virtual void update(float deltaTime) override;
	virtual void collide(Object *objectCollidedWith) override;

	// Getters/Setters
	virtual ObjectFaction getFaction() override;
	virtual ObjectType getType() override;
	virtual sf::Vector2f getPosition() override;
	virtual float getRadius() override;
	void setFireRate(int modifier);

private:
	// Member variables
	Sprite mSprite;
	Vector2f mDirection;
	Vector2f mPosition;
	float mVelocity;
	float mRadius;
	float mFireRate;
	float mFireTimer;

	// Private functions
	void handleMovement(float deltaTime);
	void handleFiring(float deltaTime);
};


#endif // !INCLUDE_INVADEROBJECT_H

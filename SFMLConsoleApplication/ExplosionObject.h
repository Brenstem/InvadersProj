#ifndef INCLUDE_EXPLOSIONOBJECT_H
#define INCLUDE_EXPLOSIONOBJECT_H
#include "Object.h"
#include "Game.h"

class ExplosionObject : public Object
{
public:
	// Constructor/Destructor
	ExplosionObject(Game *game, Vector2f position);
	~ExplosionObject();

	// Public functions
	virtual void collide(Object *objectCollidedWith) override;
	virtual void update(float deltaTime) override;
	virtual void draw() override;

	// Getters/Setters
	virtual ObjectFaction getFaction() override;
	virtual ObjectType getType() override;
	virtual sf::Vector2f getPosition() override;
	virtual float getRadius() override;

private:
	// Member variables
	ObjectFaction mCategory;
	Sprite mSprite;
	float mLifeTimer;
	float mLifeLength;
	float mRadius;
};


#endif // !INCLUDE_EXPLOSIONOBJECT_H

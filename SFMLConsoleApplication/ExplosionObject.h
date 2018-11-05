#ifndef INCLUDE_EXPLOSIONOBJECT_H
#define INCLUDE_EXPLOSIONOBJECT_H
#include "Object.h"
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "ExplosionObject.h"

using namespace sf;

class ExplosionObject : public Object
{
public:
	ExplosionObject(Game *game, Vector2f position);
	~ExplosionObject();

	virtual void collide(Object *objectCollidedWith) override;
	virtual void update(float deltaTime) override;
	virtual void draw() override;

	virtual ObjectFaction getFaction() override;
	virtual ObjectType getType() override;
	virtual sf::Vector2f getPosition() override;
	virtual float getRadius() override;

private:
	ObjectFaction mCategory;
	Sprite mSprite;

	float mLifeTimer;
	float mLifeLength;
	float mRadius;
};


#endif // !INCLUDE_EXPLOSIONOBJECT_H

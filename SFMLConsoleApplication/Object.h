#ifndef INCLUDE_OBJECT_H
#define INCLUDE_OBJECT_H
#include "SFML/Graphics.hpp"

class ResourceHandler;
class Game;

enum class ObjectType { PROJECTILE, SHIP, EFFECT };
enum class ObjectFaction { FRIEND, ENEMY, NEUTRAL };

class Object
{
public:
	Object(Game *game);
	~Object();

	virtual void collide(Object *objectCollidedWith) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw() = 0;

	virtual ObjectFaction getFaction() = 0;
	virtual ObjectType getType() = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual float getRadius() = 0;
	bool checkDeath();

protected:
	Game *mGame;
	bool isDead;
};

#endif // !INCLUDE_OBJECT_H


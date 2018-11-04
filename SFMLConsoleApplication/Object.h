#ifndef INCLUDE_OBJECT_H
#define INCLUDE_OBJECT_H

#include "SFML/Graphics.hpp"

class Game;

enum class ObjectType { PROJECTILE, PlayerObject, EFFECT };
enum class ObjectFaction { FRIEND, ENEMY, NEUTRAL };

class Object
{
public:
	Object(Game *game);
	virtual ~Object();
	virtual float getRad() = 0;
	virtual sf::Vector2f getPos() = 0;
	virtual ObjectType getType() = 0;
	virtual ObjectFaction getFaction() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void collide(Object *objectCollidedWith) = 0;
	virtual void draw() = 0;

protected:
	Game *mGame;
};

#endif // !INCLUDE_OBJECT_H


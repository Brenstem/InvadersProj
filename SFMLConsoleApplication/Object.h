#ifndef INCLUDE_OBJECT_H
#define INCLUDE_OBJECT_H
#include "SFML/Graphics.hpp"
class Game;

enum class ObjectType { PROJECTILE, SHIP, EFFECT };
enum class ObjectFaction { FRIEND, ENEMY, NEUTRAL };

using namespace sf;

class Object
{
public:
	// Constructor/Destructor
	Object(Game *game);
	~Object();

	// Public functions
	virtual void collide(Object *objectCollidedWith) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw() = 0;

	// Getters/Setters
	virtual ObjectFaction getFaction() = 0;
	virtual ObjectType getType() = 0;
	virtual Vector2f getPosition() = 0;
	virtual float getRadius() = 0;
	bool checkDeath();

protected:
	// Member variables
	Game *mGame;
	bool isDead;
};

#endif // !INCLUDE_OBJECT_H


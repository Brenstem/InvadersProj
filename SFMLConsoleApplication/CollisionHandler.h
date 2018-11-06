#ifndef INCLUDED_COLLISIONHANDLER_H
#define INCLUDED_COLLISIONHANDLER_H
#include "Game.h"
#include "Object.h"

typedef vector<Object*> ObjectVector;

class CollisionHandler
{
public:
	// Constructor/Destructor
	CollisionHandler(ObjectVector &objects);
	~CollisionHandler();

	// Public functions
	void collideEntities();

private:
	// Member variables
	ObjectVector &mObjects;

	// Private functions
	bool overlap(Vector2f position0, float rad0, Vector2f position1, float rad1);
	bool overlap(Object *object0, Object *object1);
};
#endif // !INCLUDED_COLLISIONHANDLER_H

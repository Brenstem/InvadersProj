#include "CollisionHandler.h"

using namespace sf;

// Constructor/Destructor
CollisionHandler::CollisionHandler(ObjectVector & objects) : 
	mObjects(objects)
{
}

CollisionHandler::~CollisionHandler()
{
}

// Public functions
void CollisionHandler::collideEntities()
{
	for (int i = 0; i < mObjects.size(); i++)
	{
		Object *object0 = mObjects[i];
		for (int j = i + 1; j < mObjects.size(); j++)
		{
			Object *object1 = mObjects[j];
			if (overlap(object0, object1))
			{
				object0->collide(object1);
				object1->collide(object0);
			}
		}
	}
}

// Private functions
bool CollisionHandler::overlap(Vector2f position0, float rad0, Vector2f position1, float rad1)
{
	float deltaX = position0.x - position1.x;
	float deltaY = position0.y - position1.y;
	float radiusSum = rad0 + rad1;
	float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
	return  distance <= radiusSum;
}

bool CollisionHandler::overlap(Object * object0, Object * object1)
{
	Vector2f pos0 = object0->getPosition();
	float rad0 = object0->getRadius();
	Vector2f pos1 = object1->getPosition();
	float rad1 = object1->getRadius();

	return overlap(pos0, rad0, pos1, rad1);
}

#include "ObjectHandler.h"

// Constructor/Destructor
ObjectHandler::ObjectHandler(Game * game) : 
	mGame(game)
	, mObjects(mGame->getObjectVector())
{
}

ObjectHandler::~ObjectHandler()
{
}

// Public functions
void ObjectHandler::updateObjects(float deltaTime)
{
	for (size_t i = 0; i < mObjects.size(); i++)
	{
		Object *object = mObjects[i];

		object->update(deltaTime);
	}
	drawObjects();
}

void ObjectHandler::pruneObjects()
{
	handleOutOfBounds();
	ObjectVector remainingObjects;
	for (ObjectVector::size_type i = 0; i < mObjects.size(); i++)
	{
		if (mObjects[i]->checkDeath() == false)
		{
			remainingObjects.push_back(mObjects[i]);
		}
		else
		{
			delete mObjects[i];
		}
	}
	mObjects = remainingObjects;
}

void ObjectHandler::draw(sf::Sprite & sprite)
{
	mGame->getRenderWindow().draw(sprite);

}

void ObjectHandler::add(Object * object)
{
	mObjects.push_back(object);

}

// Private functions
void ObjectHandler::drawObjects(ObjectType type)
{
	for (size_t i = 0; i < mObjects.size(); i++)
	{
		Object *object = mObjects[i];
		if (object->getType() == type)
		{
			object->draw();
		}
	}
}

void ObjectHandler::drawObjects()
{
	drawObjects(ObjectType::PROJECTILE);
	drawObjects(ObjectType::SHIP);
	drawObjects(ObjectType::EFFECT);
}

void ObjectHandler::handleOutOfBounds()
{
	float minY = -100;
	float maxY = mGame->getRenderWindow().getSize().y + 100;
	ObjectVector remainingObjects;
	for (ObjectVector::size_type i = 0; i < mObjects.size(); i++)
	{
		if (mObjects[i]->getPosition().y < maxY && mObjects[i]->getPosition().y > minY)
		{
			remainingObjects.push_back(mObjects[i]);
		}
		else
		{
			delete mObjects[i];
		}
	}
	mObjects = remainingObjects;
}

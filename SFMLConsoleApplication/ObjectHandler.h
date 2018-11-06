#ifndef INCLUDED_OBJECTHANDLER_H
#define INLCUDED_OBJECTHANDLER_H
#include "Object.h"
#include "game.h"

typedef vector<Object*> ObjectVector;

class ObjectHandler
{
public:
	// Constructor/Destructor
	ObjectHandler(Game *game);
	~ObjectHandler();

	// Public functions
	void updateObjects(float deltaTime);
	void pruneObjects();
	void draw(sf::Sprite &sprite);
	void add(Object *object);

private:
	// Member variables
	Game *mGame;
	ObjectVector &mObjects;

	// Private functions
	void drawObjects(ObjectType type);
	void drawObjects();
	void handleOutOfBounds();
};

#endif // !INCLUDED_OBJECTHANDLER_H

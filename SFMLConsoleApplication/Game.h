#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
class Object;

using namespace std;
using namespace sf;

typedef vector<Object*> ObjectVector;

class Game
{
public:
	// Constructor/Destructor
	Game();
	~Game();
	// Public functions
	virtual void run() = 0;
	virtual Sprite createSprite(string fileName, Vector2f position) = 0;
	virtual void draw(Sprite &sprite) = 0;
	virtual void add(Object *object) = 0;
	virtual void killGame() = 0;

	// Getters/Setters
	virtual RenderWindow &getRenderWindow() = 0;
	virtual ObjectVector &getObjectVector() = 0;
};

#endif // !INCLUDE_GAME_H


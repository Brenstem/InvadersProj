#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include "Object.h"

class Object;

using namespace std;

class Game
{
public:
	Game();
	~Game();
	virtual void run() = 0;
	virtual sf::Sprite createSprite(string fileName, sf::Vector2f position) = 0;
	virtual void draw(sf::Sprite &sprite) = 0;	virtual sf::RenderWindow& getRenderWindow() = 0;	virtual bool isVisable(Object *object) = 0;	virtual void add(Object *object) = 0;
private:

};

#endif // !INCLUDE_GAME_H


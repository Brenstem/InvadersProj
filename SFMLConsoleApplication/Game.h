#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H

#include <string>
#include "SFML/Graphics.hpp"
#include "WindowHandler.h"
#include "ResourceHandler.h"

class Object;

using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();

	Texture getTexture(std::string fileName);

private:
	RenderWindow mRenderWindow;
	bool mGameOver;

	WindowHandler mWindowHandler;
	ResourceHandler mResourceHandler;

};

#endif // !INCLUDE_GAME_H


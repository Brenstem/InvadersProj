#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H

#include "SFML/Graphics.hpp"
#include "WindowHandler.h"

class Object;

using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	RenderWindow mRenderWindow;
	bool mGameOver;
	WindowHandler mWindowHandler;
};

#endif // !INCLUDE_GAME_H


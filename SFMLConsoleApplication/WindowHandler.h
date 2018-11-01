#ifndef INCLUDE_WINDOWHANDLE_H
#define INCLUDE_WINDOWHANDLE_H

#include "SFML/Graphics.hpp"

using namespace sf;

class WindowHandler
{
public:
	WindowHandler(RenderWindow &renderWindow, Color backgroundColor);
	~WindowHandler();

	void handleWindowEvents();
	void clearWindow();
	void displayWindow();

private:
	RenderWindow &mRenderWindow;
	Color mBackgroundColor;
};

#endif // !INCLUDE_WINDOWHANDLE_H

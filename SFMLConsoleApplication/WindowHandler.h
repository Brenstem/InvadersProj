#ifndef INCLUDE_WINDOWHANDLE_H
#define INCLUDE_WINDOWHANDLE_H
#include "SFML/Graphics.hpp"

using namespace sf;

class WindowHandler
{
public:
	// Constructor/Destructor
	WindowHandler(RenderWindow &renderWindow);
	~WindowHandler();

	// Public functions
	void handleWindowEvents();
	void displayWindow();

private:
	// Member variables
	RenderWindow &mRenderWindow;
	Color mBackgroundColor;

	// Private function
	void clearWindow();
};

#endif // !INCLUDE_WINDOWHANDLE_H

#include "WindowHandler.h"

namespace {
	const Color backgroundColor = Color::Black;
}

// Constructor/Destructor
WindowHandler::WindowHandler(RenderWindow &renderWindow) : 
	mRenderWindow(renderWindow)
	, mBackgroundColor(backgroundColor)
{
}

WindowHandler::~WindowHandler()
{
}

// Public functions
void WindowHandler::handleWindowEvents()
{
	Event event;
	while (mRenderWindow.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			mRenderWindow.close();
		}
	}
	clearWindow();
}

void WindowHandler::displayWindow()
{
	mRenderWindow.display();
}

// Private function
void WindowHandler::clearWindow()
{
	mRenderWindow.clear(mBackgroundColor);
}


#include "WindowHandler.h"

WindowHandler::WindowHandler(RenderWindow &renderWindow, Color backgroundColor) : 
	mRenderWindow(renderWindow)
	, mBackgroundColor(backgroundColor)
{

}

WindowHandler::~WindowHandler()
{
}


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
}

void WindowHandler::clearWindow()
{
	mRenderWindow.clear(mBackgroundColor);
}

void WindowHandler::displayWindow()
{
	mRenderWindow.display();
}
#include "Game.h"

namespace {
	const String windowTitle = "Asteroids";
	const VideoMode videoMode = VideoMode(768, 1024);
	const Color backgroundColor = Color::Black;
}

Game::Game():
	mRenderWindow(videoMode, windowTitle, Style::Titlebar | Style::Close)
	, mWindowHandler(mRenderWindow, backgroundColor)
	, mGameOver(false)
{

}

Game::~Game()
{
}

void Game::run() 
{
	Clock frameClock;
	while (!mGameOver && mRenderWindow.isOpen())
	{
		float deltaTime = frameClock.restart().asSeconds();

		mWindowHandler.handleWindowEvents();
		mWindowHandler.clearWindow();
		mWindowHandler.displayWindow();
	}

}
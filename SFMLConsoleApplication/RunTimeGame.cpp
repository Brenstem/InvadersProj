#include "RunTimeGame.h"

// Settings namespace
namespace {
	const String windowTitle = "Invaders";
	const VideoMode videoMode = VideoMode(768, 1024);
}

// Constructor/Destructor
RunTimeGame::RunTimeGame() :
	mRenderWindow(videoMode, windowTitle, Style::Titlebar | Style::Close)
	, mWindowHandler(mRenderWindow)
	, mSpriteHandler()
	, mObjectHandler(this)
	, mCollisionHandler(mObjects)
	, mInvadersHandler(this)
	, mGameOver(false)
	, mObjects()
{
	mObjects.push_back(new PlayerObject(this));
}

RunTimeGame::~RunTimeGame()
{
}

// Game Loop
void RunTimeGame::run()
{
	Clock frameClock;
	while (!mGameOver && mRenderWindow.isOpen())
	{
		float deltaTime = frameClock.restart().asSeconds();

		mWindowHandler.handleWindowEvents();

		mInvadersHandler.spawnInvaders(deltaTime);

		mObjectHandler.updateObjects(deltaTime);


		mCollisionHandler.collideEntities();

		mObjectHandler.pruneObjects();
		
		mWindowHandler.displayWindow();
	}
}

// Public functions
Sprite RunTimeGame::createSprite(string fileName, Vector2f position)
{
	return mSpriteHandler.createSprite(fileName, position);
}

void RunTimeGame::draw(Sprite & sprite)
{
	mObjectHandler.draw(sprite);
}

void RunTimeGame::add(Object * object)
{
	mObjectHandler.add(object);
}


// Getters/Setters
sf::RenderWindow& RunTimeGame::getRenderWindow()
{
	return mRenderWindow;
}

void RunTimeGame::killGame()
{
	mGameOver = true;
}

ObjectVector& RunTimeGame::getObjectVector()
{
	return mObjects;
}

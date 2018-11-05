#include "RunTimeGame.h"
#include "BulletObject.h"
#include <iostream>

namespace {
	const String windowTitle = "Invaders";
	const VideoMode videoMode = VideoMode(768, 1024);
	const Color backgroundColor = Color::Black;
}

RunTimeGame::RunTimeGame() :
	mRenderWindow(videoMode, windowTitle, Style::Titlebar | Style::Close)
	, mWindowHandler(mRenderWindow, backgroundColor)
	, mSpriteHandler()
	, mGameOver(false)
{
	mObjects.push_back(new PlayerObject(this));
}

RunTimeGame::~RunTimeGame()
{
}


void RunTimeGame::run()
{
	Clock frameClock;
	while (!mGameOver && mRenderWindow.isOpen())
	{
		float deltaTime = frameClock.restart().asSeconds();

		mWindowHandler.handleWindowEvents();
		mWindowHandler.clearWindow();

		updateObjects(deltaTime);
		drawObjects();

		mWindowHandler.displayWindow();
	}
}

//Sprite Creation
Sprite RunTimeGame::createSprite(string fileName, Vector2f position)
{
	return mSpriteHandler.createSprite(fileName, position);
}


//Object handling
void RunTimeGame::drawObjects(EntityType type)
{
	for (size_t i = 0; i < mObjects.size(); i++)
	{
		Object *object = mObjects[i];
		if (object->getType() == type)
		{
			object->draw();
		}
	}
}

void RunTimeGame::drawObjects()
{
	drawObjects(EntityType::PROJECTILE);
	drawObjects(EntityType::SHIP);
	drawObjects(EntityType::EFFECT);
}

void RunTimeGame::updateObjects(float deltaTime)
{
	for (size_t i = 0; i < mObjects.size(); i++)
	{
		Object *object = mObjects[i];

		object->update(deltaTime);
	}
}

void RunTimeGame::draw(sf::Sprite & sprite)
{
	mRenderWindow.draw(sprite);
}

bool RunTimeGame::isVisable(Object * object)
{
	return false;
}

void RunTimeGame::add(Object * object)
{
	std::cout << "added gameobject" << std::endl;
	mObjects.push_back(object);
	std::cout << mObjects.size();
}

//Getters
sf::RenderWindow& RunTimeGame::getRenderWindow()
{
	return mRenderWindow;
}





#include "RunTimeGame.h"
#include <iostream>

namespace {
	const String windowTitle = "Invaders";
	const VideoMode videoMode = VideoMode(768, 1024);
	const Color backgroundColor = Color::Black;
	const float SPAWN_BASE = 1.0f;
	const float SPAWN_INCREMENT = 0.98f;
}

RunTimeGame::RunTimeGame() :
	mRenderWindow(videoMode, windowTitle, Style::Titlebar | Style::Close)
	, mWindowHandler(mRenderWindow, backgroundColor)
	, mSpriteHandler()
	, mRandomHandler()
	, mGameOver(false)
	, mSpawnCounter(0)
	, mSpawnCountModifier(SPAWN_BASE)
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

		spawnInvaders(deltaTime);

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

void RunTimeGame::spawnInvader()
{
	Vector2f position = Vector2f(mRandomHandler.getRandomNumber(0, mRenderWindow.getSize().x), -10);
	Vector2f direction = Vector2f(getSpawnDirection(), 1);
	InvaderObject *invader = new InvaderObject(this, position, direction);
	mObjects.push_back(invader);
}

void RunTimeGame::spawnInvaders(float deltaTime)
{
	mSpawnCounter += deltaTime;
	if (mSpawnCounter > mSpawnCountModifier)
	{
		spawnInvader();
		mSpawnCounter = 0;
	}
}

float RunTimeGame::getSpawnDirection()
{
	bool value = mRandomHandler.getRandomBool();

	if (value)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void RunTimeGame::draw(sf::Sprite & sprite)
{
	mRenderWindow.draw(sprite);
}

bool RunTimeGame::isVisable(Object * object)
{
	return true;
}

void RunTimeGame::add(Object * object)
{
	mObjects.push_back(object);
}

//Getters
sf::RenderWindow& RunTimeGame::getRenderWindow()
{
	return mRenderWindow;
}
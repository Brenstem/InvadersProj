#include "RunTimeGame.h"
#include <iostream>

namespace {
	const String windowTitle = "Invaders";
	const VideoMode videoMode = VideoMode(768, 1024);
	const Color backgroundColor = Color::Black;
	const float SPAWN_BASE = 3.0f;
	const float SPAWN_INCREMENT = 0.99f;
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

		handleOutOfBounds();

		collideEntities();
		pruneObjects();
		
		mWindowHandler.displayWindow();
	}
}

//Sprite Creation
Sprite RunTimeGame::createSprite(string fileName, Vector2f position)
{
	return mSpriteHandler.createSprite(fileName, position);
}


//Object handling
void RunTimeGame::drawObjects(ObjectType type)
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
	drawObjects(ObjectType::PROJECTILE);
	drawObjects(ObjectType::SHIP);
	drawObjects(ObjectType::EFFECT);
}

void RunTimeGame::updateObjects(float deltaTime)
{
	for (size_t i = 0; i < mObjects.size(); i++)
	{
		Object *object = mObjects[i];

		object->update(deltaTime);
	}
}

void RunTimeGame::pruneObjects()
{
	ObjectVector remainingObjects;
	for (ObjectVector::size_type i = 0; i < mObjects.size(); i++)
	{
		if (mObjects[i]->checkDeath() == false)
		{
			remainingObjects.push_back(mObjects[i]);
		}
		else
		{
			std::cout << "Kill" << std::endl;
			delete mObjects[i];
		}	
	}
	mObjects = remainingObjects;
}

void RunTimeGame::handleOutOfBounds()
{
	float minY = -100;
	float maxY = mRenderWindow.getSize().y + 100;
	ObjectVector remainingObjects;
	for (ObjectVector::size_type i = 0; i < mObjects.size(); i++)
	{
		if (mObjects[i]->getPosition().y < maxY && mObjects[i]->getPosition().y > minY)
		{
			remainingObjects.push_back(mObjects[i]);
		}
		else
		{
			std::cout << "Out of bounds" << std::endl;
			delete mObjects[i];
		}
	}
	mObjects = remainingObjects;
}



//Invaders handling
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

void RunTimeGame::remove(Object * object)
{
	delete object;
}

//Collision handling
void RunTimeGame::collideEntities() 
{
	for (ObjectVector::size_type i = 0; i < mObjects.size(); i++)
	{
		Object *object0 = mObjects[i];
		for (ObjectVector::size_type j = i+1; j < mObjects.size(); j++)
		{
			Object *object1 = mObjects[j];
			if (overlap(object0, object1))
			{
				object0->collide(object1);
				object1->collide(object0);
			}
		}
	}
}

bool RunTimeGame::overlap(Vector2f position0, float rad0, Vector2f position1, float rad1)
{
	float deltaX = position0.x - position1.x;
	float deltaY = position0.y - position1.y;
	float radiusSum = rad0 + rad1;
	float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
	return  distance <= radiusSum;
}

bool RunTimeGame::overlap(Object *object0, Object *object1)
{
	Vector2f pos0 = object0->getPosition();
	float rad0 = object0->getRadius();
	Vector2f pos1 = object1->getPosition();
	float rad1= object1->getRadius();

	return overlap(pos0, rad0, pos1, rad1);
}

//Getters
sf::RenderWindow& RunTimeGame::getRenderWindow()
{
	return mRenderWindow;
}

void RunTimeGame::killGame()
{
	mGameOver = true;
}

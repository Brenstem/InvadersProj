#include "RunTimeGame.h"
#include <iostream>

namespace {
	const String windowTitle = "Invaders";
	const VideoMode videoMode = VideoMode(768, 1024);
	const Color backgroundColor = Color::Black;
}

RunTimeGame::RunTimeGame() :
	mRenderWindow(videoMode, windowTitle, Style::Titlebar | Style::Close)
	, mWindowHandler(mRenderWindow, backgroundColor)
	, mGameOver(false)
{
	objectVector.push_back(new PlayerObject(this));
	

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

		drawEntities();

		mWindowHandler.displayWindow();
	}

}

Sprite RunTimeGame::createSprite(string fileName, Vector2f position)
{
	Sprite sprite;
	Texture spriteTexture;

	for (size_t i = 0; i < textureVector.size(); i++)
	{
		std::cout << i;
		if (fileName == textureVector[i]->getName())
		{
			sprite.setTexture(textureVector[i]->getTexture());

			float originX = 0.5f * sprite.getLocalBounds().width;
			float originY = 0.5f * sprite.getLocalBounds().height;
			Vector2f origin(originX, originY);
			sprite.setOrigin(origin);
			sprite.setPosition(position); 

			return sprite;
			std::cout << "got texture from list";
		}
	}

	mTexturePointer = new TextureResource(fileName);
	textureVector.push_back(mTexturePointer);
	spriteTexture = mTexturePointer->getTexture();
	sprite.setTexture(spriteTexture);
	std::cout << "created new texture";

	float originX = 0.5f * sprite.getLocalBounds().width;
	float originY = 0.5f * sprite.getLocalBounds().height;
	Vector2f origin(originX, originY);
	sprite.setOrigin(origin);
	sprite.setPosition(position);

	return sprite;
}

void RunTimeGame::draw(sf::Sprite & sprite)
{
	mRenderWindow.draw(sprite);
}

void RunTimeGame::drawEntities(EntityType type)
{
	for (size_t i = 0; i < objectVector.size(); i++)
	{
		Object *object = objectVector[i];
		if (object->getType() == type)
		{
			object->draw();
		}
	}

}

void RunTimeGame::drawEntities()
{
	drawEntities(EntityType::PROJECTILE);
	drawEntities(EntityType::SHIP);
	drawEntities(EntityType::EFFECT);
}

#include "SpriteHandler.h"
#include <iostream>

SpriteHandler::SpriteHandler()
{
}

SpriteHandler::~SpriteHandler()
{
}

Sprite SpriteHandler::createSprite(std::string fileName, Vector2f position)
{
	Sprite sprite(getTexture(fileName));

	float originX = 0.5f * sprite.getLocalBounds().width;
	float originY = 0.5f * sprite.getLocalBounds().height;
	Vector2f origin(originX, originY);
	sprite.setOrigin(origin);
	sprite.setPosition(position);

	return sprite;
}

Texture & SpriteHandler::getTexture(std::string fileName)
{
	for (TextureResourceVector::size_type i = 0; i < mTextureResources.size(); i++)
	{
		if (fileName == mTextureResources[i]->getName())
		{
			return mTextureResources[i]->getTexture();
		}
	}

	Texture t;
	t.loadFromFile(fileName);
	TextureResource *tResource = new TextureResource(fileName, t);
	mTextureResources.push_back(tResource);
	return tResource->getTexture();
}


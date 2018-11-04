#include "ResourceHandler.h"

ResourceHandler::ResourceHandler(Game *game) : 
	mGame(game)
{
}

ResourceHandler::~ResourceHandler()
{
}

Sprite ResourceHandler::createSprite(string fileName, Vector2f position)
{
	Sprite sprite;
	Texture spriteTexture;

	for (size_t i = 0; i < textureVector.size(); i++)
	{
		if (fileName == textureVector[i]->getName())
		{
			spriteTexture = textureVector[i]->getTexture();
		}
		else
		{
			mTexturePointer = new TextureResource(fileName);
			textureVector.push_back(mTexturePointer);
			spriteTexture = mTexturePointer->getTexture();
		}
	}
	sprite.setTexture(spriteTexture);
	float originX = 0.5f * sprite.getLocalBounds().width;
	float originY = 0.5f * sprite.getLocalBounds().height;
	Vector2f origin(originX, originY);
	sprite.setOrigin(origin);
	sprite.setPosition(position);

	return sprite;

}

void ResourceHandler::createObject()
{
	mPlayer = new PlayerObject(mGame, this);
}


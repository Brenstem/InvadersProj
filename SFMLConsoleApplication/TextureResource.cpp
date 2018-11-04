#include "TextureResource.h"

TextureResource::TextureResource(std::string name) :
	mName(name)
{
	mTexture.loadFromFile(name);
}

TextureResource::~TextureResource()
{
}

std::string TextureResource::getName()
{
	return mName;
}

sf::Texture TextureResource::getTexture()
{
	return mTexture;
}

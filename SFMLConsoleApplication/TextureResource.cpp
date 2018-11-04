#include "TextureResource.h"

TextureResource::TextureResource(std::string fileName) : 
	mName(fileName)
{
	mTexture.loadFromFile(fileName);
}

TextureResource::~TextureResource()
{
}

Texture TextureResource::getTexture()
{
	return mTexture;
}

std::string TextureResource::getName()
{
	return mName;
}

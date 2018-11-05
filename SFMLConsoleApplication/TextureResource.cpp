#include "TextureResource.h"

TextureResource::TextureResource(std::string fileName, Texture texture) : 
	mName(fileName)
	, mTexture(texture)
{
}

TextureResource::~TextureResource()
{
}

Texture& TextureResource::getTexture()
{
	return mTexture;
}

std::string TextureResource::getName()
{
	return mName;
}

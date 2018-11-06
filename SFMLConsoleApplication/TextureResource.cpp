#include "TextureResource.h"

// Constructor/Destructor
TextureResource::TextureResource(std::string fileName, Texture texture) : 
	mName(fileName)
	, mTexture(texture)
{
}

TextureResource::~TextureResource()
{
}

// Getters/Setters
Texture& TextureResource::getTexture()
{
	return mTexture;
}

std::string TextureResource::getName()
{
	return mName;
}

#include "ResourceHandler.h"

using namespace std;

ResourceHandler::ResourceHandler()
{
}

ResourceHandler::~ResourceHandler()
{
}

void ResourceHandler::createTexture(string fileName)
{
	texturePointer = new TextureResource(fileName);
	textureVector.push_back(texturePointer);
}

Texture ResourceHandler::getTexture(std::string fileName)
{
	for (size_t i = 0; i < textureVector.size; i++)
	{
		if (fileName == textureVector[i]->getName())
		{
			return textureVector[i]->getTexture();
		}
	}
}

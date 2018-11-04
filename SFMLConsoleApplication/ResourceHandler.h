#ifndef INCLUDE_RESOURCEHANDLER_H
#define INCLUDE_RESOURCEHANDLER_H

#include <vector>
#include <string>
#include "TextureResource.h"

using namespace sf;

class ResourceHandler
{
public:
	ResourceHandler();
	~ResourceHandler();
	void createTexture(std::string fileName);

	Texture getTexture(std::string fileName);

private:
	typedef std::vector<TextureResource*> Textures;
	Textures textureVector;

	TextureResource *texturePointer;
};

#endif // !INCLUDE_RESOURCEHANDLER_H


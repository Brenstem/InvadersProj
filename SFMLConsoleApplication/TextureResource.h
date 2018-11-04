#ifndef INCLUDE_TEXTURERESOURCE_H
#define INCLUDE_TEXTURERESOURCE_H

#include "SFML/Graphics.hpp"
#include <string>

using namespace sf;

class TextureResource
{
public:
	TextureResource(std::string fileName);
	~TextureResource();

	Texture getTexture();
	std::string getName();

private:
	std::string mName;
	Texture mTexture;
};

#endif // !INCLUDE_TEXTURERESOURCE_H


#ifndef INCLUDE_TEXTURERESOURCE_H
#define INCLUDE_TEXTURERESOURCE_H

#include <string>
#include "SFML/Graphics.hpp"

class TextureResource
{
public:
	TextureResource(std::string name);
	~TextureResource();
	std::string getName();
	sf::Texture getTexture();

private:
	std::string mName;
	sf::Texture mTexture;

};


#endif // !INCLUDE_TEXTURERESOURCE_H

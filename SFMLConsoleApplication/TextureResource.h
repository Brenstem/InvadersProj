#ifndef INCLUDE_TEXTURERESOURCE_H
#define INCLUDE_TEXTURERESOURCE_H
#include "SFML/Graphics.hpp"
#include <string>

using namespace std;
using namespace sf;

class TextureResource
{
public:
	// Constructor/Destructor
	TextureResource(string fileName, Texture texture);
	~TextureResource();

	// Getters/Setters
	Texture& getTexture();
	string getName();

private:
	// Member variables
	string mName;
	Texture mTexture;
};

#endif // !INCLUDE_TEXTURERESOURCE_H


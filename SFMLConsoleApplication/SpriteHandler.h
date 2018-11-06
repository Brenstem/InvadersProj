#ifndef INCLUDE_SPRITECREATOR_H
#define INCLUDE_SPRITECREATOR_H
#include "SFML/Graphics.hpp"
#include "TextureResource.h"
#include <string>
#include <vector>

using namespace sf;

class SpriteHandler
{
public:
	// Constructor/Destructor
	SpriteHandler();
	~SpriteHandler();

	// Public functions
	Sprite createSprite(std::string fileName, Vector2f position);

private:
	// Member variables
	typedef std::vector<TextureResource*> TextureResourceVector;
	TextureResourceVector mTextureResources;

	// Private functions
	Texture& getTexture(std::string fileName);
};

#endif // !INCLUDE_SPRITECREATOR_H


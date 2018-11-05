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
	SpriteHandler();
	~SpriteHandler();
	Sprite createSprite(std::string fileName, Vector2f position);

private:
	typedef std::vector<TextureResource*> TextureResourceVector;
	TextureResourceVector mTextureResources;

	Texture& getTexture(std::string fileName);
};

#endif // !INCLUDE_SPRITECREATOR_H


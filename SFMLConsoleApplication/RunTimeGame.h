#ifndef INCLUDE_RUNTIMEGAME_H
#define INCLUDE_RUNTIMEGAME_H

#include "Game.h"
#include "WindowHandler.h"
#include "TextureResource.h"
#include "PlayerObject.h"

using namespace std;

class RunTimeGame : public Game
{
public:
	RunTimeGame();
	~RunTimeGame();
	virtual void run() override;
	virtual Sprite createSprite(string fileName, Vector2f position) override;
	virtual void draw(sf::Sprite &sprite) override;

private:
	RenderWindow mRenderWindow;
	bool mGameOver;

	WindowHandler mWindowHandler;

	typedef vector<TextureResource*> TextureResourceVector;
	typedef vector<Object*> ObjectVector;

	TextureResourceVector textureVector;
	ObjectVector objectVector;

	TextureResource *mTexturePointer;
	PlayerObject *mPlayer;
	Game *mGame;
	ResourceHandler *mResourceHandler;

	void drawEntities(EntityType type);
	void drawEntities();
	sf::Texture getTexture(string fileName);
};

#endif // !INCLUDE_RUNTIMEGAME_H


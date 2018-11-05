#ifndef INCLUDE_RUNTIMEGAME_H
#define INCLUDE_RUNTIMEGAME_H

#include "Game.h"
#include "WindowHandler.h"
#include "SpriteHandler.h"
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

	virtual bool isVisable(Object *object) override;
	virtual void add(Object *object) override;
	
	//Getters
	virtual sf::RenderWindow& getRenderWindow() override;	

private:
	//Member variables
	RenderWindow mRenderWindow;
	bool mGameOver;

	//Game Handlers
	WindowHandler mWindowHandler;
	SpriteHandler mSpriteHandler;

	//ObjectHandling
	typedef vector<Object*> ObjectVector;
	ObjectVector mObjects;
	void drawObjects(EntityType type);
	void drawObjects();
	void updateObjects(float deltaTime);

	PlayerObject *mPlayer;
	Game *mGame;
};

#endif // !INCLUDE_RUNTIMEGAME_H


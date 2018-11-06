#ifndef INCLUDE_RUNTIMEGAME_H
#define INCLUDE_RUNTIMEGAME_H
#include "Game.h"
#include "WindowHandler.h"
#include "CollisionHandler.h"
#include "InvadersHandler.h"
#include "ObjectHandler.h"
#include "SpriteHandler.h"
#include "PlayerObject.h"

using namespace std;
using namespace sf;

class RunTimeGame : public Game
{
public:
	// Constructor/Destructor
	RunTimeGame();
	~RunTimeGame();

	// Game Loop
	virtual void run() override;

	// Public functions
	virtual Sprite createSprite(string fileName, Vector2f position) override;
	virtual void draw(Sprite &sprite) override;
	virtual void add(Object *object) override;

	// Getters/Setters
	virtual RenderWindow &getRenderWindow() override;
	virtual void killGame() override;
	virtual ObjectVector &getObjectVector() override;

private:
	//Member variables
	RenderWindow mRenderWindow;
	ObjectVector mObjects;
	bool mGameOver;

	//Game Handlers
	WindowHandler mWindowHandler;
	SpriteHandler mSpriteHandler;
	CollisionHandler mCollisionHandler;
	InvadersHandler mInvadersHandler;
	ObjectHandler mObjectHandler;
};

#endif // !INCLUDE_RUNTIMEGAME_H


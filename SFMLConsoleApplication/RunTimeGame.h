#ifndef INCLUDE_RUNTIMEGAME_H
#define INCLUDE_RUNTIMEGAME_H

#include "Game.h"
#include "WindowHandler.h"
#include "SpriteHandler.h"
#include "RandomHandler.h"
#include "TextureResource.h"
#include "PlayerObject.h"
#include "InvaderObject.h"
#include <random>

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
	virtual void remove(Object *object) override;

	//Getters
	virtual sf::RenderWindow& getRenderWindow() override;
	virtual void killGame() override;
	

private:
	//Member variables
	RenderWindow mRenderWindow;
	bool mGameOver;

	//Game Handlers
	WindowHandler mWindowHandler;
	SpriteHandler mSpriteHandler;
	RandomHandler mRandomHandler;

	//ObjectHandling
	typedef vector<Object*> ObjectVector;
	ObjectVector mObjects;

	void drawObjects(ObjectType type);
	void drawObjects();
	void updateObjects(float deltaTime);
	void pruneObjects();
	void handleOutOfBounds();

	//Invader handling
	float mSpawnCountModifier;
	float mSpawnCounter;
	void spawnInvader();
	void spawnInvaders(float deltaTime);
	float getSpawnDirection();

	//Collision
	void collideEntities();
	bool overlap(Vector2f position0, float rad0, Vector2f position1, float rad1);
	bool overlap(Object *object0, Object *object1);
};

#endif // !INCLUDE_RUNTIMEGAME_H


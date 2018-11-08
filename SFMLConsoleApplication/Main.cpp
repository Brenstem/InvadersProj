#include "RunTimeGame.h"

int main(){
	RunTimeGame game;
	game.run();
}

/*
+ High cohesion for runtimeGame
+ runtimeGame is not a godclass and handles objects generally

? could one make a handler baseclass
? could runtimegame handle the handlers generally

*/
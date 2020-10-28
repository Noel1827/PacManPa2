#pragma once

#include "State.h"
#include "Button.h"
#include "GameState.h"
#include "Player.h"

class GameOverState : public State{
private:
Button * restartButton;
// TESTING
ofImage youdied;

public:
	GameOverState();
	void tick();
	 void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();

 
};
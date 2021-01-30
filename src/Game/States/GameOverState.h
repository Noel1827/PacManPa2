#pragma once

#include "State.h"
#include "Button.h"
#include "GameState.h"
#include "Player.h"

class GameOverState : public State{
private:
Button * restartButton;
long int score;
// TESTING
ofImage youdied;
ofSoundPlayer gameOver;

public:
	GameOverState();
	void tick();
	 void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void setFinalScore(int score);

 
};
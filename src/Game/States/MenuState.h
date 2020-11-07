#pragma once

#include "State.h"
#include "Button.h"
#include "GameState.h"

class MenuState : public State {
private:
	ofImage img1;
	ofImage pacman;
	ofSoundPlayer gameMusic;
	Button *startButton;
	bool loop = true;

public:
	MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};

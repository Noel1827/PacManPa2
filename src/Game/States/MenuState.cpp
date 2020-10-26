#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
	pacman.load("images/pacmanM.jpg");
	pacmanS.load("images/pacmanS.wav");
	pacmanS.play();
}
void MenuState::tick() {
	pacmanS.setLoop(true);
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}
void MenuState::render() {
	 ofSetColor(256,256,256);
	pacman.draw(0,0,ofGetWidth(), ofGetHeight());
	startButton->render();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}
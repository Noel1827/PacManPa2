#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
}
void GameState::tick() {
	map->tick();
}
void GameState::render() {
	map->render();
	ofSetColor(255,255,0);
	int PermanentX = 10;
	int sum = 0;
	for( int i = 0; i < lives;i++ ){
		ofDrawCircle(PermanentX + sum, 20, 10);
		sum += 20;
	}
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}
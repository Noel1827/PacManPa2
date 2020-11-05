#include "GameState.h"
#include "Entity.h"

GameState::GameState()
{
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
	gameMusic.load("images/gameMusic.wav");
	// gameMusic.play();

}
void GameState::tick()
{
	gameMusic.setLoop(loop);
	if (map->getPlayer()->getHealth() == 0)
	{
		loop = false;
		gameMusic.setLoop(loop);
		finalScore = map->getPlayer()->getScore();
		setNextState("GameOverState");
		setFinished(true);
		map->getPlayer()->SetHealth(3);
		map = MapBuilder().createMap(mapImage);
	}
	map->tick();
}
void GameState::render()
{
	map->render();

}

int GameState:: getScore(){
	return finalScore;
}
void GameState::keyPressed(int key)
{
	map->keyPressed(key);

}

void GameState::mousePressed(int x, int y, int button)
{
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key)
{
	map->keyReleased(key);
}

void GameState::reset()
{
	setFinished(false);
	setNextState("");
}
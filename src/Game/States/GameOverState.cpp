#include "GameOverState.h"

GameOverState::GameOverState()
{
    // cuanto toques el RE del restart no funcionará, tiene coordenadas de "start"
    restartButton = new Button(0, 0, ofGetWidth(), ofGetHeight(), "Click Anywhere To Start");
    youdied.load("images/you-died.png");
    // gameOver.load("images/gameOver.mp3");
    // gameOver.play();
}

void GameOverState::setFinalScore(int score){
this->score = score;
}

void GameOverState::tick()
{
    restartButton->tick();
    if (restartButton->wasPressed())
    {
        setNextState("Game");
        setFinished(true);
    }
}
void GameOverState::keyPressed(int key){

}

void GameOverState::render()
{
    youdied.draw(0,0,ofGetWidth(), ofGetHeight());
    ofSetColor(255,255,255);
    ofDrawBitmapString("Score:" + to_string(score),ofGetWidth()-100,20);
    restartButton->render();
}

void GameOverState::mousePressed(int x, int y, int button) {
    restartButton->mousePressed(x,y);
}

void GameOverState::reset(){
    setFinished(false);
    setNextState("");
    restartButton->reset();
}
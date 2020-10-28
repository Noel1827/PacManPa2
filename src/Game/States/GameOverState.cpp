#include "GameOverState.h"

GameOverState::GameOverState()
{
    // cuanto toques el RE del restart no funcionará
    restartButton = new Button(ofGetWidth() / 2, ofGetHeight() / 2, 64, 50, "Restart");
    youdied.load("images/you-died.png");
 
}

void GameOverState::setFinalScore(int score){
this->score = score;
}

void GameOverState::tick()
{
    restartButton->tick();
    if (restartButton->wasPressed())
    {
        // score = 0;
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
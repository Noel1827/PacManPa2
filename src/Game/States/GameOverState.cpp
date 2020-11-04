#include "GameOverState.h"

GameOverState::GameOverState()
{
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
    ofSetColor(255,170,0);
    ofDrawBitmapString("Images were from:" , 0, ofGetHeight() / 1.3 + 100);
    ofDrawBitmapString("https://c4.wallpaperflare.com/wallpaper/114/731/747/blue-pacman-gameboy-old-games-wallpaper-preview.jpg" , 0, ofGetHeight() / 1.3 + 110);
    ofDrawBitmapString("https://i2.wp.com/nerdmacia.cl/wp-content/uploads/2016/02/you-died.png?fit=1920%2C934&ssl=1" , 0, ofGetHeight() / 1.3 + 120);
    ofDrawBitmapString("Soundbytes were from:" , 0, ofGetHeight() / 1.3 + 130);
    ofDrawBitmapString("https://www.classicgaming.cc/classics/pac-man/sounds" , 0, ofGetHeight() / 1.3 + 140);
    ofDrawBitmapString("http://www.classicgaming.cc/classics/donkey-kong/sounds" , 0, ofGetHeight() / 1.3 + 150);
    ofDrawBitmapString("https://www.101soundboards.com/sounds/11321-game-over" , 0, ofGetHeight() / 1.3 + 160);
}

void GameOverState::mousePressed(int x, int y, int button) {
    restartButton->mousePressed(x,y);
}

void GameOverState::reset(){
    setFinished(false);
    setNextState("");
    restartButton->reset();
}
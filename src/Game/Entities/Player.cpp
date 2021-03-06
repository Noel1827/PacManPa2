#include "Player.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "MapBuilder.h"

Player::Player(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height){
    sprite.load("images/pacman.png");
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);
    gameOver.load("images/gameOver.mp3");
    
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);

    this->em = em;
    
}

int Player::getScore(){
    return score;
}

void Player::tick(){
    if(em->eatGhost == true){
        counter++;
        if(counter == 450){
            em->eatGhost = false;
            counter = 0;
        }
    }
    canMove = true;
    checkCollisions();
    if(canMove){
        if(facing == UP){
            y-= speed;
            walkUp->tick();
        }else if(facing == DOWN){
            y+=speed;
            walkDown->tick();
        }else if(facing == LEFT){
            x-=speed;
            walkLeft->tick();
        }else if(facing == RIGHT){
            x+=speed;
            walkRight->tick();
        }
    }
}

void Player::render(){
    ofSetColor(256, 256, 256);
    ofDrawBitmapString("Score:" + to_string(score), ofGetWidth() - 100, 20);
    if(facing == UP){
        walkUp->getCurrentFrame().draw(x, y, width, height);
        
    }else if(facing == DOWN){
        walkDown->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == LEFT){
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == RIGHT){
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }

    PermanentX = 10;
    sum = 0;
    // draws Pacman's lives
    for (int i = 0; i < health; i++)
    {
        // sets the colors to red, green, or yellow depending on pacman's life
        switch (health)
        {
        case 1:
            ofSetColor(255, 0, 0);
            break;
        case 2:
            ofSetColor(255, 255, 0);
            break;
        case 3:
            ofSetColor(0, 255, 0);
            break;
        }
        ofDrawCircle(PermanentX + sum, 20, 10);
        sum += 20;
    }
    ofSetColor(248,171,186);
    ofDrawBitmapString("WARINIG CODE IS PRONE TO CRASH WHEN USING THIS POWERUP", 0, 45);
    ofDrawBitmapString("Press 'f' to ignore all bounds, Pac-Man can still die",0, 55);
}

void Player::keyPressed(int key)
{
    switch (key)
    {
    case 'w':
        setFacing(UP);
        break;
    case 's':
        setFacing(DOWN);
        break;
    case 'a':
        setFacing(LEFT);
        break;
    case 'd':
        setFacing(RIGHT);
        break;
    case 'n':
        die();
        // health++;
        break;
    case 'f':
        trespassing = !trespassing;
        break;
    case 'm':
        // this switch is so that the integer lives won't be negative
        switch (health)
        {
        case 0:
            break;
        default:
            health--;
        }
    }
}

void Player::keyReleased(int key){
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}
void Player::mousePressed(int x, int y, int button){

}

void Player::setFacing(FACING facing){
    this->facing = facing;
}

void Player::checkCollisions(){
    if(trespassing == false){
    for(Block* block: em->blocks){
        switch(facing){
            case UP:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case DOWN:
                if(this->getBounds(x, y+speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case LEFT:
                if(this->getBounds(x-speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case RIGHT:
                if(this->getBounds(x+speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
        }
    }
    }
    else if(trespassing == true){
        canMove = true;
    }
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity)){
                entity->remove = true;
            }
            if(dynamic_cast<Dot*>(entity)){
                score+= 10;
            }else if( dynamic_cast<BigDot*>(entity)){
                score += 50;
                em->eatGhost = true;
                counter = 0;
            }
            else if(dynamic_cast<Ghost*>(entity)){
                if(em->eatGhost == false){
                die();
                gameOver.play();
                }
                else if(em->eatGhost == true){
                    entity->remove = true;
                    score += 200;
                    em->GhostCounter++;
                }
            }

        }
    }
    
}

void Player::die(){
    health--;
    this->x = RESPAWNXPOS;
    this->y = RESPAWNYPOS;
}

int Player::getHealth(){
    return health;
}

void Player::SetHealth(int health){
    this->health = health;
}



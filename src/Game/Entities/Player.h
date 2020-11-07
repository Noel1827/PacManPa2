#pragma once
#include "Animation.h"
#include "EntityManager.h"

enum FACING {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player: public Entity{

    private:
    int PermanentX;
	int sum;
	int health = 3;
    const int RESPAWNXPOS = 312;
    const int RESPAWNYPOS = 624;
    int counter = 0; 
        long int score = 0;
        bool canMove;
        int speed = 8;
        bool walking = false;
        bool trespassing = false;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;

    public:
    
        Player(int, int, int , int, EntityManager*);
        int getHealth();
        void die();
        void SetHealth(int health);
        int getScore();
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void setFacing(FACING facing);
        void checkCollisions();
};
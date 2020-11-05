#pragma once
#include "Entity.h"
#include "EntityManager.h"
#include "Player.h"
#include "BigDot.h"
#include "Animation.h"

enum GhostFACING{
    GUP,
    GDOWN,
    GLEFT,
    GRIGHT
};

class Ghost: public Entity{

private:
    bool canMove;
    GhostFACING Gfacing = GUP;
    int speed = 1;
    EntityManager *em;
    bool eatGhost;
    bool white;
    int counter = 0;
    int flashing = 0;
    // Animation flashing;

public:
    Ghost(int, int, int, int, ofImage, string, EntityManager *);
    void setEatGhost(bool eatGhost);
    void tick();
    void render();
    void move();
    void checkCollisions();
        
};

#pragma once
#include "Entity.h"
#include "EntityManager.h"
#include "Player.h"
#include "BigDot.h"

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
    int speed = 8;
    EntityManager *em;
    bool GhostFlash = false;
    bool white;
    int counter = 0;
    int flashing = 0;

public:
    Ghost(int, int, int, int, ofImage, string, EntityManager *);
    void tick();
    void move();
    void checkCollisions();
        
};

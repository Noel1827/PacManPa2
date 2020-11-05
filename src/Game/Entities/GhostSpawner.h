#pragma once
#include "Entity.h"
#include "EntityManager.h"
#include "Ghost.h"


class GhostSpawner : public Entity
{
public:
    GhostSpawner(int, int, int, int, ofImage, EntityManager *);
    void tick();
    void render();
    void keyPressed(int);
    void keyReleased(int);
    void mousePressed(int, int, int);

private:
    EntityManager *em;
    int ghostCounter = 0;
};
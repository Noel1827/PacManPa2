#include "GhostSpawner.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage spriteSheet, EntityManager* em): Entity(x, y, width, height){
    sprite = spriteSheet;
    this->em = em;
}

void GhostSpawner::tick(){
   // Can make ghost respawn if dead
}

void GhostSpawner:: render(){

}

void GhostSpawner:: keyPressed(int key){
if(key == 'g'){
    Ghost* GhostR = new Ghost(x ,y, width, height, sprite);
    em->entities.push_back(GhostR);
 }
}
#include "GhostSpawner.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage spriteSheet, EntityManager* em): Entity(x, y, width, height){
    sprite = spriteSheet;
    this->em = em;
    Ghost *RedGhost = new Ghost(x, y, width, height, sprite, "red");
    em->entities.push_back(RedGhost);
    Ghost *OrangeGhost = new Ghost(x, y, width, height, sprite, "orange");
     em->entities.push_back(OrangeGhost);
    Ghost *BlueGhost = new Ghost(x, y, width, height, sprite, "blue");
     em->entities.push_back(BlueGhost);
     Ghost *PinkGhost = new Ghost(x,y, width, height, sprite, "pink");
     em->entities.push_back(PinkGhost);
    
}

void GhostSpawner::tick(){
   // Can make ghost respawn if dead
}

void GhostSpawner:: render(){

}

void GhostSpawner:: keyPressed(int key){
if(key == 'g'){
    Ghost* GhostR = new Ghost(x ,y, width, height, sprite, "red");
   em->entities.push_back(GhostR); 
 }
}
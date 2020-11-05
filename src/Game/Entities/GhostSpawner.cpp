
#include "GhostSpawner.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage spriteSheet, EntityManager* em): Entity(x, y, width, height){
    sprite = spriteSheet;
    this->em = em;
    Ghost *RedGhost = new Ghost(x, y, width, height, sprite, "red", em);
    em->entities.push_back(RedGhost);
    Ghost *OrangeGhost = new Ghost(x, y, width, height, sprite, "orange", em);
     em->entities.push_back(OrangeGhost);
    Ghost *BlueGhost = new Ghost(x, y, width, height, sprite, "blue", em);
     em->entities.push_back(BlueGhost);
     Ghost *PinkGhost = new Ghost(x,y, width, height, sprite, "pink", em);
     em->entities.push_back(PinkGhost);
    
}

void GhostSpawner::tick(){
  // Can make ghost respawn if dead
  // ghostCounter++;
  // if (ghostCounter == 90)
  // {
  //   ghostCounter = 0;
  //   int random = ofRandom(4);
  //   if (random == 0)
  //   {
  //     Ghost *RedGhost = new Ghost(x, y, width, height, sprite, "red", em);
  //     em->entities.push_back(RedGhost);
  //   }
  //   else if (random == 1)
  //   {
  //     Ghost *OrangeGhost = new Ghost(x, y, width, height, sprite, "orange", em);
  //     em->entities.push_back(OrangeGhost);
  //   }
  //   else if (random == 2)
  //   {
  //     Ghost *BlueGhost = new Ghost(x, y, width, height, sprite, "blue", em);
  //     em->entities.push_back(BlueGhost);
  //   }
  //   else if (random == 3)
  //   {
  //     Ghost *PinkGhost = new Ghost(x, y, width, height, sprite, "pink", em);
  //     em->entities.push_back(PinkGhost);
  //   }
  // }
}

void GhostSpawner:: render(){

}

void GhostSpawner:: keyPressed(int key){
if(key == 'g'){
  int random = ofRandom(4);
  if (random == 0)
  {
      Ghost *RedGhost = new Ghost(x, y, width, height, sprite, "red", em);
    em->entities.push_back(RedGhost);
  }
  else if (random == 1)
  {
     Ghost *OrangeGhost = new Ghost(x, y, width, height, sprite, "orange", em);
     em->entities.push_back(OrangeGhost);
  }
  else if (random == 2)
  {
      Ghost *BlueGhost = new Ghost(x, y, width, height, sprite, "blue", em);
     em->entities.push_back(BlueGhost);
  }
  else if (random == 3)
  {
    Ghost *PinkGhost = new Ghost(x,y, width, height, sprite, "pink", em);
     em->entities.push_back(PinkGhost);
  }
 }
}


#include "Ghost.h"

Ghost::Ghost(int x, int y, int width, int height, ofImage spriteSheet, string color): Entity(x, y, width, height){

    if (color == "pink")
        sprite.cropFrom(spriteSheet, 456, 81, 16, 16);
    else if (color == "blue")
        sprite.cropFrom(spriteSheet, 456, 96, 16, 16);
    else if (color == "orange")
        sprite.cropFrom(spriteSheet, 456, 113, 16, 16);
    else
        sprite.cropFrom(spriteSheet, 456, 64, 16, 16);
     
}

// Dark blue sprite.cropFrom(spriteSheet, 584, 64, 16,16);
// White ghosts sprite.cropFrom(spriteSheet, 617, 64, 16,16);
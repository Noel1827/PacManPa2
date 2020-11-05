#include "Ghost.h"


Ghost::Ghost(int x, int y, int width, int height, ofImage spriteSheet, string color, EntityManager *em) : Entity(x, y, width, height)
{
    eatGhost = em->geteatGhost();
    this->em = em;
    if (eatGhost == false)
    {
        if (color == "pink")
            sprite.cropFrom(spriteSheet, 456, 81, 16, 16);
        else if (color == "blue")
            sprite.cropFrom(spriteSheet, 456, 96, 16, 16);
        else if (color == "orange")
            sprite.cropFrom(spriteSheet, 456, 113, 16, 16);
        else
            sprite.cropFrom(spriteSheet, 456, 64, 16, 16);
    }
    else if (eatGhost == true)
    {
        if (white == true)
        {
            sprite.cropFrom(spriteSheet, 617, 64, 16, 16);
        }
        else
            sprite.cropFrom(spriteSheet, 584, 64, 16, 16);
    }
}

void Ghost::tick()
{
     canMove = true;
    checkCollisions();
   
    if (canMove)
    {
        if (Gfacing == GUP){
            y -= speed;
        }
        else if (Gfacing == GDOWN){
            y += speed;
        }
        else if (Gfacing == GLEFT){
            x -= speed;
        }
        else if (Gfacing == GRIGHT){
            x += speed;
        }
    }else{

        int random = ofRandom(4);
        if(random == 0){
            Gfacing = GUP;
        } else if(random == 1){
            Gfacing = GDOWN;
        }else if(random == 2){
            Gfacing = GLEFT;
        }else if(random == 3){
            Gfacing = GRIGHT;
        }
    }
    
    // if (eatGhost == true)
    // {
    //     flashing++;
    //     if (flashing == 30)
    //     {
    //         white = !white;
    //         flashing = 0;
    //     }
    // }
}

void Ghost::checkCollisions()
{
         
    for (Block* block : this->em->blocks)
    {
        switch (Gfacing)
        {
        case GUP:
            if (this->getBounds(x, y - speed).intersects(block->getBounds()))
            {
                canMove = false;
            }
            break;
        case GDOWN:
            if (this->getBounds(x, y + speed).intersects(block->getBounds()))
            {
                canMove = false;
            }
            break;
        case GLEFT:
            if (this->getBounds(x - speed, y).intersects(block->getBounds()))
            {
                canMove = false;
            }
            break;
        case GRIGHT:
            if (this->getBounds(x + speed, y).intersects(block->getBounds()))
            {
                canMove = false;
            }
            break;
        }
    }
    
}

// void Ghost::move()
// {
//     canMove = true;

//     if (canMove)
//     {
//         if (Gfacing == GUP){
//             y -= speed;
//         }
//         else if (Gfacing == GDOWN){
//             y += speed;
//         }
//         else if (Gfacing == GLEFT){
//             x -= speed;
//         }
//         else if (Gfacing == GRIGHT){
//             x += speed;
//         }
//     }else{

//         int random = ofRandom(4);
//         if(random == 0){
//             Gfacing = GUP;
//         } else if(random == 1){
//             Gfacing = GDOWN;
//         }else if(random == 2){
//             Gfacing = GLEFT;
//         }else if(random == 3){
//             Gfacing = GRIGHT;
//         }
//     }
    
// }



void Ghost::render(){
  Entity::render();
}


// Dark blue sprite.cropFrom(spriteSheet, 584, 64, 16,16);
// White ghosts sprite.cropFrom(spriteSheet, 617, 64, 16,16);

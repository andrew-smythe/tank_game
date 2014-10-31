#ifndef ENEMYTANK_H
#define ENEMYTANK_H

/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 29th, 2014
*
* File: EnemyTank.h
*
* Behaviour: Class definition for enemy tank objects. This class will
*            have a drawable component, derived from Drawable.
*
******************************************************************************/

#include "Drawable.h"

class EnemyTank : public Drawable
{
    protected:
        /* x and y inherited from drawable */
        float z;

    private:
        float xScale;
        float yScale;
        float zScale;
        float angle;

    public:
        EnemyTank(float x, float y, float size, float angle);
        
        // Rotate the tank x degrees to the left
        void rotate(float deg);
        
        // Move the tank forward in the direction it is facing
        void move();
        
        // Implement virtual render function from parent Drawable interface
        void render();
        
        float getX();
        float getY();
        float getAngle();
};

#endif

#ifndef SHELL_H
#define SHELL_H

/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 30th, 2014
*
* File: Shell.h
*
* Behaviour: Class definition for shell object. This class will
*            have a drawable component, derived from Drawable.
*
******************************************************************************/

#include "Drawable.h"

class Shell : public Drawable
{        
    private:
        float angle;
        
        // how long until shell will stop being drawn (ie. max range)
        int timeToLive;
        
        bool isPlayerShell;
        
    public:
        // Constructor -- defines origin and angle of direction
        Shell(float x, float y, float angle, bool p);
        
        // Iterate movement of the shell -- returns 0 when timeToLive == 0
        int iterate();
    
        /* draw a plane onto the screen */
        void render();
        
        float getX();
        float getY();
        
        bool isPlayer();
        
};

#endif

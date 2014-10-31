#ifndef PLANE_H
#define PLANE_H

/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 29th, 2014
*
* File: Plane.h
*
* Behaviour: Class definition for plane object. This class will
*            have a drawable component, derived from Drawable.
*
******************************************************************************/

#include "Drawable.h"

class Plane : public Drawable
{
    protected:
        /* x and y inherited from drawable */
        float z;
        
    private:
        float sizeX;
        float sizeY;
        
    public:
        // Constructor -- defines size of plane. Will always be an XZ
        // plane, at Y = 0.0f for OpenGL, positioned at 
        Plane(float x, float y);
    
        /* draw a plane onto the screen */
        void render();
        
};

#endif

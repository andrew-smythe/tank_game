#ifndef DRAWABLE_H
#define DRAWABLE_H

/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 29th, 2014
*
* File: Drawable.h
*
* Behaviour: Contains class definition for parent Drawable class --
*            game objects with drawable components will be derived
*            from this class.
*
******************************************************************************/

#define PI 3.1415926

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
using namespace std;

class Drawable
{
    protected:
        float x;
        float y;
        
    public:
        Drawable(float x, float y);
        virtual void render() = 0;

};

#endif

/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 29th, 2014
*
* File: Drawable.cpp
*
* Behaviour: Contains implementations for parent Drawable class method --
*            game objects with drawable components will be derived
*            from this class.
*
******************************************************************************/

#include "Drawable.h"

// Constructor method -- creates drawable object at given x,y coordinate
Drawable::Drawable(float x, float y)
{
    this->x = x;
    this->y = y;
}

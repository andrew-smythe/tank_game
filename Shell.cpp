/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 30th, 2014
*
* File: Shell.cpp
*
* Behaviour: Class implementation for shell object. This class will
*            have a drawable component, derived from Drawable.
*
******************************************************************************/

#include "Shell.h"

Shell::Shell(float x, float y, float angle, bool p) : Drawable( x, y )
{
    this->angle = angle;
    this->timeToLive = 45;
    this->isPlayerShell = p;
}

// Implement virtual drawable function
void Shell::render()
{
    glColor3f( 1.0f, 0.0f, 0.0f );
    
    // move to location
	glPushMatrix();
	glTranslatef( this->x, 75.0f, this->y );
    
    /* Rotate shell */
    glPushMatrix();
    glRotatef( ((float) (180*this->angle) / PI), 0.0f, 1.0f, 0.0f );
	
	glutWireSphere( 5.0f, 10, 10 );
	
	glPopMatrix();
	glPopMatrix();
}

int Shell::iterate()
{
    // Move shell forward
    this->x = this->x + 40.0f * cos(this->angle);
    this->y = this->y + 40.0f * sin(this->angle);

    // decrement lifespan, return value
    this->timeToLive--;
    return ( this->timeToLive );
}

float Shell::getX()
{
    return ( this->x );
}

float Shell::getY()
{
    return ( this->y );
}

bool Shell::isPlayer()
{
    return ( this->isPlayerShell );
}

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
* Behaviour: Class implementation for plane object. This class will
*            have a drawable component, derived from Drawable.
*
******************************************************************************/

#include "Plane.h"

Plane::Plane(float x, float y) : Drawable( 0.0f, 0.0f )
{
    this->sizeX = x;
    this->sizeY = y;
}

// Implement virtual drawable function
void Plane::render()
{
    int numXSegments = this->sizeX / 20.0f;
    int numYSegments = this->sizeY / 20.0f;
    
    glColor3f( 0.0f, 0.0f, 0.25f );
    
    for ( int i = 0; i < numXSegments; i++ ) 
    {
        glBegin( GL_LINES );
            glVertex3f( 0.0f, -0.5f, 20.0f*i );
            glVertex3f( this->sizeX, -0.5f, 20.0f*i );
        glEnd();
    }
    
    for ( int j = 0; j < numYSegments; j++ )
    {
        glBegin( GL_LINES );
            glVertex3f( 20.0f*j, -0.5f, 0.0f );
            glVertex3f( 20.0f*j, -0.5f, this->sizeY );
        glEnd();      
    }
    glFlush();
}

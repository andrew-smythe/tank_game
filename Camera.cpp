/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 29th, 2014
*
* File: PlayerCamera.cpp
*
* Behaviour: Implementation of class methods for PlayerCamera object.
*
******************************************************************************/

#include "Camera.h"

// Constructor method for PlayerCamera (instantiates all floating point numbers
// needed for gluPerspective and gluLookAt calls
PlayerCamera::PlayerCamera(float px, float py, float pz, float f, float a, 
                           float near, float far)
{
    this->angle = 0.0f;
    
    this->posX = px;
    this->posY = py;
    this->posZ = pz;
    
    this->atX = this->posX + 500.0f * cos( this->angle );
    this->atY = py;
    this->atZ = this->posZ + 500.0f * sin( this->angle );
    
    this->fovy = f;
    this->aspect = a;
    this->nearClip = near;
    this->farClip = far;
    
    
    // set initial key states
    this->keyState[LEFT_TREAD_UP] = 0;
    this->keyState[LEFT_TREAD_DOWN] = 0;
    this->keyState[RIGHT_TREAD_UP] = 0;
    this->keyState[RIGHT_TREAD_DOWN] = 0;
}

// Methods for camera movement
void PlayerCamera::moveLeftTread(int direction)
{
    if (direction == MOVE_FORWARD)
    {
        // rotate to the right
        this->angle += 0.01f;
        
        // move tank slightly forward
        this->posX = this->posX + 1.2f * cos( this->angle );
        this->posZ = this->posZ + 1.2f * sin( this->angle );
    }
    else if (direction == MOVE_BACKWARD)
    {
        // rotate to the left
        this->angle -= 0.01f;
        
        // move tank slightly backward
        this->posX = this->posX - 1.2f * cos( this->angle );
        this->posZ = this->posZ - 1.2f * sin( this->angle );
    }
        
    // Recalculate at vector
    this->atX = this->posX + 500.0f * cos( this->angle );
    this->atZ = this->posZ + 500.0f * sin( this->angle );
}

void PlayerCamera::moveRightTread(int direction)
{
    if (direction == MOVE_FORWARD)
    {
        // rotate to the left
        this->angle -= 0.01f;
        
        // move tank slightly forward
        this->posX = this->posX + 1.2f * cos( this->angle );
        this->posZ = this->posZ + 1.2f * sin( this->angle );
    
    }
    else if (direction == MOVE_BACKWARD)
    {
        // rotate to the right
        this->angle += 0.01f;
        
        // move tank slightly backward
        this->posX = this->posX - 1.2f * cos( this->angle );
        this->posZ = this->posZ - 1.2f * sin( this->angle );        
    }
        
    // Recalculate at vector
    this->atX = this->posX + 500.0f * cos( this->angle );
    this->atZ = this->posZ + 500.0f * sin( this->angle );

}


// Getter methods

float PlayerCamera::getPosX()
{
    return (this->posX);
}

float PlayerCamera::getPosY()
{
    return (this->posY);
}

float PlayerCamera::getPosZ()
{
    return (this->posZ);
}

float PlayerCamera::getAtX()
{
    return (this->atX);
}

float PlayerCamera::getAtY()
{
    return (this->atY);
}

float PlayerCamera::getAtZ()
{
    return (this->atZ);
}

float PlayerCamera::getFOV()
{
    return (this->fovy);
}

float PlayerCamera::getAspect()
{
    return (this->aspect);
}

float PlayerCamera::getNearClip()
{
    return (this->nearClip);
}

float PlayerCamera::getFarClip()
{
    return (this->farClip);
}

float PlayerCamera::getAngle()
{
    return (this->angle);
}

// Keyboard input functions
void PlayerCamera::setKey(int key)
{
    this->keyState[key] = 1;
}

void PlayerCamera::releaseKey(int key)
{
    this->keyState[key] = 0;
}

int PlayerCamera::getKeyState(int key)
{
    return ( this->keyState[key] );
}

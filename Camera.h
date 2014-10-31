#ifndef CAMERA_H
#define CAMERA_H

/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 29th, 2014
*
* File: Camera.h
*
* Behaviour: Class definition for PlayerCamera object.
*
******************************************************************************/

// defines for direction of movement
#define MOVE_FORWARD  1
#define MOVE_BACKWARD 2

// defines for input keys
#define LEFT_TREAD_UP 0
#define LEFT_TREAD_DOWN 1
#define RIGHT_TREAD_UP 2
#define RIGHT_TREAD_DOWN 3

#include <cmath>
using namespace std;

class PlayerCamera
{
    private:
        float posX;
        float posY;
        float posZ;
        
        float atX;
        float atY;
        float atZ;
        
        float fovy;
        float aspect;
        float nearClip;
        float farClip;
        
        float angle;
        
        int keyState[4];
        
    public:
        PlayerCamera(float px, float py, float pz, float f, float a, 
                     float near, float far);
        
        // apply changes in input state
        void setKey(int key);
        void releaseKey(int key);
        
        // get key input state
        int getKeyState(int key);
        
        // camera movements
        void moveLeftTread(int direction);
        void moveRightTread(int direction);
        
        // getter methods
        float getPosX();
        float getPosY();
        float getPosZ();
        
        float getAtX();
        float getAtY();
        float getAtZ();
        
        float getFOV();
        float getAspect();
        float getNearClip();
        float getFarClip();
        
        float getAngle();      
};

#endif

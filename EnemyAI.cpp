/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 29th, 2014
*
* File: Game.h
*
* Behaviour: Implementation of enemy AI class. Each instantiated object will 
*            hold a reference to a tank model object that it will control with 
*            an AI strategy.
*
******************************************************************************/

#include "EnemyAI.h"

// Constructor -- create a tank AI, attached to given tank model object
EnemyAI::EnemyAI(EnemyTank* tank, float worldX, float worldY, Game* g)
{
    this->tankModel = tank;
    this->currentAction = MOVING;
    this->rotating = 0;
    this->forceMove = 0;
    this->timeTillFire = 0;
    
    this->worldX = worldX;
    this->worldY = worldY;
    
    this->engine = g;
}

// Returns drawable component
Drawable* EnemyAI::getDrawable()
{
    return( this->tankModel );
}

// Calculate and perform next AI action
int EnemyAI::doAction(float playerX, float playerY)
{
    // seed random number timer
    srand( time( NULL ) );
    
    bool playerInSight = false;
    
    // Determine if we will change current action
    int change = rand() % 100 + 1;
    
    // if the tank is moving, check if it will rotate
    if (this->rotating == 0 && this->forceMove == 0)
    {
        if (currentAction > MOVING)
            currentAction = MOVING;
            
        // select a different action if below threshold
        if (change < CHANGE_ACTION)
        {
            this->currentAction = rand() % 2 + 1;
            this->rotating = ROTATING_TIME;
        }
        
        // Check if the tank is about to hit a wall
        float x = this->tankModel->getX();
        float y = this->tankModel->getY();
        
        if ( ((x + 150) > this->worldX) || ((x - 150) < 0.0f)
             || ((y + 150) > this->worldY) || ((y - 150) < 0.0f) )
        {
            // force a rotation
            this->forceMove = MOVING_TIME;
            this->currentAction = rand() % 2 + 1;
            this->rotating = 2*ROTATING_TIME;
        }
        
        
        // check if player is in sight
        float distance = sqrt( (x - playerX) * (x - playerX) +
                               (y - playerY) * (y - playerY) );
                               
                               
        if (distance < 800.0f)
        {
            // find angle to player
            float dx = x-playerX;
            float dy = y-playerY;
            
            float fangle = atan2(dy, dx) * 180 / PI;
            int angle = (int) fangle;
                        
            if (angle < 0)
                this->tankModel->rotate( 1.0f );
            if (angle > 0)
                this->tankModel->rotate( -1.0f );
                
            if ((angle%360) < 10 && (angle%360) > -10)
            {
                if (this->timeTillFire == 0)
                {
                    /*
                    // origin of shell
                    int origX = this->tankModel->getX() + 40.0f * cos( this->tankModel->getAngle() );
                    int origY = this->tankModel->getY() + 40.0f * sin( this->tankModel->getAngle() );
                    
                    // fire from origin (slightly in front of player
                    this->engine->fireShell( origX, origY, this->tankModel->getAngle(), false );*/
                    this->timeTillFire = 166;
                }
            } 
        }
    }
    else if (this->rotating == 0 && this->forceMove > 0)
    {
        // Force tank to move
        this->currentAction = MOVING;
        this->forceMove--;        
    }
    
    
    // apply current AI instruction
    if (currentAction == MOVING)
    {
        this->tankModel->move();
    }
    else if (currentAction == ROTATING_LEFT)
    {
        this->tankModel->rotate( 1.0f );
    }
    else if (currentAction == ROTATING_RIGHT)
    {
        this->tankModel->rotate( -1.0f );
    }
    
    if (this->rotating > 0)
    {
        this->rotating--;
    }
    if (this->timeTillFire > 0)
    {
        this->timeTillFire--;
    }
}

// Check if a shell has collided with the tank
bool EnemyAI::checkCollision(Shell* shell)
{
    float radius = 150.0f;
    
    float shellX = shell->getX();
    float shellY = shell->getY();
    
    float x = this->tankModel->getX();
    float y = this->tankModel->getY();
    
    float distance = sqrt( (x - shellX) * (x - shellX) +
                           (y - shellY) * (y - shellY) );
    if (distance < radius)
        return true;
        
    return false;
}

// Delete old tank model, and build new one
void EnemyAI::setNewModel(EnemyTank* newTank)
{
    delete this->tankModel;
    this->tankModel = newTank;
}

/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 29th, 2014
*
* File: Game.cpp
*
* Behaviour: Implementation of main game class. This class will control the 
*            state of the game, and keep track of each object. It will have
*            methods for rendering each object.
*
******************************************************************************/

#include "Game.h"

int Game::NUM_ENEMIES = 0;

// Constructor for game object -- initializes the game state
Game::Game(int max, float x, float y, PlayerCamera* cam)
{
    // player location
    this->cam = cam;
    
    // Maximum number of enemy tanks on screen
    this->maxEnemies = max;
    
    // Parameters for plane size
    this->worldX = x;
    this->worldY = y;
    
    // Initialize each drawable object and enemy AI
    this->tankAgents = new vector<EnemyAI*>();
    this->shellObjects = new vector<Shell*>();
    
    // add the game plane to the drawable objects list
    this->gamePlane = new Plane( this->worldX, this->worldY );
                                     
    // Holder variable for new tank objects
    EnemyAI* newTank;
    float xPos;
    float yPos;
    float direction;
    int neg;
                    
    srand(time(NULL));                 
    
    for (int i = 0; i < this->maxEnemies; i++) 
    {
        xPos = rand() % (int)(this->worldX - 500.0f) + 250.0f;
        yPos = rand() % (int)(this->worldY - 500.0f) + 250.0f;
        direction = rand() % 360;
                
        // Create a new tank object, and insert it into 
        // drawable and AI agent lists
        newTank = new EnemyAI( new EnemyTank( xPos, yPos, 100.0f, direction ), 
                               this->worldX, this->worldY, this );
        
        this->tankAgents->insert( this->tankAgents->end(), newTank );  
        
        NUM_ENEMIES++;
    }
    
    // at initial state
    this->playerCanFire = true;
    this->gameTicks = 0;
    this->spaceKeyActive = 0;
}

// Returns list (std::vector) of drawable objects in the current game state
vector<Drawable*>* Game::getDrawables()
{
    // create a list of drawable objects for the rendering engine
    vector<Drawable*>* drawObjects = new vector<Drawable*>();
    
    // add the plane to the drawable list
    drawObjects->insert( drawObjects->end(), this->gamePlane );
    
    // add each tank model to the drawable list
    for (int i = 0; i < this->tankAgents->size(); i++)
    {
        drawObjects->insert( drawObjects->end(), 
                             this->tankAgents->at(i)->getDrawable() );
    }
    
    // add each shell to the drawable list
    for (int i = 0; i < this->shellObjects->size(); i++)
    {
        drawObjects->insert( drawObjects->end(), this->shellObjects->at(i) );
    }
    
    return ( drawObjects );
}

// Create a new shell object and fire it
void Game::fireShell(float x, float y, float angle, bool p)
{
    // create new shell object, and add it to vector lists
    Shell* newShell = new Shell( x, y, angle, p );
    
    this->shellObjects->insert( this->shellObjects->end(), newShell );     
}

// Record player input for firing shells
void Game::setSpaceKey(int i)
{
    this->spaceKeyActive = i;
}

/*
    MAIN GAME LOOP -- callback function for glutTimerFunc in main routine.
*/
void Game::gameTick()
{
    // iterate each tank agent
    for (int i = 0; i < this->tankAgents->size(); i++)
    {
        this->tankAgents->at(i)->doAction(this->cam->getPosX(), 
                                          this->cam->getPosZ());
    }
    
    // move each shell
    int timeToLive = 0;
    bool removeShell = false;
    int removeTank = -1;
    for (int i = 0; i < this->shellObjects->size(); i++)
    {
        // current shell pointer
        Shell* currentShell = this->shellObjects->at(i);
        // iterate the shell's movement, and how long it has to live
        timeToLive = currentShell->iterate();
        
        // check if shell has collided with any tanks
        for (int j = 0; j < this->tankAgents->size(); j++)
        {
            if (currentShell->isPlayer())
            {
                if (this->tankAgents->at(j)->checkCollision(currentShell)) 
                {
                    removeTank = j;
                    removeShell = true;
                }
            }
        }
        
        // check if shell has ran out of life
        if (timeToLive == 0)
            removeShell = true;
            
        // check if we need to remove the shell
        if (removeShell)
        {
            // remove from list of shells;
            this->shellObjects->erase( this->shellObjects->begin()+i );
            delete currentShell;
        }
        
        // check if we need to remove tank
        if (removeTank >= 0)
        {
            // create new tank model
            float xPos = rand() % (int)(this->worldX - 500.0f) + 250.0f;
            float yPos = rand() % (int)(this->worldY - 500.0f) + 250.0f;
            float direction = rand() % 360;
            EnemyTank* newTank = new EnemyTank( xPos, yPos, 100.0f, direction);
            this->tankAgents->at(removeTank)->setNewModel(newTank);
        }
    }
    
    // Determine if player can fire shell
    if (this->timeTillFire == 0)
        this->playerCanFire = true;
    else
        this->timeTillFire--;
        
    // fire a shell if the user can
    if (playerCanFire && this->spaceKeyActive)
    {
        // origin of shell
        int origX = this->cam->getPosX() + 40.0f * cos( this->cam->getAngle() );
        int origY = this->cam->getPosZ() + 40.0f * sin( this->cam->getAngle() );
        
        // fire from origin (slightly in front of player
        this->fireShell( origX, origY, this->cam->getAngle(), true );
        this->playerCanFire = false;
        this->timeTillFire = 40;
    }  
    
    this->gameTicks++;
}

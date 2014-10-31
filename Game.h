#ifndef GAME_H
#define GAME_H

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
* Behaviour: Definition of main game class. This class will control the state
*            of the game, and keep track of each object.
*
******************************************************************************/

#include "Drawable.h"
#include "EnemyTank.h"
#include "EnemyAI.h"
#include "Plane.h"
#include "Shell.h"
#include "Camera.h"
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

class EnemyAI;

class Game
{
    private:      
        int maxEnemies;
        PlayerCamera* cam;
        vector<EnemyAI*>* tankAgents;
        vector<Shell*>* shellObjects;
        
        /* size of world */
        float worldX;
        float worldY;
        
        int spaceKeyActive;
        int gameTicks;
        
        bool playerCanFire;
        int timeTillFire;
        
        Plane* gamePlane;
        
    public:
        // number of enemies currently in game
        static int NUM_ENEMIES;
        
        // Constructor for game object -- initializes the game state
        Game(int max, float x, float y, PlayerCamera* cam);
    
        // Move game state forward -- callback function for glutTimerFunc in
        // main
        void gameTick();
        
        // Retrieve list of drawable objects for rendering
        vector<Drawable*>* getDrawables();
        
        // Create a new shell object and fire it
        void fireShell(float x, float y, float angle, bool p);
        
        // player fire shell
        void setSpaceKey(int i);
        
};

#endif

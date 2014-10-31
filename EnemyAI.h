#ifndef ENEMYAI_H
#define ENEMYAI_H

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
* Behaviour: Definition of enemy AI class. Each instantiated object will hold
*            a reference to a tank model object that it will control with an
*            AI strategy.
*
******************************************************************************/

// Possible AI actions
#define MOVING 0
#define ROTATING_LEFT 1
#define ROTATING_RIGHT 2
#define CHANGE_ACTION 14
#define ROTATING_TIME 90
#define MOVING_TIME 60

#include "Game.h"
#include "EnemyTank.h"
#include "Shell.h"
#include <ctime>
#include <iostream>
using namespace std;

class Game;

class EnemyAI
{
    private:
        EnemyTank* tankModel;
        
        // checks if player is in enemy's line of sight
        bool playerInSight();
        
        // current action being taken by tank AI
        int currentAction;
        int rotating;
        int forceMove;
        int timeTillFire;
        
        // fires tank's cannon
        void shoot();
        
        // world extreme coordinates
        float worldX;
        float worldY;
        
        // reference to game engine
        Game* engine;
        
        
    public:
        // Create a tank AI, attached to given tank model
        EnemyAI(EnemyTank* tank, float worldX, float worldY, Game* g);
        
        Drawable* getDrawable();
        
        // Execute next AI action
        int doAction(float x, float y);
        
        // Check if a shell object has collided with tank
        bool checkCollision(Shell* shell);
        
        // Reset tank model (ie. old one was destroyed)
        void setNewModel(EnemyTank* tank);
};

#endif

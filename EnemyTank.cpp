/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 29th, 2014
*
* File: EnemyTank.cpp
*
* Behaviour: Implementation of class methods for enemy tank objects. This
*            class will have a drawable component, derived from Drawable.
*
******************************************************************************/

#include "EnemyTank.h"

// Constructor method for EnemyTank
EnemyTank::EnemyTank(float x, float y, float size, float angle) : Drawable(x, size*0.4)
{
    // NOTE: game is played in two dimensions, ie. X and Y, as tanks will be
    // situated on the same plane (ie. no up and down) for the entire game.
    // OpenGL is in 3 dimensions, with a constant up-vector of 0, 1, 0 (in the
    // Y direction. So, z is given y value in drawing, as the game will refer
    // to only two axes, X and Y.
    
    this->y = size*0.4;
    this->z = y;
    
    this->xScale = size;
    this->yScale = size*0.8;
    this->zScale = size;
    this->angle = angle;
}


// Rotate the tank model x degrees to the left
void EnemyTank::rotate(float deg)
{
    this->angle += deg;
}


// Move the tank model by one unit forward in the direction it is facing
void EnemyTank::move()
{
    this->x = this->x + 3.0f*sin((float) (this->angle*PI / 180));
    this->z = this->z + 3.0f*cos((float) (this->angle*PI / 180));
}


// Implementation of virtual method render from Drawable class -- will render
// a tank to the screen using OpenGL transformations & primitives
void EnemyTank::render()
{
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	
	/*glColor3f( 1.0f, 1.0f, 1.0f );
	glPointSize( 5.0f );
	glBegin(GL_POINTS);
        glVertex3f( this->x, this->y, this->z );
        for (int i = 0; i < 36; i++) {
            glVertex3f( this->x + 150.0f * sin((float) (10*i*PI / 180)), this->y, this->z + 150.0f * cos((float) (10*i*PI / 180)) );
        }
    glEnd();*/
	
	glPushMatrix();
	glTranslatef( this->x, this->y, this->z );
	
	glColor3f( 0.0f, 1.0f, 0.0f );
	    
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        
        /* Rotate tank */
        glPushMatrix();
        glRotatef(this->angle, 0.0f, 1.0f, 0.0f);
        
        if ( i == 0 )
        {
            glScalef( this->xScale, this->yScale, this->zScale );
        }
        else if ( i == 1 )
        {
            glScalef( this->xScale, -1*this->yScale, this->zScale );
        }
        else if ( i == 2 )
        {
            glScalef( this->xScale*0.4, (float)(this->yScale/3)*2, this->zScale*0.4 );
            glTranslatef( 0.0f, 0.75f, -0.75f );
        }
            
        /* Draw top square */
        glBegin(GL_QUADS);
            glVertex3f( -1.0, 0.5f, -1.0f );
            glVertex3f( -1.0, 0.5f, 1.0f );
            glVertex3f( 1.0, 0.5f, 1.0f );
            glVertex3f( 1.0, 0.5f, -1.0f );
        glEnd();
        
        /* Draw front slanted square */
        glBegin(GL_QUADS);
            glVertex3f( -1.0, 0.5f, 1.0f );
            glVertex3f( 1.0, 0.5f, 1.0f );
            glVertex3f( 1.0, 0.0f, 1.5f );
            glVertex3f( -1.0, 0.0f, 1.5f );
        glEnd();
        
        /* Draw bottom square */
        glBegin(GL_QUADS);
            glVertex3f( 1.0, 0.0f, 1.5f );
            glVertex3f( -1.0, 0.0f, 1.5f );
            glVertex3f( -1.0, 0.0f, -1.0f );
            glVertex3f( 1.0, 0.0f, -1.0f );
        glEnd();
        
        /* Draw back square */
        glBegin(GL_QUADS);
            glVertex3f( -1.0, 0.0f, -1.0f );
            glVertex3f( 1.0, 0.0f, -1.0f );
            glVertex3f( 1.0, 0.5f, -1.0f );
            glVertex3f( -1.0, 0.5f, -1.0f );
        glEnd();
        
        glPopMatrix();
        glPopMatrix();
    }
    
    /* Draw turret */
    glPushMatrix();
    
    glPushMatrix();
    glRotatef(this->angle, 0.0f, 1.0f, 0.0f);
    glScalef( (float) this->xScale/6, (float) this->yScale/6, (float) this->zScale );
    glTranslatef( 0.0f, 4.0f, 0.60f );
    
    glutWireCube(1.0f);
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();
    
    glFlush();
}

// Getters for x, y location
float EnemyTank::getX()
{
    return ( this->x );
}

float EnemyTank::getY()
{
    return ( this->z );
}

float EnemyTank::getAngle()
{
    return ( ((float) (((int)this->angle%360)*PI) / 180) );
}

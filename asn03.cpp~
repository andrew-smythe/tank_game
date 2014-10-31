/******************************************************************************
*
* Title: CSCI 405 Assignment #3
*
* Author: Andrew Smythe
*
* Date: March 25th, 2014
*
* File: asn03.cpp
*
* Behaviour: Runs the main game loop for Assignment #3 Tank Game.
*
******************************************************************************/

// GLOBAL CONSTANTS
#define pi 3.14159

#include <math.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Camera.h"
#include "Game.h"
#include "Shell.h"
using namespace std;

// Main game object
Game* engine;

// Camera object (controlled by player input)
PlayerCamera* cam;

// Camera control by player input
void keyboardPress( unsigned char key, int x, int y )
{
    if ( key == 'a' || key == 'A' )
    {
        cam->setKey( LEFT_TREAD_UP );
    }
    
    if ( key == 'z' || key == 'Z' )
    {
        cam->setKey( LEFT_TREAD_DOWN );
    }
    
    if ( key == '\'')
    {
        cam->setKey( RIGHT_TREAD_UP );
    }
    
    if (key == '/')
    {
        cam->setKey( RIGHT_TREAD_DOWN );
    }
    if (key == 32) 
    {
        engine->setSpaceKey(1);
    }
}
void keyboardUp( unsigned char key, int x, int y )
{
    if ( key == 'a' || key == 'A' )
    {
        cam->releaseKey( LEFT_TREAD_UP );
    }
    
    if ( key == 'z' || key == 'Z' )
    {
        cam->releaseKey( LEFT_TREAD_DOWN );
    }
    
    if ( key == '\'')
    {
        cam->releaseKey( RIGHT_TREAD_UP );
    }
    
    if (key == '/')
    {
        cam->releaseKey( RIGHT_TREAD_DOWN );
    }
    
    if (key == 32)
    {
        engine->setSpaceKey(0);
    }
}

// Call for game state iteration, and reset timer
void timerCall(int t)
{
    engine->gameTick();
    glutTimerFunc( 33, timerCall, 0 );
}

// Draw crosshair to screen
void drawCrosshair(float x, float y, float z, float angle)
{
    float newX = x + 0.4f * cos(angle);
    float topY = y - 0.02f;
    float botY = y + 0.02f;
    
    float leftZ1 = (z + 0.01f) + (0.4f * sin(angle));
    float leftZ2 = (z + 0.02f) + 0.4f * sin(angle);
    float rightZ1 = (z - 0.01f) + 0.4f * sin(angle);
    float rightZ2 = (z - 0.02f) + 0.4f * sin(angle);
    
    glColor3f( 1.0f, 0.0f, 0.0f );
    glBegin( GL_LINE_STRIP );
        glVertex3f( newX, topY, leftZ1 );
        glVertex3f( newX, topY, leftZ2 );
        glVertex3f( newX, botY, leftZ2 );
        glVertex3f( newX, botY, leftZ1 );
    glEnd();
    
    glBegin( GL_LINE_STRIP );
        glVertex3f( newX, topY, rightZ1 );
        glVertex3f( newX, topY, rightZ2 );
        glVertex3f( newX, botY, rightZ2 );
        glVertex3f( newX, botY, rightZ1 );
    glEnd();
}

void renderScene(void) 
{
    glEnable (GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // Setup player perspective based on current player position
    gluPerspective(cam->getFOV(), cam->getAspect(), cam->getNearClip(),
                   cam->getFarClip() );
 
    glMatrixMode(GL_MODELVIEW);
    
    // Check for camera movement
    if ( cam->getKeyState( LEFT_TREAD_UP ) )
    {
        cam->moveLeftTread( MOVE_FORWARD );
    }
    if ( cam->getKeyState( LEFT_TREAD_DOWN ) )
    {
        cam->moveLeftTread( MOVE_BACKWARD );
    }
    if ( cam->getKeyState( RIGHT_TREAD_UP ) )
    {
        cam->moveRightTread( MOVE_FORWARD );
    }
    if ( cam->getKeyState( RIGHT_TREAD_DOWN ) )
    {
        cam->moveRightTread( MOVE_BACKWARD );
    }
    
    // Aim camera based on current player position
    glPushMatrix();
    gluLookAt( cam->getPosX(), cam->getPosY(), cam->getPosZ(),
               cam->getAtX(), cam->getAtY(), cam->getAtZ(),
               0.0f, 1.0f, 0.0f );
    
    // Pull drawable objects from game engine, and call their render functions
    vector<Drawable*>* drawList = engine->getDrawables();
    
	glViewport(0, 0, 512, 512);
	glPushMatrix();
    for (int i = 0; i < drawList->size(); i++)
    {
        // Render current drawable object
        drawList->at(i)->render();
    }
    glPopMatrix();
    
    //drawCrosshair( cam->getPosX(), cam->getPosY(), cam->getPosZ(), cam->getAngle() );
      
	glPopMatrix();  
	glPopMatrix();      
	
	
    /*glPushMatrix();
    gluLookAt( cam->getPosX(), cam->getPosY()-500, cam->getPosZ(),
               cam->getPosX(), cam->getAtY(), cam->getPosZ(),
               1.0f, 0.0f, 0.0f );
    
	glViewport(0, 0, 100, 100);
    
    glPushMatrix();
    for (int i = 0; i < drawList->size(); i++)
    {
        // Render current drawable object
        drawList->at(i)->render();
    }    
    glPopMatrix();  */
    
	glutSwapBuffers(); 

}
int main(int argc, char **argv) 
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA|GLUT_MULTISAMPLE);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(512,512);
    glutCreateWindow("CSCI 405 Assignment #3");

    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

    // initialize the game
    cam = new PlayerCamera( 200.0f, 90.0f, 200.0f, 60.0f, 1.0f, 0.1f, 1500.0f );
    engine = new Game( 3, 3000.0f, 3000.0f, cam );

    // Input callbacks
	glutKeyboardFunc(keyboardPress);
	glutKeyboardUpFunc(keyboardUp);
	
	// Main game loop
	glutTimerFunc( 33, timerCall, 0 );
	
    // GLUT main loop
    glutMainLoop();

    return(0);
}

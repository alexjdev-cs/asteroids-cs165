/******************************************************************************
 * File:
 *   flyingObject.cpp
 * Author:
 *   Alex Johnson
 * Description:
 *   The base class for all elements in the game that fly, e.g., bullets, the
 *   ship, and asteroids.
 *****************************************************************************/
#include "flyingObject.h"
#include "game.h"

/********************************************************************
 * Constructors
 ********************************************************************/
FlyingObject::FlyingObject(Point point)
{
  this->point = point;
}

FlyingObject::FlyingObject(Point, Velocity)
{
  this->point = point;
  this->velocity = velocity;
}

FlyingObject::FlyingObject(Point, Velocity, int angle)
{
  this->point = point;
  this->velocity = velocity;
  this->angle = angle;
}

/********************************************************************
 * rotateLeft()
 * Rotates the object by the amount passed in
 ********************************************************************/
void FlyingObject::rotateLeft(int amount)
{
  angle += amount;
  if (angle > COMPLETE_ROTATION)
    angle -= COMPLETE_ROTATION;
}

/********************************************************************
 * rotateRight()
 * Rotates the object by the amount passed in
 ********************************************************************/
void FlyingObject::rotateRight(int amount)
{
  angle -= amount;
  if (angle < COMPLETE_ROTATION)
    angle += COMPLETE_ROTATION;
}

/********************************************************************
 * kill()
 * Sets alive to false
 ********************************************************************/
void FlyingObject::kill()
{
  alive = false;
}

/********************************************************************
 * Virtual function
 * draw()
 ********************************************************************/
void FlyingObject::draw()
{
}

/********************************************************************
 * update()
 * Updates the object's position information
 ********************************************************************/
void FlyingObject::update()
{
  point.addX(velocity.getDx());
  point.addY(velocity.getDy());

  if (point.getX() < -(float)GAME_WIDTH)
    point.addX((float)GAME_WIDTH * 2.0f);

  if (point.getX() > (float)GAME_WIDTH)
    point.addX(-(float)GAME_WIDTH * 2.0f);

  if (point.getY() < -(float)GAME_HEIGHT)
    point.addY((float)GAME_HEIGHT * 2.0f);

  if (point.getY() > (float)GAME_HEIGHT)
    point.addY(-(float)GAME_HEIGHT * 2.0f);
}
